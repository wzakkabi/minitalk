/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:29 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/09 03:31:58 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"


int main()
{
	pid_t a = getpid();
	char *p = ft_itoa(a);
	ft_putstr_fd(p, 1);
	sleep(100);
	return 0;
}
