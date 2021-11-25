/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:08:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 12:59:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_builtin_action(t_shell *shell, int exit_code)
{
	ft_putstr("\033[0;32m");
	ft_putstr("Goodbye :)");
	ft_putstr_nl("\033[0m");
	errno = exit_code;
	exit_shell(shell, NULL, exit_code);
}

void	exit_builtin(t_shell *shell, char **args)
{
	size_t	args_size;

	args_size = ft_get_string_array_length(args);
	ft_putstr_errnl("exit");
	if (args_size == 1)
		exit_builtin_action(shell, 0);
	else if (args_size >= 2)
	{
		if (!is_numberstr(args[1]))
		{
			put_error("minishell", "exit", "numeric argument required");
			exit_builtin_action(shell, 255);
		}
		if (args_size > 2)
			put_error("minishell", "exit", "too many arguments");
		else
			exit_builtin_action(shell, ft_atoi(args[1]) % 256);
	}
}
