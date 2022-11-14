/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:48:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 15:26:49 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	lst_rgb(t_list *data, char *s)
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
			ft_error("RGB overflow");
		data->rgb[i] = ft_atoi(split[i]);
		i++;
	}
	split_free(split);
	if (i != 3)
		ft_error("file currupted");
}

void	lst_vec(t_list *data, char *s)
{
	char	**split;
	int		i;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
		data->vec[i] = ft_atod(split[i]);
		if (data->vec[i] > 1.00000 || data->vec[i] < -1.000000)
			ft_error("Vector currupted");
		i++;
	}
	if (data->vec[0] == 0 && data->vec[1] == 0 && data->vec[2] == 0)
		ft_error("No Zero Vector");
	split_free(split);
	if (i != 3)
		ft_error("File currupted");
}

void	lst_orig(t_list *data, char *s)
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
	split_free(split);
	if (i != 3)
		ft_error("File currupted");
}

char	**my_split(char *line, char c)
{
	char	**split;

	split = ft_split(line, c);
	if (split == NULL)
		ft_error("Malloc failure");
	return (split);
}
