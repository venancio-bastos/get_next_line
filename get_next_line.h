/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:34:01 by vebastos          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:05 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_h
#define GET_NEXT_LINE_h

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h> 
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

#endif