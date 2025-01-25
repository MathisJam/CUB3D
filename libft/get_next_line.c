/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:58:21 by jchen             #+#    #+#             */
/*   Updated: 2025/01/25 14:15:44 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name get_next_line
   Prototype char *get_next_line(int fd);
   Fichiers de rendu get_next_line.h, get_next_line.c,
   get_next_line_utils.c
   Paramètres fd : le descripteur de fichier depuis lequel lire
   Valeur de retour Le contenu de la ligne lue : comportement correct
NULL : rien d’autre à lire ou une erreur s’est
produite
Fonctions externes autorisées
read, malloc, free
Description Écrire une fonction qui retourne une ligne lue
depuis un descripteur de fichier
 */

#include "libft.h"

void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_get_line(char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = (char *) malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (buffer[i - 1] == '\n')
		tmp[i - 1] = '\n';
	tmp[i] = 0;
	while (--i >= 0)
		tmp[i] = buffer[i];
	return (tmp);
}

char	*ft_get_next(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer || !buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *) malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[++i])
		tmp[j++] = buffer[i];
	tmp[j] = 0;
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	int		bytes_read;

	if (!buffer)
	{
		buffer = (char *) malloc(1);
		buffer[0] = 0;
	}
	reading = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reading)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, reading, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(buffer, reading);
			return (NULL);
		}
		reading[bytes_read] = 0;
		buffer = ft_strjoin_free(buffer, reading);
	}
	free(reading);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next(buffer);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
int fd;
char *line;

if (ac < 2)
fd = 0;
else
fd = open(av[1], O_RDONLY);
line = get_next_line(fd);
while (line)
{
ft_printf("%s", line);
line = get_next_line(fd);
}
return (0);
}

 */
// #include "libft.h"

// static char	*buf[4096];

// void	gnl_clear_all_buffers(void)
// {
// 	int	i;

// 	// Parcourt tous les descripteurs potentiels (0 à 4095)
// 	for (i = 0; i < 4096; i++)
// 	{
// 		if (buf[i]) // Si un buffer existe, libère sa mémoire
// 		{
// 			free(buf[i]);
// 			buf[i] = NULL; // Réinitialise le pointeur à NULL
// 		}
// 	}
// }

// char	*get_next_line(int fd)
// {
// 	char	*line;
// 	size_t	old_len;

// 	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	line = NULL;
// 	if (gnl_strchr_i(buf[fd], '\n') == -1)
// 	{
// 		old_len = gnl_strlen(buf[fd]);
// 		buf[fd] = gnl_expand_buffer(buf[fd], fd);
// 		if (old_len == gnl_strlen(buf[fd]) && buf[fd])
// 			line = gnl_substr(buf[fd], 0, gnl_strlen(buf[fd]));
// 	}
// 	if (!buf[fd])
// 		return (NULL);
// 	if (!line && gnl_strchr_i(buf[fd], '\n') != -1)
// 		line = gnl_substr(buf[fd], 0, gnl_strchr_i(buf[fd], '\n') + 1);
// 	if (line)
// 	{
// 		buf[fd] = gnl_shrink_buffer(buf[fd], line);
// 		return (line);
// 	}
// 	return (get_next_line(fd));
// }

// char	*gnl_shrink_buffer(char *buf, char *line)
// {
// 	char	*newbuf;
// 	int		line_len;

// 	if (!buf || !line)
// 		return (buf);
// 	line_len = gnl_strlen(line);
// 	if ((int)gnl_strlen(buf) == line_len)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}
// 	newbuf = gnl_substr(buf, line_len, gnl_strlen(buf) - line_len);
// 	free(buf);
// 	return (newbuf);
// }

// char	*gnl_expand_buffer(char *buf, int fd)
// {
// 	char	*newbuf;
// 	int		newlen;
// 	char	*aux;

// 	aux = gnl_newread(fd);
// 	if (!aux)
// 		return (NULL);
// 	if (!aux[0])
// 	{
// 		free(aux);
// 		return (buf);
// 	}
// 	if (!buf)
// 		return (aux);
// 	newlen = gnl_strlen(buf) + gnl_strlen(aux);
// 	newbuf = malloc(newlen + 1);
// 	if (!newbuf)
// 		return (NULL);
// 	gnl_strlcpy(newbuf, buf, newlen + 1);
// 	gnl_strlcat(newbuf, aux, newlen + 1);
// 	free(buf);
// 	free(aux);
// 	return (newbuf);
// }

// char	*gnl_newread(int fd)
// {
// 	int		nbytes;
// 	char	*aux;

// 	aux = malloc(BUFFER_SIZE + 1);
// 	if (!aux)
// 		return (NULL);
// 	nbytes = read(fd, aux, BUFFER_SIZE);
// 	if (nbytes < 0)
// 	{
// 		free(aux);
// 		return (NULL);
// 	}
// 	aux[nbytes] = '\0';
// 	return (aux);
// }
