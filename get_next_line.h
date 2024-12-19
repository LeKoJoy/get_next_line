/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrii <andrii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:32:08 by andrii            #+#    #+#             */
/*   Updated: 2024/12/19 21:40:38 by andrii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t     ft_strlen(const char *str);
char    *ft_strchr(const char *s, int i);
char    *ft_strdup(const char *s);

#endif