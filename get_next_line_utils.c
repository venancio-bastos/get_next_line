/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:33:37 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/21 14:22:27 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    size_t  total;
    char    *out;
    size_t  i;

    total = nmemb * size;
    if (nmemb != 0 && total / nmemb != size)
        return (NULL);

    out = malloc(total);
    if (!out)
        return (NULL);

    i = 0;
    while (i < total)
        out[i++] = 0;

    return (out);
}


char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*new_s;

	size_s = ft_strlen(s);
	new_s = ft_calloc(size_s + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	new_s[size_s] = '\0';
	while (size_s)
	{
		size_s--;
		new_s[size_s] = s[size_s];
	}
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*new_arr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_arr = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (s1[i] && i < s1_len)
	{
		new_arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && i < s1_len + s2_len)
	{
		new_arr[i + j] = s2[j];
		j++;
	}
	new_arr[i + j] = '\0';
	return (new_arr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	if (!str)
        return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}