/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:48:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 11:47:17 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void lst_rgb(t_list *data, char *s)
{
	char	**split;
	int		i;
	int		num;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		if (num > 255 || num < 0)
		{
			free(data);
			ft_error("RGB overflow");
		}
		data->rgb[i] = ft_atoi(split[i]);
		i++;
	}
}
void lst_vec(t_list *data, char *s)
{
	char	**split;
	int		i;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
		data->vec[i] = ft_atod(split[i]);
		if (data->vec[i] > 1.00000 || data->vec[i] < 0.000000)
			ft_error("Vector currupted");
		i++;
	}
	if (data->vec[0] == 0 && data->vec[1] == 0 && data->vec[2] == 0)
		ft_error("No Zero Vector");
	if (i != 3)
		ft_error("Fire currupted");
}

void lst_orig(t_list *data, char *s)
{
	char	**split;
	int		i;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
		data->ori[i] = ft_atod(split[i]);
		i++;
	}
}