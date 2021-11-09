/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:56:21 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 12:13:34 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_shell *shell, char *message)
{
	if (message != NULL)
	{
		ft_putstr("\033[0;31m");
		ft_putstr(message);
		ft_putstr_nl("\033[0m");
	}
	destroy_shell(shell);
	exit(0);
}
