/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:08:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 15:11:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_builtin(t_shell *shell, char **args)
{
	(void)args;
	ft_putstr_errnl("exit");
	ft_putstr("\033[0;32m");
	ft_putstr("Goodbye :)");
	ft_putstr_nl("\033[0m");
	exit_shell(shell, NULL);
}
