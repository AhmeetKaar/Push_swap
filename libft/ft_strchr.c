/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:45:05 by akar              #+#    #+#             */
/*   Updated: 2023/12/21 21:30:54 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	c = (char)c;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + i);
	return (0);
}
