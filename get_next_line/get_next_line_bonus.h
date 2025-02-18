/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:08:04 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 14:57:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_and_append(int fd, char *st_buffer, char *buffer);
char	*ft_copy_until_new_line(char *st_buffer, char *line);
char	*ft_copy_after_newline(char *st_buffer);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
int		ft_strchr_gnl(const char *s, int c);

#endif