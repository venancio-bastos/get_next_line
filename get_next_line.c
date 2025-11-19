/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:03:35 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/19 18:31:47 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	printf("fd: %d\n", fd);
	printf("stash: %s\n", stash);

	return ("Test");
}

char	*get_next_line(int fd)
{
	static char	*stash = "";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, stash);
	return (line);
}

int	main(void)
{
	int 	fd = open("text.txt", O_RDONLY);

	get_next_line(fd);
	return (0);
}