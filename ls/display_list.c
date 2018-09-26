/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:26:58 by agama             #+#    #+#             */
/*   Updated: 2018/08/31 08:01:45 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			lst_column(t_file *lst, t_index row_col, t_index maxlen
							, int flags)
{
	t_file			*lst_tmp;
	int				tmp_column;
	int				tmp_row;
	int				counter;

	counter = row_col.y;
	while (lst && counter--)
	{
		tmp_column = row_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_column--)
		{
			display_name(lst, flags, maxlen.y);
			if (tmp_column)
				ft_putnchar(MAX(maxlen.x - ft_strlen(lst->name), 0), ' ');
			tmp_row = row_col.y;
			while (lst && tmp_row--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = lst_tmp;
	}
	return (1);
}

static int			display_basic_list(t_file *lst, int flags)
{
	t_index			maxlen;
	t_index			i;
	t_file			*temp_lst;
	struct ttysize	ts;
	int				total;

	total = 0;
	maxlen.x = lst_maxlen(lst) + ((flags & LS_G) ? 1 : 4);
	maxlen.y = (flags & LS_S) ? lst_blocks_len(lst, &total) : 0;
	if (flags & LS_S)
		ft_printf("total %d\n", total);
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(flags & 128)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	temp_lst = lst;
	while (temp_lst)
	{
		++i.y;
		temp_lst = temp_lst->next;
	}
	if (!(flags & 128))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	lst_column(lst, i, maxlen, flags);
	return (1);
}

int					display_list(t_file **begin, int flags)
{
	sort_list(begin, flags);
	if (!(flags & LS_L))
		display_basic_list(*begin, flags);
	else
		display_list_details(*begin, flags);
	return (1);
}
