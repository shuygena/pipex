/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:18:13 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 08:21:41 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_daughter1(char **narg, char **envp, int *fd, int *files)
{
	char	**paths;
	int		i;
	char	*cmd;

	i = 0;
	close(files[1]);
	close(fd[0]);
	dup2(files[0], 0);
	dup2(fd[1], 1);
	paths = split_path(envp);
	if (narg[0][0] == '/' || narg[0][0] == '.')
		return (ft_just_do_it(narg, envp));
	cmd = ft_strcat(paths[i], narg[0]);
	while (paths[i] && execve(cmd, narg, envp) == -1)
	{
		free(cmd);
		i++;
		cmd = ft_strcat(paths[i], narg[0]);
	}
	free(narg);
	return (ft_error(4, narg[0], NULL));
}

int	ft_just_do_it(char **narg, char **envp)
{
	execve(narg[0], narg, envp);
	free(narg);
	return (ft_error(4, narg[0], NULL));
}

void	ft_parent(char **narg, char **envp, int *fd, int *files)
{
	char	**paths;
	int		i;
	char	*cmd;

	i = 0;
	wait(0);
	close(files[0]);
	close(fd[1]);
	dup2(files[1], 1);
	dup2(fd[0], 0);
	paths = split_path(envp);
	if (narg[0][0] == '/' || narg[0][0] == '.')
		ft_just_do_it(narg, envp);
	cmd = ft_strcat(paths[i], narg[0]);
	while (paths[i] && execve(cmd, narg, envp) == -1)
	{
		free(cmd);
		i++;
		cmd = ft_strcat(paths[i], narg[0]);
	}
	ft_error(4, narg[0], NULL);
	if (!(narg[0][0] == '/' || narg[0][0] == '.'))
		free(narg);
}
