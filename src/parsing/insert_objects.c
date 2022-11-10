/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:52:57 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/10 11:15:45 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	insert_sp(t_list *data, char **s)
{
	data->id = SP;
	lst_orig(data, s[1]);
	data->diameter = ft_atod(s[2]);
	lst_rgb(data, s[3]);
	printf("%d, <%f %f %f>, %f, <%d %d %d>\n", data->id, data->origin[0], data->origin[1], data->origin[2], data->diameter, data->rgb[0], data->rgb[1], data->rgb[2]);
	return (TRUE);
}

int	insert_pl(t_list *data, char **s)
{
	data->id = PL;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	lst_rgb(data, s[3]);
	printf("%d, <%f %f %f>, <%f %f %f>, <%d %d %d>\n", data->id, data->origin[0], data->origin[1], data->origin[2], data->vec[0], data->vec[1], data->vec[2], data->rgb[0], data->rgb[1], data->rgb[2]);
	return (TRUE);
}

int	insert_cy(t_list *data, char **s)
{
	data->id = CY;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	data->diameter = ft_atod(s[3]);
	data->height = ft_atod(s[4]);
	lst_rgb(data, s[5]);
	printf("%d, <%f %f %f>, <%f %f %f>, %f, %f, <%d %d %d>\n", data->id,  data->origin[0], data->origin[1], data->origin[2], data->vec[0], data->vec[1], data->vec[2], data->diameter, data->height, data->rgb[0], data->rgb[1], data->rgb[2]);
	return (TRUE);
}