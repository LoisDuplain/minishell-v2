/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 16:22:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_shell *shell, char *message)
{
	ft_putstr_nl("exit");
	if (message != NULL)
	{
		ft_putstr("\033[0;31m");
		ft_putstr(message);
		ft_putstr_nl("\033[0m");
	}
	destroy_shell(&shell);
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	shell = create_shell(env);
	if (shell == NULL)
		exit_shell(shell, "Shell creation failed.");
	display_env(shell);
	while (TRUE)
	{
		shell->line = readline(shell->prompt);
		if (shell->line == NULL || ft_strcmp(shell->line, "exit") == 0)
			exit_shell(shell, "Goodbye :)");
		if (ft_strlen(shell->line) > 0)
		{
			add_history(shell->line);
		}
	}
	return (0);
}
