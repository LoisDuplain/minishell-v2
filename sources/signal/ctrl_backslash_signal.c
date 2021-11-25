/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_backslash_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:12:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 12:06:56 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_backslash_signal(int signal)
{
	(void)signal;
	if (g_shell->is_in_execution)
		ft_putstr_nl("Quit: 3");
	else
	{
		rl_on_new_line();
		rl_replace_line("  ", 0);
		rl_redisplay();
		rl_replace_line("", 0);
	}
}
