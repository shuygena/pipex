/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:20:44 by mskeleto          #+#    #+#             */
/*   Updated: 2021/12/07 07:20:46 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	substr = (char *)(ft_calloc((len + 1), sizeof(char)));
	i = 0;
	if (substr == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (substr);
	while ((len--) && (s[start + i]))
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
