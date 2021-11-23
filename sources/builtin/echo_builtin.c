/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:12:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/21 18:52:40 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_builtin(t_shell *shell, char **cmd)
{
	t_bool	print_nl;
	size_t	index;

	(void)shell;
	print_nl = TRUE;
	index = 1;
	while (cmd[index] != NULL && ft_strcmp(cmd[index], "-n") == 0)
	{
		print_nl = FALSE;
		index++;
	}
	while (cmd[index] != NULL)
	{
		ft_putstr(cmd[index]);
		if (cmd[index + 1] != NULL)
			ft_putchar(' ');
		index++;
	}
	if (print_nl)
		ft_putchar('\n');
	shell->exit_status = 0;
}
