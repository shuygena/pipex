/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:18:33 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:18:36 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

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
int		ft_daughter1(char **narg, char **envp, int *fd, int *files);
char	**split_path(char **envp);
void	open_and_pipe(int *files, int *fd, char **argv);
void	ft_parent(char **narg, char **envp, int *fd, int *files);
int		ft_just_do_it(char **narg, char **envp);

#endif
