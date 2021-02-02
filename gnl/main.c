/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:16:04 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/12/05 14:57:44 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string.h>


int	main(int argc, char **argv)
{
	int		fd;
	char	*line = 0;
	int	i;
	int	r;
	char	*tests[9] = {
		"tests/z_emptysingle", 
		"tests/z_emptymulti",
		"tests/z_onesingle", 
		"tests/z_onemulti",
		"tests/z_shortsingle", 
		"tests/z_shortmulti",
		"tests/z_longsingle", 
		"tests/z_longmulti",
		NULL
	};
	int	tcount;

	(void)argc;
	(void)argv;
	i = 0;
	tcount = 0;
	printf("TESTS\n\n\n");
	while (tests[tcount])
	{
		fd = open(tests[tcount], O_RDONLY);
		if (fd == -1)
			return (1);
		printf("TEST FROM FILE: %s\n\n", tests[tcount]);
		while (((r = get_next_line(fd, &line)) > 0))
		{
			printf("%d-%s\n", r, line);
			free (line);
		}
		printf("%d-%s\n", r, line);
		free(line);
		close(fd);
		tcount++;
	}
	printf("\n\nTEST FROM STDIN\n\n");
	while (((r = get_next_line(0, &line)) > 0))
	{
		printf("%d-%s\n", r, line);
		free (line);
	}
	printf("%d-%s\n", r, line);
	free(line);
	return (0);
}
