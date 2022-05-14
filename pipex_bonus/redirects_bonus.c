/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:23:17 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:35:11 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	redirect_manipulate(char **argv, int argc, int **fd)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		fd[1][0] = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
		if (fd[1][0] == -1)
			return (0);
		pipe(fd[0]);
		ft_redirect2(argv[3], fd[0]);
	}
	else
	{
		fd[0][0] = open(argv[1], O_RDONLY);
		if (fd[0][0] == -1)
			return (ft_error(2, strerror(errno), argv[1]));
		fd[1][0] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd[1][0] == -1)
			return (0);
	}
	return (1);
}

void	ft_redirect2(char *key, int *fd1)
{
	int		cmp;
	char	*line;

	cmp = ft_strlen(key) + 1;
	write(1, "> ", 2);
	get_next_line(0, &line);
	while (ft_strncmp(line, key, cmp) != 0)
	{
		write(fd1[1], line, ft_strlen(line));
		write(fd1[1], "\n", 1);
		free(line);
		write(1, "> ", 3);
		get_next_line(0, &line);
	}
	free(line);
	close (fd1[1]);
}

int	free_all(int *buf_pid, int **pipes_fd, int **fd, int cmd)
{
	int	i;

	i = -1;
	while (++i < cmd - 1)
	{
		close(pipes_fd[i][0]);
		free(pipes_fd[i]);
	}
	free(pipes_fd);
	free(buf_pid);
	free(fd[0]);
	free(fd[1]);
	return (1);
}
