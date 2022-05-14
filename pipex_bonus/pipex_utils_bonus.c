/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 04:42:29 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:55:03 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error(int flag, char *text, char *t2)
{
	if (flag == 1)
		write(2, "pipex: bad count arguments\n", 27);
	if (flag == 2)
	{
		write(2, "pipex: ", 7);
		write(2, t2, ft_strlen(t2));
		write(2, ": ", 2);
		write(2, text, ft_strlen(text));
		write(2, "\n", 1);
	}
	if (flag == 3)
		write(2, "pipex: unexpected error\n", 24);
	if (flag == 4)
	{
		write(2, "pipex: ", 7);
		write(2, text, ft_strlen(text));
		write(2, ": command not found\n", 20);
	}
	return (0);
}

char	**split_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

int	ft_count_cmd(char **argv, int argc)
{
	int	cmd;

	cmd = argc - 3 - !(ft_strncmp(argv[1], "here_doc", 9));
	return (cmd);
}

void	ft_command_block(char **argv, int i, char **envp)
{
	if (!ft_strncmp(argv[0], "here_doc", 9) && i > 0)
		argv++;
	argv++;
	ft_daughter(ft_split(argv[i], ' '), envp);
	exit(1);
}

int	ft_daughter(char **narg, char **envp)
{
	char	**paths;
	int		i;
	char	*cmd;

	i = 0;
	paths = split_path(envp);
	if (narg[0][0] == '/' || narg[0][0] == '.')
	{
		execve(narg[0], narg, envp);
		return (ft_error(4, narg[0], NULL));
	}
	cmd = ft_strcat(paths[i], narg[0]);
	while (paths[i] && execve(cmd, narg, envp) == -1)
	{
		free(cmd);
		i++;
		cmd = ft_strcat(paths[i], narg[0]);
	}
	return (ft_error(4, narg[0], NULL));
}
