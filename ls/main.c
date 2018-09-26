/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:57:36 by agama             #+#    #+#             */
/*   Updated: 2018/08/31 08:17:06 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char *argv[])
{
	int		i;
	int		flags;
	int		no_files;
	t_file	*file_lst;

	if ((i = parsing(argc, argv, &flags)) == -1)
		return (1);
	argv += i;
	argc -= i;
	file_lst = init_files_list(argc, argv, 1);
	no_files = (!file_lst ? 1 : 0);
	display_all(file_lst, flags, (!no_files ? 1 : 2), argc);
	free_list_content(&file_lst);
	return (0);
}
