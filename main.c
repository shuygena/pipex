/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:17:45 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 08:18:33 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		*fd;
	int		*files;

	if (argc != 5)
		return (ft_error(1, NULL, NULL));
	fd = (int *)malloc(sizeof(int) * 2);
	files = (int *)malloc(sizeof(int) * 2);
	open_and_pipe(files, fd, argv);
	if (!fd || !files || files[0] == -1 || files[1] == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (ft_error(3, NULL, NULL));
	if (pid == 0)
		ft_daughter1(ft_split(argv[2], ' '), envp, fd, files);
	else
		ft_parent(ft_split(argv[3], ' '), envp, fd, files);
	close(files[1]);
	close(fd[0]);
	return (0);
}
