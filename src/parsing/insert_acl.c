/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_acl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:12:18 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 12:13:46 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	insert_a(t_list *data, char **s)
{
	data->id = A;
	data->ratio = ft_atod(s[1]);
	if (data->ratio < 0.00000000 || data->ratio > 1.00000000)
	{
		free(data);
		ft_error("File currupted");
	}
	lst_rgb(data, s[2]);
	return (TRUE);
}

int	insert_c(t_list *data, char **s)
{
	data->id = C;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	data->fov = ft_atoi(s[3]);
	return (TRUE);
}

int	insert_l(t_list *data, char **s)
{
	data->id = L;
	lst_orig(data, s[1]);
	data->ratio = ft_atod(s[2]);
	lst_rgb(data, s[3]);
	return (TRUE);
}
