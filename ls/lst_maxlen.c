/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_maxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:12:04 by agama             #+#    #+#             */
/*   Updated: 2018/08/21 12:14:50 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lst_maxlen(t_file *lst)
{
	int	maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(ft_strlen(lst->name), maxlen);
		lst = lst->next;
	}
	return (maxlen);
}
