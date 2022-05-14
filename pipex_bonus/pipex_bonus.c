/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:42:13 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:30:32 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_start_fork(int cmd, char **argv, int **fd, char **envp)
{
	int	i;
	int	status;
	int	*buf_pid;
	int	**pipes_fd;

	i = -1;
	pipes_fd = ft_pipes(cmd - 1);
	buf_pid = (int *)malloc(sizeof(int) * cmd);
	while (++i < cmd)
	{
		buf_pid[i] = fork();
		if (buf_pid[i] < 0)
			return (-1);
		else if (buf_pid[i] == 0)
		{
			dup_all(cmd - 1, i, fd, pipes_fd);
			ft_command_block(argv + 1, i, envp);
		}
		else if (buf_pid[i] > 0 && i != cmd - 1)
			close(pipes_fd[i][1]);
	}
	i = -1;
	while (++i < cmd)
		waitpid(buf_pid[i], &status, 0);
	return (free_all(buf_pid, pipes_fd, fd, cmd));
}

void	dup_all(int num_pipes, int index, int **fd, int **pipes_fd)
{
	ft_close_pipe_fds(pipes_fd, index, num_pipes);
	ft_dup_pipes(pipes_fd, index, num_pipes);
	if (index == 0)
		dup2(fd[0][0], 0);
	if (index == num_pipes)
		dup2(fd[1][0], 1);
}

int	**ft_pipes(int count_pipes)
{
	int	**fds;
	int	i;

	i = -1;
	fds = (int **)malloc(sizeof(int *) * count_pipes);
	while (++i < count_pipes)
		fds[i] = (int *)malloc(sizeof(int) * 2);
	i = -1;
	while (++i < count_pipes)
		pipe(fds[i]);
	return (fds);
}

void	ft_dup_pipes(int **pipes_fd, int index, int num_pipes)
{
	if (index == 0)
		dup2(pipes_fd[index][1], 1);
	else if (index == num_pipes)
		dup2(pipes_fd[index - 1][0], 0);
	else
	{
		dup2(pipes_fd[index - 1][0], 0);
		dup2(pipes_fd[index][1], 1);
	}
}

void	ft_close_pipe_fds(int **pipes_fd, int index, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (i == index)
			close(pipes_fd[i][0]);
		if (i == index - 1)
			close(pipes_fd[i][1]);
		if (i != index && i != index - 1)
		{
			close(pipes_fd[i][0]);
			close(pipes_fd[i][1]);
		}
		i++;
	}
}
