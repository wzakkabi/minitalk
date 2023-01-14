/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/15 00:37:42 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void msg(int a)
{
	a = 0;
	write(1, "succes", 7);
}

void converter(int c, int pid)
{
	char *bs;
		bs = "01";
	char *p;
	int y = 0;
	int x = 7;
	p = malloc(9);
	usleep(100);
	while(x >= 0)
	{
		y = c / 2;
		p[x] = bs[c % 2];
		c = y;
		x--;
	}
	p[8] = '\0';
	x = 0;
	usleep(100);
	while(x <= 8)
	{
		if(p[x] == '0')
		{
			kill(pid, SIGUSR1);
		}
		else if(p[x] == '1')
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		x++;
	}
	free(p);
}

int main(int arv, char **arc)
{
	int a = 0;
	
	if(arv >= 3)
	{
		signal(SIGUSR1 ,msg);
		while(arc[2][a])
			converter((unsigned char)arc[2][a++], ft_atoi(arc[1]));
	}
	return 0;
}