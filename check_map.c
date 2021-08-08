/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:59:46 by dpants            #+#    #+#             */
/*   Updated: 2021/08/05 19:08:37 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_char(char c)
{
	char	*key_words;
	int		i;

	key_words = ft_strdup("10EPC");
	i = 0;
	while (key_words[i])
	{
		if (key_words[i] == c)
		{
			free(key_words);
			return (1);
		}
		i++;
	}
	free(key_words);
	return (0);
}

void	check_wall(t_config config)
{
	int	i;
	int	j;

	i = 0;
	while (i != config.map.height)
	{
		if (config.map.map[i][0] != '1' ||
		config.map.map[i][config.map.width - 1] != '1')
			exit_error("Wrong map - no walls around\n");
		i++;
	}
	j = 0;
	while (j != config.map.width)
	{
		if (config.map.map[0][j] != '1' ||
		config.map.map[config.map.height - 1][j] != '1')
			exit_error("Wrong map - no walls around\n");
		j++;
	}
}

void	check_config_map(t_config config)
{
	int	i;
	int	j;

	i = 0;
	if (config.player.count > 1 || config.exit.count > 1)
		exit_error("Wrong map - more then one P or E\n");
	if (config.player.count < 1 || config.exit.count < 1)
		exit_error("Wrong map - no one P or E\n");
	if (config.map.col_count < 1)
		exit_error("Wrong map - no one collectible on map\n");
	while (i != config.map.height - 1)
	{
		j = 0;
		while (j != config.map.width - 1)
		{
			if (!check_char(config.map.map[i][j]))
				exit_error("Wrong map - not valid character\n");
			j++;
		}
		i++;
	}
	check_wall(config);
}
