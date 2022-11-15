/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:51:24 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/15 15:19:16 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	insert_only(t_list *data, char **s)
{
	if (s[0][0] == 'A' && ft_strlen(s[0]) == 1)
	{
		if (insert_a(data, s))
			return (FALSE);
	}
	if (s[0][0] == 'C' && ft_strlen(s[0]) == 1)
	{
		if (insert_c(data, s))
			return (FALSE);
	}
	if (s[0][0] == 'L' && ft_strlen(s[0]) == 1)
	{
		if (insert_l(data, s))
			return (FALSE);
	}
	return (TRUE);
}

void	insert_objects(t_list *data, char **s, int flag)
{
	if (s[0][0] == 's' && s[0][1] == 'p' && ft_strlen(s[0]) == 2 && flag == 1)
	{
		if (insert_sp(data, s))
		{
			split_free(s);
			return ;
		}
	}
	if (s[0][0] == 'p' && s[0][1] == 'l' && ft_strlen(s[0]) == 2 && flag == 1)
	{
		if (insert_pl(data, s))
		{
			split_free(s);
			return ;
		}
	}
	if (s[0][0] == 'c' && s[0][1] == 'y' && ft_strlen(s[0]) == 2 && flag == 1)
	{
		if (insert_cy(data, s))
		{
			split_free(s);
			return ;
		}
	}
	split_free(s);
}

void	data_insert(t_list *ori, int fd, char **split)
{
	int		is_object;
	int		i;
	char	*line;

	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0])
		{
			is_object = FALSE;
			split = my_split(line, ' ');
			free(line);
			is_object = insert_only(ft_lstselect(ori, ++i), split);
			insert_objects(ft_lstselect(ori, i), split, is_object);
			ft_lstadd_back(&ori, ft_lstnew());
		}
		line = get_next_line(fd);
	}
}

t_list	*map_init(const char *file)
{
	char	**split;
	int		fd;
	t_list	*data;

	split = NULL;
	fd = open_file(file);
	data = ft_lstnew();
	if (data == NULL)
	{
		close(fd);
		ft_error("Malloc failure");
	}
	data_insert(data, fd, split);
	free(split);
	close(fd);
	return (data);
}
