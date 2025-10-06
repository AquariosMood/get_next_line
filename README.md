# get_next_line - 42 School Project

## 📋 Description
get_next_line est un projet du tronc commun à 42 qui consiste à développer une fonction permettant de lire une ligne complète depuis un descripteur de fichier. Ce projet aborde les concepts de lecture bufferisée et de gestion de mémoire persistante entre les appels de fonction.

## 🎯 Objectifs
- Comprendre le système de fichiers et les descripteurs sous UNIX
- Maîtriser la lecture bufferisée pour optimiser les performances
- Gérer la mémoire de manière efficace entre plusieurs appels
- Implémenter une logique de gestion d'état persistante

## 🛠️ Fonctions Implémentées

### 🔤 Fonction Principale
**get_next_line** - Lit et retourne une ligne complète depuis un descripteur de fichier

### ⚙️ Fonctions Auxiliaires
**Gestion de la mémoire** :
- read_buffer - Effectue la lecture depuis le descripteur
- extract_line - Extrait une ligne complète du buffer
- clean_buffer - Nettoie le buffer après extraction
- add_to_stash - Ajoute les données lues au stock temporaire

**Utilitaires** :
- ft_strlen - Calcul de la longueur des chaînes
- ft_strchr - Recherche de caractère dans une chaîne
- ft_strjoin - Concatenation de chaînes avec gestion mémoire

## 🚀 Installation et Utilisation
```bash
git clone [URL-du-repository]
cd get_next_line
make
c
#include "get_next_line.h"
// Compiler avec : -L. -lgnl
📊 Compilation
Le Makefile supporte les règles suivantes :

make - Compile la bibliothèque

make clean - Supprime les fichiers objets

make fclean - Supprime les fichiers objets et la bibliothèque

make re - Recompile entièrement le projet
```

💡 Fonctionnalités
Lecture depuis multiples descripteurs de fichiers simultanément

Gestion de la mémoire sans fuites

Gestion des fichiers de très grande taille

Support des lectures standard et avec buffer personnalisé

Gestion robuste des cas d'erreur et de fin de fichier

🎯 Cas d'Usage
c
int fd = open("fichier.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
💡 Compétences Développées
Programmation système avec les descripteurs de fichier

Gestion de mémoire dynamique avancée

Algorithmie de parsing et de bufferisation

Gestion d'état persistant entre appels de fonction

Optimisation des performances en E/S

Débogage de programmes complexes

Ce projet est essentiel pour comprendre les mécanismes bas niveau de lecture de fichiers et sert de fondation pour des projets impliquant le traitement séquentiel de données.
