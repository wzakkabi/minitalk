/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/10 20:56:25 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

void converter(int c, int base)
{
	char *bs;
	if(base == 2)
		bs = "01";
	if(base == 10)
		bs = "0123456789";
	char *p;
	int y = 0;
	int x = 7;
	p = malloc(9);
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
			kill(38306, SIGUSR1);
			printf("0");
		}
		
		if(p[x] == '1')
		{
			kill(38306, SIGUSR2);
			printf("1");
		}
		usleep(1);
		x++;
	}
}

int main()
{
	converter('A', 2);
	//printf("%s", p);

	return 0;
}