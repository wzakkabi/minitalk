/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/13 00:42:21 by wzakkabi         ###   ########.fr       */
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


void walid(int a, siginfo_t *ff, void *nll)
{
	static char p[10];
	static int x = 0;
	static int pd;
	int pidc = ff->si_pid;

	nll = 0;
	if(pd != pidc)
	{
		kill(pidc, SIGUSR1);
		pd = pidc;
		x = 0;
	}
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
	
}

int main()
{
	pid_t a = getpid();
	char *p = ft_itoa(a);
	struct sigaction ac;
	ac.sa_sigaction = walid;
	//ac.sa_handler = walid;
	ft_putstr_fd(p, 1);
	sigaction(SIGUSR1, &ac , NULL);
	sigaction(SIGUSR2, &ac , NULL);
	
	while(1);

	return 0;
}
