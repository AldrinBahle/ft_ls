/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 03:23:25 by angavrel          #+#    #+#             */
/*   Updated: 2018/08/27 12:45:48 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	wchar_t	*s2;
	size_t	len;

	len = ft_wstrlen((wchar_t *)s1) * sizeof(wchar_t);
	if (!s1 || !(s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) + len))))
		return (NULL);
	ft_memcpy(s2, s1, len);
	return (s2);
}
