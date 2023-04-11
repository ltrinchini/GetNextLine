/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:48:26 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/04/05 11:42:20 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_substr(char *str, size_t start, size_t len)
{
	char *dst;
	size_t i;

	i = 0;
	if (!str || start < 0)
		return (NULL);
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i + start];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static char *ft_strcdup(char *str, char c)
{
	size_t i;
	size_t size;
	char *dst;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str);
	dst = malloc(sizeof(char) * size + 1);
	if (!dst)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			dst[i] = str[i];
			i++;
			break;
		}
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char *ft_get_line(char **str)
{
	char *next;
	char *line;
	char *ptr;

	if (ft_strlen(*str) == 0)
	{
		free(*str);
		return (NULL);
	}
	line = ft_strcdup(*str, '\n');
	next = ft_strchr(*str, '\n');
	ptr = *str;
	*str = ft_substr(*str, next - *str + 1, ft_strlen(next));
	if (!line || !*str)
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);
	return (line);
}
