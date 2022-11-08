#include "../libft/includes/libft.h"
#include "../../includes/minirt.h"
#include <stdio.h>
#include <fcntl.h>



char	**my_split(char *line, char c)
{
	char	**split;

	split = ft_split(line, c);
	if (split == NULL)
		ft_error("Malloc failure");
	return (split);
}

static int	open_file(const char *path, int oflag)
{
	char	*pos;
	int		fd;

	if (!path)
		ft_error("No file");
	pos = ft_strchr(path, '.');
	if (pos && ft_strncmp(pos, ".rt", 4))
		ft_error("Wrong file format");
	fd = open(path, oflag);
	if (fd < 0)
		ft_error("Cannot open file");
	return (fd);
}

void lst_rgb(t_list *data, char *s)
{
	char	**split;
	int		i;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
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
		i++;
	}
}

void lst_orig(t_list *data, char *s)
{
	char	**split;
	int		i;

	split = my_split(s, ',');
	i = 0;
	while (split[i])
	{
		data->origin[i] = ft_atod(split[i]);
		i++;
	}
}

void	insert_data(t_list *data, char **s)
{
	if (s[0][0] == 'A' && ft_strlen(s[0]) == 1)
	{
		data->id = A;
		data->ratio = ft_atod(s[1]);
		lst_rgb(data, s[2]);
		printf("%d, %f, <%d %d %d>\n", data->id, data->ratio, data->rgb[0], data->rgb[1], data->rgb[2]);
		return ;
	}
	if (s[0][0] == 'C' && ft_strlen(s[0]) == 1)
	{
		data->id = C;
		printf("%s\n", s[1]);

		lst_orig(data, s[1]);

		lst_vec(data, s[2]);
		data->fov = ft_atoi(s[3]);
		printf("%d, <%f %f %f>, <%f %f %f>, %d\n", data->id, data->origin[0], data->origin[1], data->origin[2], data->vec[0], data->vec[1], data->vec[2], data->fov);
	}
}

void	map_init(const char *file)
{
	char	**split;
	char	*line;
	int		form_check[3];
	int		fd;
	t_list	*data;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	data = ft_lstnew();
	if (data == 0)
		ft_error("Malloc failure");
	if (line == NULL)
		ft_error("Empty file");
	while (line)
	{
		if (line[0])
		{
			split = my_split(line, ' ');
			insert_data(data, split);
			ft_lstadd_back(&data, ft_lstnew());
			data = data->next;
		}
		line = get_next_line(fd);
	}
}