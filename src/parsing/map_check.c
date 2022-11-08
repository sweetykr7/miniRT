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

void	map_init(const char *file)
{
	char	**split;
	char	*line;
	int		form_check[3];
	int		fd;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Empty file");
	while (line)
	{
		if (line[0] || line[0] != '#')
		{
			split = my_split(line, ' ');
		}
		line = get_next_line(fd);
	}

	
}