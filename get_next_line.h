/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:59:54 by akarafi           #+#    #+#             */
/*   Updated: 2021/11/13 02:06:43 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		add_buff_to_full(char *buffer, char *full);
int		ft_char_in_str(char *s, char c);
int		ft_strlen(char *s);
void	ft_strlcpy(char *dest, char *src, int size);
void	ft_strlcat(char *dst, char *src, int dstsize);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	*line_from_full(char *full);

#endif