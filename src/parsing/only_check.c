/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:53:47 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:40 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	set_check(int *check)
{
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
}

void	check_check(int *check)
{
	if (!(check[0] == 1 && check[1] == 1 && check[2] == 1))
		ft_error("file currupted");
}

void	one_vaild_check(t_list *e, int *check)
{
	if (e->id == A)
		check[0]++;
	else if (e->id == C)
		check[1]++;
	else if (e->id == L)
		check[2]++;
}
