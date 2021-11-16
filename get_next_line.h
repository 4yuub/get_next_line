/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:59:54 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/16 16:46:16 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*add_buffer_to_full(char *buffer, char *full);
int		ft_strlen(char *s);
void	ft_strcat(char *dst, char *src);
char	*ft_strdup( char *s1);
char	*trim(char *full);
char	*get_line(char *full);
int		line_in_full(char *full);
char	*get_line_or_null(int fd);
char	*return_line_or_null(char *full);

#endif