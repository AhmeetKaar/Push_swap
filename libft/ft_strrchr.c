/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:19:14 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 18:50:17 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	p = (char *)s;
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i--;
	}
	return (NULL);
}
