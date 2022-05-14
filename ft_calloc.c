/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:16:37 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:16:40 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(number * size);
	if (arr == NULL)
		return (NULL);
	while (i < (number * size))
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
