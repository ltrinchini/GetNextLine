/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:47:43 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/04/11 10:02:37 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_error(char *str, char **ptr, int i)
{
	if (!str)
	{
		if (*ptr)
			free(*ptr);
		return (EXIT_FAILURE);
	}
	if (i < 0)
	{
		if (*ptr)
			free(*ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char *ft_strjoin(char *s1, char *s2)
{
	size_t size_s1;
	size_t size_s2;
	size_t size;
	size_t i;
	char *dst;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	i = 0;
	dst = malloc(sizeof(char) * size + 1);
	if (!dst)
		return (NULL);
	while (i < size_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < size_s1 + size_s2)
	{
		dst[i] = s2[i - size_s1];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char *ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == 0)
		return (&str[i]);
	return (NULL);
}

char *get_next_line(int fd)
{
	static char *str;
	char *ptr;
	char buff[BUFFER_SIZE + 1];
	int i;

	i = read(fd, buff, BUFFER_SIZE);
	if (i < 0 || (i == 0 && !str))
		return (NULL);
	while (i > 0)
	{
		buff[i] = 0;
		ptr = str;
		str = ft_strjoin(str, buff);
		if (ft_error(str, &ptr, i))
			return (NULL);
		if (ptr)
			free(ptr);
		if (ft_strchr(str, '\n'))
			return (ft_get_line(&str));
		i = read(fd, buff, BUFFER_SIZE);
		if (ft_error(str, &ptr, i))
			return (NULL);
	}
	return (ft_get_line(&str));
}
