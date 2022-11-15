/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:10:02 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 16:17:49 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/includes/libft.h"
# include "../../includes/minirt.h"

t_list	*map_init(const char *file);
void	lst_rgb(t_list *data, char *s);
void	lst_vec(t_list *data, char *s);
void	lst_orig(t_list *data, char *s);
char	**my_split(char *line, char c);
int		insert_a(t_list *data, char **s);
int		insert_c(t_list *data, char **s);
int		insert_l(t_list *data, char **s);
int		insert_sp(t_list *data, char **s);
int		insert_pl(t_list *data, char **s);
int		insert_cy(t_list *data, char **s);
void	split_free(char **split);
int		open_file(const char *path);
void	set_check(int *check);
void	check_check(int *check);
void	one_vaild_check(t_list *e, int *check);

#endif