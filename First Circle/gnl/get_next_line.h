/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:44 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/22 17:41:45 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/*****************************/
/*		get_next_line.c		 */
/*****************************/

char	*get_next_line(int fd);
char	*start_get_line(int fd);
size_t	have_newline(char *str);
char	*trim_remains(char	*str, size_t len);

/*************************************/
/*		 get_next_line_utils.c		 */
/*************************************/

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif