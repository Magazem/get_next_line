/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:10:34 by ysuliman          #+#    #+#             */
/*   Updated: 2024/04/06 14:10:36 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_;
	const char	*src_;

	dest_ = (char *)dest;
	src_ = (const char *)src;
	if (src_ < dest_ && dest_ < src_ + n)
	{
		src_ += n;
		dest_ += n;
		while (n--)
		{
			*--dest_ = *--src_;
		}
	}
	else
	{
		while (n--)
		{
			*dest_++ = *src_++;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *str1)
{
	char	*str2;

	str2 = malloc(ft_strlen(str1) + 1);
	if (str2 == 0)
		return (NULL);
	ft_strcpy(str2, str1);
	return (str2);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
