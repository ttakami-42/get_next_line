/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:49:13 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/06 01:05:10 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (const char)c)
			return ((char *)str);
		str++;
	}
	if ((const char)c == '\0')
		return ((char *)str);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;

	ptr = dst;
	if (dst == src)
		return (dst);
	while (len-- > 0)
		*ptr++ = *(unsigned char *)src++;
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (size <= start)
		size = 0;
	else
	{
		size = size - start;
		if (size > len)
			size = len;
	}
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, str + start, size);
	*(result + size) = '\0';
	return (result);
}
