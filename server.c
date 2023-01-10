/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/10 20:56:02 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

void converter(char *p)
{
	char *bs;
	int x;
	int y;
	int crt = 0;
	char cc;
	int pp;
	y = 1;
	x = 7;
	bs = "0123456789";
	while(x >= 0)
	{
		if(p[x] == '1')
			crt = crt + y;
		y = y * 2;
		x--;	
	}
	write(1, &crt, 1);
}


void walid(int a)
{
	static char p[9];
	static int x = 0;

	if(a == 30)
		p[x] = '0';
	if(a == 31)
		p[x] = '1';
	x++;
	if(x == 8)
	{
		x = 0;
		converter(p);
	}
	//ft_putnbr_fd(x,1);cd 
}

int main()
{
	pid_t a = getpid();
	char *p = ft_itoa(a);
	ft_putstr_fd(p, 1);
	signal(SIGUSR1, walid);
	signal(SIGUSR2, walid);
	//pause();
	while(1);

	return 0;
}
