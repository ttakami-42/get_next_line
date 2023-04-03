/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:02:57 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/08 22:58:19 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif