/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstselect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:41:56 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/11 12:52:27 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstselect(t_list *lst, int index)
{
	int	lstsize;

	lstsize = ft_lstsize(lst);
	if (index < 0)
	{
		ft_printf("%s\n", "Index cannot be -, rtn [0]");
		return (lst);
	}
	if (index > lstsize)
	{
		ft_printf("<ft_lstselect : %d, Max index is %d. rtn [0]>", index, lstsize);
		write(1, "\n", 1);
		return (lst);
	}
	while (index)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
