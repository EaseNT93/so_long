/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:27:42 by dpants            #+#    #+#             */
/*   Updated: 2021/08/08 18:37:41 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	exit_error(char *str)
{
	printf("ERROR\n%s", str);
	exit(1);
}

int	close_window(void)
{
	exit(0);
	return (0);
}

int	check_map_type(char *arg)
{
	char	*format;
	int		i;
	int		j;

	format = ft_strdup(".ber");
	i = 0;
	j = 0;
	while (arg[i])
		i++;
	while (format[j])
	{
		if (format[j] != arg[i - 4])
			exit_error("Wrong map type\n");
		i++;
		j++;
	}
	i = open(arg, O_RDONLY);
	if (i < 0)
		exit_error("Map file not exist\n");
	free(format);
	return (i);
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
		exit_error("Wrong number of arguments\n");
	config = init_config(check_map_type(argv[1]));
	config.window.window = mlx_new_window(config.window.mlx,
			config.map.width * 32, config.map.height * 32, "Much long");
	mlx_hook(config.window.window, 2, 0, key_pressed, &config);
	mlx_hook(config.window.window, 17, 0, close_window, &config);
	mlx_loop_hook(config.window.mlx, draw_map, &config);
	mlx_loop(config.window.mlx);
	return (0);
}
