/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:18:55 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:47:29 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	open_and_pipe(int *files, int *fd, char **argv)
{
	pipe(fd);
	files[0] = open(argv[1], O_RDONLY);
	if (files[0] == -1)
		ft_error(2, strerror(errno), argv[1]);
	files[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (files[1] == -1)
		ft_error(2, strerror(errno), argv[4]);
}
