/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:46:08 by mderome           #+#    #+#             */
/*   Updated: 2021/06/14 10:56:45 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*sptr;

	index = 0;
	if (!s || !f)
		return (NULL);
	sptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (sptr == NULL)
		return (NULL);
	ft_bzero(sptr, ft_strlen(s));
	while (s[index])
	{
		sptr[index] = f(index, s[index]);
		index++;
	}
	sptr[index] = '\0';
	return (sptr);
}
