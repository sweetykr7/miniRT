/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:52:57 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 16:02:31 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <fcntl.h>

int	insert_sp(t_list *data, char **s)
{
	data->id = SP;
	lst_orig(data, s[1]);
	data->diameter = ft_atod(s[2]);
	if (data->diameter <= 0.00000000)
	{
		free(data);
		ft_error("File currupted");
	}
	lst_rgb(data, s[3]);
	return (TRUE);
}

int	insert_pl(t_list *data, char **s)
{
	data->id = PL;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	lst_rgb(data, s[3]);
	return (TRUE);
}

int	insert_cy(t_list *data, char **s)
{
	data->id = CY;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	data->diameter = ft_atod(s[3]);
	if (data->diameter <= 0.00000000)
	{
		free(data);
		ft_error("File currupted");
	}
	data->height = ft_atod(s[4]);
	if (data->height <= 0.00000000)
	{
		free(data);
		ft_error("File currupted");
	}
	lst_rgb(data, s[5]);
	return (TRUE);
}

int	open_file(const char *path)
{
	char	*pos;
	int		fd;

	if (!path)
		ft_error("No file");
	pos = ft_strchr(path, '.');
	if (pos && ft_strncmp(pos, ".rt", 4))
		ft_error("Wrong file format");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open file");
	return (fd);
}
