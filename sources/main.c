/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/14 18:08:23 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_shell *shell)
{
	ft_putstr_nl("exit");
	ft_putstr_nl("\033[0;31mGoodbye :)\033[0m");
	destroy_shell(&shell);
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = create_shell(env);
	while (TRUE)
	{
		set_line(shell, readline(shell->prompt));
		if (shell->line == NULL || ft_strcmp(shell->line, "exit") == 0)
			exit_shell(shell);
		if (ft_strlen(shell->line) > 0)
		{
			add_history(shell->line);
			ft_putstr_nl(getenv("TEST"));
		}
	}
	return (0);
}
