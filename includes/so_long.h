/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:11:13 by dpants            #+#    #+#             */
/*   Updated: 2021/08/08 18:11:05 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define SIZE 1

typedef struct s_img
{
	int		height;
	int		width;
	void	*ptr;
}			t_img;

typedef struct s_imgs
{
	t_img	wll;
	t_img	emp;
	t_img	ext[2];
	t_img	clt[4];
	t_img	plr[4];
	t_img	enm;
}			t_imgs;

typedef struct s_player
{
	int		i;
	int		j;
	int		count;
	int		stand;
	int		col_count;
	int		move_count;
}			t_player;

typedef struct s_exit
{
	int		i;
	int		j;
	int		count;
}			t_exit;

typedef struct s_map
{
	int		height;
	int		width;
	int		col_count;
	char	**map;
}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*window;
}			t_window;

typedef struct s_enm
{
	int		i;
	int		j;
}			t_enm;

typedef struct s_config
{
	t_window	window;
	t_map		map;
	t_player	player;
	t_exit		exit;
	t_imgs		imgs;
	t_enm		enm[100];
	int			enm_cout;

}				t_config;

char		*get_next_line(int fd);

int			ft_strlen(const char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strchr(const char *str, int s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoins(char *s1, char *s2);
char		*ft_strdup(const char *str);

int			key_pressed(int k_code, t_config *config);

void		parse_map(t_config *config, int fd);
t_config	init_config(int fd);

void		get_config_map(int i, char *line, t_config *config);
void		check_config_map(t_config config);
int			check_char(char c);

void		exit_error(char *str);
void		victory_window(t_config config);
void		defeat_window(void);

char		*ft_itoa(int n);
int			get_random(void);

int			draw_map(t_config *cfg);

void		init_textures(t_config *cfg);
void		init_enemy(t_config *cfg);
void		enemy_move(t_config *c);

#endif