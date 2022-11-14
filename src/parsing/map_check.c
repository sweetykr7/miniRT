/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:51:24 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 14:53:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <fcntl.h>

static int	open_file(const char *path)
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
	if (flag == FALSE)
	{
		split_free(s);
		return ;
	}
	if (s[0][0] == 's' && s[0][1] == 'p' && ft_strlen(s[0]) == 2)
	{
		if (insert_sp(data, s))
		{
			split_free(s);
			return ;
		}
	}
	if (s[0][0] == 'p' && s[0][1] == 'l' && ft_strlen(s[0]) == 2)
	{
		if (insert_pl(data, s))
		{
			split_free(s);
			return ;
		}
	}
	if (s[0][0] == 'c' && s[0][1] == 'y' && ft_strlen(s[0]) == 2)
	{
		if (insert_cy(data, s))
		{
			split_free(s);
			return ;
		}
	}
	split_free(s);
}


t_list	*data_insert(t_list *ori, int fd, char **split)
{
	int		is_object;
	int		i;
	char	*line;
	t_list	*data;

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
			ft_lstadd_back(&data, ft_lstnew());
		}		
		line = get_next_line(fd);
	}
	// free(line);
	return (data);
}

t_list	*map_init(const char *file)
{
	char	**split;
	// char	*line;
	int		fd;
	t_list	*data;

	split = NULL;
	fd = open_file(file);
	// line = get_next_line(fd);
	// if (line == NULL)
	// {
	// 	close(fd);
	// 	ft_error("Empty file");
	// }
	data = ft_lstnew();
	if (data == NULL)
	{
		close(fd);
		// free(line);
		ft_error("Malloc failure");
	}
	data_insert(data, fd, split);
	free(split);
	close(fd);
	// free(line);
	return (data);
}
