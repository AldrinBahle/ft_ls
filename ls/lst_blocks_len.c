/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_blocks_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:23:49 by agama             #+#    #+#             */
/*   Updated: 2018/08/28 08:28:15 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lst_blocks_len(t_file *lst, int *total)
{
	int	maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(integer_len(lst->st_blocks), maxlen);
		*total += lst->st_blocks;
		lst = lst->next;
	}
	return (maxlen);
}
