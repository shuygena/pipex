/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:20:17 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:20:18 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(dest) + ft_strlen(src) + 2);
	while (dest != NULL && (dest[j] != '\0'))
	{
		new_str[j] = dest[j];
		j++;
	}
	new_str[j] = '/';
	j++;
	while (src != NULL && src[i] != '\0')
	{
		new_str[j] = src[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
