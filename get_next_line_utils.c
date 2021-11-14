/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:00:01 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/14 09:13:25 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s1)
{
	int		l;
	int		i;
	char	*s2;

	l = ft_strlen(s1);
	s2 = (char *) malloc(l + 1);
	if (!s2)
		return (s2);
	i = 0;
	while (s1[i])
	{	
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
}

int	line_in_full(char *full)
{
	if (!full)
		return (0);
	while (*full)
	{
		if (*full == '\n')
			return (1);
		full++;
	}
	return (0);
}
