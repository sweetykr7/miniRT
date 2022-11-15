/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:21:47 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/15 14:19:52 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void)
{
	t_list	*lst_new;

	lst_new = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (lst_new == 0)
		return (0);
	lst_new->next = 0;
	return (lst_new);
}
