/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:19:27 by agama             #+#    #+#             */
/*   Updated: 2018/08/31 18:15:41 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_name(t_file *l, int flags, int blocks_len)
{
	if (blocks_len)
	{
		ft_putnchar(MAX(blocks_len - integer_len(l->st_blocks), 0), ' ');
		ft_printf("%d ", l->st_blocks);
	}
	if (flags & LS_G)
	{
		if (S_ISDIR(l->mode))
			ft_printf("%{cyan}%s%{eoc}", l->name);
		else
			ft_printf((S_IXUSR & l->mode) ? "%{red}%s%{eoc}" : "%s", l->name);
	}
	else
		ft_printf("%s", l->name);
}
