/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:11:18 by dpants            #+#    #+#             */
/*   Updated: 2021/08/05 17:08:00 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_nlen(int n)
{
	int		l;

	l = 0;
	while (n >= 0)
	{
		l++;
		n /= 10;
		if (n == 0)
			return (l);
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	str[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	i += ft_nlen(n);
	str[i--] = '\0';
	while (n >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			return (ft_strdup(str));
	}
	return (ft_strdup(str));
}

char	*ft_strjoins(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * len);
	if (NULL == new_str)
		return (NULL);
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}

void	defeat_window(void)
{
	printf("You lose\n (\\_/)\n (>.<)\n(\")_(\")\n");
	exit(0);
}

void	victory_window(t_config config)
{
	printf("Move: %d\n", config.player.move_count++ + 1);
	printf("Such WOW!\nYou won with %d moves.\n", config.player.move_count);
	exit(0);
}
