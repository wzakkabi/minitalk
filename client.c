/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/20 01:05:03 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char *p, int pid)
{
	int	x;

	x = 0;
	usleep(100);
	while (x <= 8)
	{
		if (p[x] == '0')
		{
			kill(pid, SIGUSR1);
		}
		else if (p[x] == '1')
		{
			kill(pid, SIGUSR2);
		}
		usleep (100);
		x++;
	}
}

void	converter(int c, int pid)
{
	char	*bs;
	char	p[9];
	int		y;
	int		x;

	if (pid <= 10)
		return ;
	x = 7;
	y = 0;
	bs = "01";
	while (x >= 0)
	{
		y = c / 2;
		p[x] = bs[c % 2];
		c = y;
		x--;
	}
	p[8] = '\0';
	send(p, pid);
}

int	main(int arv, char **arc)
{
	int	a;

	a = 0;
	if (arv >= 3)
	{
		while (arc[2][a])
			converter(arc[2][a++], ft_atoi(arc[1]));
	}
	return (0);
}
