/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:58:31 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argv;
	shell = create_shell(env);
	if (shell == NULL)
		exit_shell(shell, "Shell creation failed.");
	if (argc != 1)
		exit_shell(shell, "Wrong number of arguments.");
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, ctrl_backslash_signal);
	while (TRUE)
	{
		set_line(shell, readline(shell->prompt));
		if (shell->line == NULL)
			exit_shell(shell, "Goodbye :)");
		if (ft_strlen(shell->line) > 0)
		{
			add_history(shell->line);
			parse(shell);
		}
	}
	return (0);
}
