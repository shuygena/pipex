/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:40:52 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:28:03 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 88
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

void	*ft_calloc(size_t number, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_error(int flag, char *text, char *t2);
char	**split_path(char **envp);
int		redirect_manipulate(char **argv, int argc, int **fd);
void	ft_redirect2(char *key, int *fd1);
int		ft_start_fork(int cmd, char **argv, int **fd, char **envp);
void	dup_all(int num_pipes, int index, int **fd, int **pipes_fd);
int		**ft_pipes(int count_pipes);
void	ft_dup_pipes(int **pipes_fd, int index, int num_pipes);
void	ft_close_pipe_fds(int **pipes_fd, int index, int num_pipes);
int		ft_count_cmd(char **argv, int argc);
void	ft_command_block(char **argv, int i, char **envp);
int		ft_daughter(char **narg, char **envp);
int		free_all(int *buf_pid, int **pipes_fd, int **fd, int cmd);
char	*ft_dup(const char *str);
int		ft_nsymbol(char *str);
char	*ft_strjon(char *s1, char *s2);
int		ft_zero(char *buffer, int i);
int		ft_result(int status);
int		ft_check_remain(char ***line, char **remain);
int		get_next_line(int fd, char **line);

#endif
