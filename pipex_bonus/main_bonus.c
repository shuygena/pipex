/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:21:19 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 08:01:48 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		**fd;
	int		count_cmd;

	if (argc < (5 + !(ft_strncmp(argv[1], "here_doc", 9))))
		return (ft_error(1, NULL, NULL));
	fd = (int **)malloc(sizeof(int *) * 2);
	if (!fd)
		return (0);
	fd[0] = (int *)malloc(sizeof(int) * 2);
	fd[1] = (int *)malloc(sizeof(int) * 1);
	if (!(fd[0]) || !(fd[1]))
		return (0);
	if (redirect_manipulate(argv, argc, fd) == 0)
		return (0);
	count_cmd = ft_count_cmd(argv, argc);
	ft_start_fork(count_cmd, argv, fd, envp);
	return (0);
}
