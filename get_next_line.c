/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:59:59 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/13 03:06:02 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*full;
	char			*buffer;
	char			*dup;
	int				n_bytes_or_bool;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n_bytes_or_bool = read(fd, buffer, BUFFER_SIZE);
	if (!n_bytes_or_bool)
	{
		free(buffer);
		return (NULL);
	}
	buffer[n_bytes_or_bool] = '\0';
	n_bytes_or_bool = add_buff_to_full(buffer, full);
	if (n_bytes_or_bool)
	{
		dup = ft_strdup(full);
		free(full);
		full = NULL;
		return (dup);
	}
	return (get_next_line(fd));
}

int	add_buff_to_full(char *buffer, char *full)
{
	char	*tmp;
	int		ret;

	ret = ft_char_in_str(buffer, '\n');
	if (ret != -1)
	{
		tmp = malloc(ft_strlen(full) + ret + 2);
		ft_strlcpy(tmp, full, ft_strlen(full) + 1);
		ft_strlcat(tmp, buffer, ft_strlen(full) + ret + 2);
		free(full);
		full = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}
