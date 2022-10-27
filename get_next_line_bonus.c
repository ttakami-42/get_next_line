/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:23:28 by ttakami           #+#    #+#             */
/*   Updated: 2022/08/09 00:10:02 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*gnl_split_save(char *save, char **line, size_t split_len)
{
	char	*result;

	if (*save)
		*line = ft_substr(save, 0, split_len + 1);
	if (!*line || !save[split_len])
	{
		free(save);
		return (NULL);
	}
	result = ft_strdup(save + split_len + 1);
	if (!result)
	{
		free(*line);
		*line = NULL;
	}
	free(save);
	return (result);
}

static char	*gnl_strjoin(char *s1, char *s2, size_t s2_size)
{
	size_t	s1_size;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	s1_size = ft_strlen(s1);
	result = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(result, s1, s1_size);
	free(s1);
	ft_memcpy(result + s1_size, s2, s2_size);
	*(result + s1_size + s2_size) = '\0';
	return (result);
}

static	char	*gnl_read_join(int fd, char *save, char *buf, size_t *i)
{
	ssize_t		read_len;

	read_len = 1;
	while (read_len != 0 && (save == NULL || save[*i] != '\n'))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[read_len] = '\0';
		save = gnl_strjoin(save, buf, (size_t)read_len);
		if (!save)
			break ;
		while (save[*i] != '\0' && save[*i] != '\n')
			(*i)++;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	char		*buf;
	size_t		split_len;

	if (0 > fd || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	split_len = 0;
	save[fd] = gnl_read_join(fd, save[fd], buf, &split_len);
	if (!save[fd])
		return (NULL);
	line = NULL;
	save[fd] = gnl_split_save(save[fd], &line, split_len);
	return (line);
}
