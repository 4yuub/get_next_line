/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:59:59 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/14 09:40:58 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*full;
	char		*buffer;
	char		*line;
	int			n;

	if (line_in_full(full))
	{
		line = get_line(full);
		full = trim(full); // leak
		if (!full)
			return (NULL);
		return (line);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[n] = '\0';
	full = add_buffer_to_full(buffer, full); // leak
	if (!full)
		return (NULL);
	return (get_next_line(fd));
}

char	*add_buffer_to_full(char *buffer, char *full)
{
	char	*tmp;

	if (!full)
		full = ft_strdup("");
	tmp = ft_strdup(full);
	free(full);
	full = malloc(ft_strlen(tmp) + ft_strlen(buffer) + 1);
	if (!full)
	{
		free(tmp);
		free(buffer);
		return (0);
	}
	*full = 0;
	ft_strcat(full, tmp);
	ft_strcat(full, buffer);
	free(tmp);
	free(buffer);
	return (full);
}

char	*trim(char *full)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!full)
		return (NULL);
	while (full[i] && full[i] != '\n')
		i++;
	tmp = ft_strdup(full + i + 1);
	if (!tmp)
		return (NULL);
	free(full);
	full = tmp;
	return (full);
}

char	*get_line(char *full)
{
	char	*line;
	int		i;

	i = 0;
	if (!full)
		return (NULL);
	while (full[i] && full[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (full[i] && full[i] != '\n')
	{
		line[i] = full[i];
		i++;
	}
	line[i] = full[i];
	line[++i] = '\0';
	return (line);
}
