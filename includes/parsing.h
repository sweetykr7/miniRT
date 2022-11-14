/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:10:02 by jinwoole          #+#    #+#             */
/*   Updated: 2022/11/14 14:16:53 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/includes/libft.h"
# include "../../includes/minirt.h"
# include <stdio.h> //완성하기 전 지워야.

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

#endif