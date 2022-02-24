/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:41:29 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/21 15:52:12 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <limits.h>

/* Variables for the pipes */
# define READ_END	0
# define WRITE_END	1

/*Mandatory part*/
void		arg_error(char *cmd);
void		error_cmd(char *file);
void		error_file(int fd, char *file);
int			open_file(char *argv, int i);
char		*find_path(char *cmd, char **envp);
int			execute(char *argv, char **envp);

/*bonus_part*/
char		*get_next_line(int fd);

/*libft_functions*/
int			ft_strncmp(const char	*str1, const char	*str2, unsigned	int n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_count(const char *str, char c);
char		**ft_split2(char const *s, char c, int len, char **split);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putstr_fd(char *str, int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
void		optimize(int pid, int p[2]);
void		join_free(char **buff, char **line);
void		mini_optimize(int argc, int p[2]);
void		write_get(char **line);

#endif
