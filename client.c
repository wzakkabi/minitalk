/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:12 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/01/07 01:09:51 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void converter(int c, int base)
{
	char *bs;
	
	if(base <= 2)
		bs = "01";
	else
		bs = "0123456789";
	
	if(c >= base)
		converter((c / base), base);
	write(1, &bs[c % base], 1);
}

int main()
{
	converter(254, 2);
	return 0;
}