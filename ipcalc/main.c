/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:08:10 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/01/08 00:16:01 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	power(int base, int power)
{
	int	result;

	result = 1;
	while (power-- > 0)
		result = result * base;
	return (result);
}

void	print_address(char *s)
{
	int	i;
	int	pwr;
	int	add;

	i = 0;
	while (i < 32)
	{
		pwr = 8;
		add = 0;
		while (--pwr >= 0)
			if (s[i++] == '1')
				add += power(2, pwr);
		printf("%d", add);
		if (i != 32)
			printf(".");
	}
}

void	print(char *bin_net, int slash)
{
	int	slash_cp;
	char	*bin_host_start;
	char	*bin_host_end;
	char	*bin_broadcast;

	/* Net address */
	slash_cp = slash;
	while (slash_cp < 31)
		bin_net[slash_cp++] = '0';
	bin_net[slash_cp] = '0';
	/* Start host address */
	bin_host_start = strdup(bin_net);
	bin_host_start[slash_cp] = '1';
	/* End host address */
	bin_host_end = strdup(bin_host_start);
	slash_cp = slash;
	while (slash_cp < 31)
		bin_host_end[slash_cp++] = '1';
	bin_host_end[slash_cp] = '0';
	/* Broadcast */
	bin_broadcast = strdup(bin_host_end);
	bin_broadcast[slash_cp] = '1';
	/* Print net address */
	printf("\nNet address: ");
	print_address(bin_net);
	printf("\n\nHost addresses: ");
	print_address (bin_host_start);
	printf("   -   ");
	print_address (bin_host_end);
	printf("\n\nBroadcast address: ");
	print_address (bin_broadcast);
	printf("\n\nMax host address: %d\n\n", power(2, 32 - slash) - 2);
}

int	translate(char *bin, int add, int cp)
{
	int	pwr;
	
	pwr = 7;
	while (pwr >= 0)
	{
		if (add >= power(2, pwr))
		{
			bin[cp++] = '1';
			add -= power(2, pwr);
		}
		else
			bin[cp++] = '0';
		pwr--;
	}
	return (cp);
}

int	main(int argc, char **argv)
{
	int	i;
	int	add;
	int	slash;
	int	cp;
	char	*address;
	char	*bin_net;

	if (argc != 2)
		return (0);
	i = 0;
	cp = 0;
	bin_net = calloc(sizeof(char) * 32, 1);
	slash = 32;
	address = strdup(argv[1]);
	while (i < strlen(address))
	{
		add = 0;
		while (address[i] != '.' && address[i] != '/' && address[i] != '\0')
			add = add * 10 + (address[i++] - '0');
		cp = translate(bin_net, add, cp);
		if (address[i] == '/')
		{
			slash = 0;
			while (address[++i])
				slash = slash * 10 + (address[i] - '0');
		}
		i++;
	}
	print(bin_net, slash);
	free(bin_net);
	free(address);
	return (0);
}
