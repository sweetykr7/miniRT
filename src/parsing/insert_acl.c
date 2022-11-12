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
	printf("%d, %f, <%d %d %d>\n", data->id, data->ratio, data->rgb[0], data->rgb[1], data->rgb[2]);
	return (TRUE);
}

int	insert_c(t_list *data, char **s)
{
	data->id = C;
	lst_orig(data, s[1]);
	lst_vec(data, s[2]);
	data->fov = ft_atoi(s[3]);
	printf("%d, <%f %f %f>, <%f %f %f>, %d\n", data->id, data->ori[0], data->ori[1], data->ori[2], data->vec[0], data->vec[1], data->vec[2], data->fov);
	return (TRUE);
}

int	insert_l(t_list *data, char **s)
{
	data->id = L;
	lst_orig(data, s[1]);
	data->ratio = ft_atod(s[2]);
	if (data->ratio < 0.00000000 || data->ratio > 1.00000000)
	{
		free(data);
		ft_error("File currupted");
	}
	lst_rgb(data, s[3]);
	//보너스,멘더토리 구분할때 이거 들어오면 터지게 예외처리 해야함 아마도
	printf("%d, <%f %f %f>, %f, <%d %d %d>\n", data->id, data->ori[0], data->ori[1], data->ori[2], data->ratio, data->rgb[0], data->rgb[1], data->rgb[2]);
	return (TRUE);
}
