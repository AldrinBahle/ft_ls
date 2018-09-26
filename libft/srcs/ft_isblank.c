/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:58:26 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/09 18:31:41 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isblank(char c)
{
	if (!c)
		return (0);
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
