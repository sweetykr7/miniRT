
#include "../includes/minirt.h"

int is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
double  atod_get_number(char *str, double num, double temp, int flag)
{
	if (!flag)
		num = num * 10 + (*str - '0');
	else
	{
		num = num + (*str - '0') * temp;
		temp = temp * 0.1;
	}
	return (num);
}

int error_check(char *str, int cnt, int flag)
{
	int	*error;

	error = NULL;
	if (*str == '.')
	{
		str++;
		if (!(*str))
			return (error_return_zero(error));
		str--;
	}
	if (*str < '0' || *str > '9')
	{
		if (*str != '.' || (*str == '.' && flag))
			return (error_return_zero(error));
	}
	if (cnt == 15 && flag)
		return (-1);
	if (cnt == 15 && *str != '.')
		return (error_return_zero(error));
	else if (cnt == 15 && *str == '.')
		return (-1);
	return (1);
}

double  atod_input_calculator(char *str, double m, double num)
{
	double  temp;
	int	 flag;
	int	 cnt;
	flag = 0;
	cnt = 0;
	if (m < 0)
		cnt++;
	while (*str)
	{
		if (error_check(str, cnt, flag) == 0)
			ft_error("double error");
		if (error_check(str, cnt, flag) == -1)
			ft_error("double error");
		if (*str == '.')
		{
			temp = 0.1;
			flag = 1;
			str++;
		}
		num = atod_get_number(str, num, temp, flag);
		str++;
		cnt++;
	}
	return (num * m);
}
double  ft_atod(char *str)
{
	double  m;
	double  num;
	m = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m = -1;
		str++;
	}
	num = 0;
	if (*str < '0' || *str > '9')
	{
		return (0);
	}
	return (atod_input_calculator(str, m, 0));
}