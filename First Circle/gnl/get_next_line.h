/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:44 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/24 16:35:12 by megadiou         ###   ########.fr       */
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
char	*read_file(int fd, char *stock);
char	*get_line(char *stock);
int		have_newline(char *stock);
char	*trim_stock(char *stock, int start);

/*************************************/
/*		 get_next_line_utils.c		 */
/*************************************/

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_malloc_n_cat(const char *s1, const char *s2, int len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif