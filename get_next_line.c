/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:03:35 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/25 23:52:43 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_index(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(int fd, char *stash)
{
	char	*buf;
	char	*temp;
	int		bytes;

	bytes = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (newline_index(stash) == -1 && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(stash), NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(stash, buf);
			free(stash);
			stash = temp;
		}
	}
	free(buf);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*buf;
	int		i;
	int		j;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = newline_index(stash);
	if (i == -1)
		i = ft_strlen(stash) - 1;
	buf = ft_calloc(i + 2, sizeof(char));
	if (!buf)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		buf[j] = stash[j];
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

char	*update_stash(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = newline_index(stash);
	if (i == -1)
	{
		free(stash);
		return (NULL);
	}
	newstash = ft_calloc(ft_strlen(stash) - i, 1);
	if (!newstash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		newstash[j++] = stash[i++];
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	if (stash && !stash[0])
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int fd = open("text.txt", 0);
// 	char *stash = get_next_line(fd);
// 	while (stash)
// 	{
// 		printf("%s", stash);
// 		free(stash);
// 		stash = get_next_line(fd);
// 	}
// 	free(stash);
// 	return (0);
// }
