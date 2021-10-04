/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 16:33:30 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_builtin(t_shell *shell, char **args)
{
	size_t	index;
	ssize_t	equal_char_index;

	index = 1;
	if (cmd[index] == NULL)
		display_env(shell);
	while (cmd[index] != NULL)
	{
		if (is_alpha(cmd[index][0]) || cmd[index][0] == '_')
		{
			equal_char_index = ft_find_char(cmd[index], '=');
			if (equal_char_index == -1)
				set_env_var(shell, cmd[index], NULL, FALSE);
			else
				set_env_var(shell, NULL, &cmd[index][equal_char_index], FALSE);
		}
		else
		{
			ft_putstr_err("export: ");
			ft_putstr_err(cmd[index]);
			ft_putstr_errnl(": not a valid identifier");
			errno = 1;
			return ;
		}
		index++;
	}
}
