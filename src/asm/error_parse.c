/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:37:21 by skrystin          #+#    #+#             */
/*   Updated: 2019/08/16 18:12:09 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	first_error(char *str, char *file, char **todel)
{
	ft_printf("%s", str);
	if (file)
		ft_printf("%s\n", file);
	if (todel && *todel)
		ft_strdel(todel);
	exit(0);
}

void	valid_errors(char *line, char ***todel, t_as **all, int flag)
{
	if (flag == 0)
		ft_printf("Syntax error at token - %s", line);
	if (flag == 'N')
		ft_printf("Champion name too long (Max length 128)");
	if (flag == 'C')
		ft_printf("Champion comment too long (Max length 2048)");
	if (flag == 'c' || flag == 'n')
		ft_printf("Invalid name or comment\n");
	if (todel && *todel)
		ft_arraydel((void ***)todel);
	delete_asm_all(all, NULL);
	exit(0);
}

void	invalid_comm(t_as **all, char ***todel, char *str)
{
	ft_printf("Invalid command, arguments or label - %s\n", str);
	if (todel && *todel)
		ft_arraydel((void ***)todel);
	delete_asm_all(all, NULL);
	exit(0);
}
