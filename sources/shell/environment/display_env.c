/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:09:01 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 15:10:41 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(t_shell *shell)
{
	size_t	line_index;

	line_index = 0;
	while (shell->env[line_index] != NULL)
	{
		ft_putstr_nl(shell->env[line_index]);
		line_index++;
	}
}
