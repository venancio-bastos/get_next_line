/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:34:01 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/24 15:10:26 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_BONUS_h
#define GET_NEXT_LINE_BONUS_h

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h> 
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*read_line(int fd, char *stash);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int  	newline_index(char *s);
int	    found_newline(char *s, int c);
size_t	ft_strlen(const char *str);

#endif