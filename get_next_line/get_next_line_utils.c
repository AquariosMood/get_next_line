/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:56:57 by crios             #+#    #+#             */
/*   Updated: 2024/06/17 16:21:53 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	const char	*src;
	char		*str;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	src = s1;
	while (*src)
		*str++ = *src++;
	src = s2;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - (len1 + len2));
}

char	*find_newline(char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

int	initialize_buffer(int fd, char **buffer, char **temp)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!*buffer)
	{
		*buffer = (char *)malloc(1);
		if (!*buffer)
			return (-1);
		(*buffer)[0] = '\0';
	}
	*temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!*temp)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	return (0);
}

int	append_to_buffer(int fd, char **buffer, char *temp)
{
	ssize_t	bytes_read;
	char	*new_buffer;

	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(temp);
		return (-1);
	}
	if (bytes_read == 0)
	{
		free(temp);
		return (0);
	}
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	free(*buffer);
	*buffer = new_buffer;
	if (!new_buffer)
	{
		free(temp);
		return (-1);
	}
	return (1);
}
