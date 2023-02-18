/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/20 01:04:22 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	converter(char *p)
{
	char	*bs;
	int		x;
	int		y;
	int		crt;

	crt = 0;
	y = 1;
	x = 7;
	bs = "0123456789";
	while (x >= 0)
	{
		if (p[x] == '1')
			crt = crt + y;
		y = y * 2;
		x--;
	}
	write (1, &crt, 1);
}

void	walid(int a, siginfo_t *ff, void *nll)
{
	static char	p[10];
	static int	x;
	static int	pd;

	nll = 0;
	if (pd != ff->si_pid)
	{
		kill(ff->si_pid, SIGUSR1);
		pd = ff->si_pid;
		x = 0;
	}
	if (a == 30)
	{
		p[x] = '0';
	}
	if (a == 31)
	{
		p[x] = '1';
	}
	x++;
	if (x == 8)
	{
		x = 0;
		converter(p);
	}
}

int	main(void)
{
	struct sigaction	ac;

	ac.sa_sigaction = walid;
	ft_putnbr(getpid());
	while (1)
	{
		sigaction(SIGUSR2, &ac, NULL);
		sigaction(SIGUSR1, &ac, NULL);
		pause();
	}
	return (0);
}
