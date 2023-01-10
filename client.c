/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/10 01:40:36 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "libft.h"

char *converter(int c, int base)
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
	
	return p;
}

int main()
{
	char *p = converter('0', 10);
	printf("%s", p);
	kill(8746,  SIGUSR1);
	return 0;
}