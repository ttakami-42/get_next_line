/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:02:57 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/08 22:59:05 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  include <stdio.h>
#  define OPEN_MAX FOPEN_MAX
# endif

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif