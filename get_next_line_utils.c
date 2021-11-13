/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:00:01 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/13 01:40:38 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_char_in_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{	
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

void	ft_strlcat(char *dst, char *src, int dstsize)
{
	int		i;
	int		j;

	i = ft_strlen(dst);
	if (dstsize - 1 < i || dstsize == 0)
		return ;
	j = 0;
	while (i < dstsize - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
}

char	*ft_strdup(char *s1)
{
	int		l;
	char	*s2;

	l = ft_strlen(s1);
	s2 = (char *) malloc(l + 1);
	if (!s2)
		return (s2);
	ft_strlcpy(s2, (char *) s1, l + 1);
	return (s2);
}
