/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/13 00:43:47 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

void msg(int a)
{
	write(1, "succes", 7);
}

void converter(int c, int base, int pid)
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
		y = c / base;
		p[x] = bs[c % base];
		c = y;
		x--;
	}
	p[8] = '\0';
	x = 0;
	while(x <= 8)
	{
		if(p[x] == '0')
		{
			kill(pid, SIGUSR1);
		}
		
		if(p[x] == '1')
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		x++;
	}
}

int main(int arv, char **arc)
{
	int a = 0;
	
	if(arv >= 3)
	{
		signal(SIGUSR1 ,msg);
		while(arc[2][a])
			converter((unsigned char)arc[2][a++], 2, atoi(arc[1]));
		//printf("%s", p);
	}
	return 0;
}