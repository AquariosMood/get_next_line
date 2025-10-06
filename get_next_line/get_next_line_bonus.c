/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:56:04 by crios             #+#    #+#             */
/*   Updated: 2024/06/17 15:58:58 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*process_line_core(char *line)
{
	int		i;
	char	*temp_line;

	i = 0;
	while (line[i])
		i++;
	temp_line = NULL;
	if (line && line[0] != '\0' && line[i - 1] == '\n')
		return (line);
	else
	{
		temp_line = ft_strjoin(line, "\n");
		free(line);
		return (temp_line);
	}
}

char	*process_line(char **buffer, char *newline, char *temp)
{
	char	*line;
	char	*remaining;

	line = NULL;
	remaining = NULL;
	if (newline)
	{
		*newline = '\0';
		line = ft_strdup(*buffer);
		if (line)
		{
			remaining = ft_strdup(newline + 1);
			free(*buffer);
			*buffer = remaining;
		}
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	free(temp);
	return (process_line_core(line));
}

int	read_and_update_buffer(int fd, char **buffer, char *temp)
{
	char	*newline;
	int		append_result;

	newline = find_newline(*buffer);
	while (!newline)
	{
		append_result = append_to_buffer(fd, buffer, temp);
		if (append_result != 1)
			return (append_result);
		newline = find_newline(*buffer);
	}
	return (1);
}

char	*handle_buffer_result(char **buffer, char *temp)
{
	char	*line;

	if (!temp)
		return (NULL);
	line = NULL;
	if (*buffer && **buffer)
	{
		line = ft_strdup(*buffer);
		if (line)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	else if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			result;
	static char	*backup[1024];

	temp = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0
		|| initialize_buffer(fd, &backup[fd], &temp) != 0)
	{
		free(temp);
		return (NULL);
	}
	result = read_and_update_buffer(fd, &backup[fd], temp);
	if (result == -1)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	if (result == 0)
		return (handle_buffer_result(&backup[fd], temp));
	return (process_line(&backup[fd], find_newline(backup[fd]), temp));
}
