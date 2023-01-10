/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/10 01:51:01 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"
void walid(int a)
{
	printf("s1");
}

void walid1(int a)
{
	printf("s22");
}

int main()
{
	pid_t a = getpid();
	char *p = ft_itoa(a);
	ft_putstr_fd(p, 1);
	sigaction(SIGUSR1, SA_NOCLDWAIT, walid1);
	sigaction(SIGUSR2, SA_NOCLDWAIT,walid);
	pause();
	return 0;
}
