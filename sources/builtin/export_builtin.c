/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 18:16:39 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_export_variable_key(char *variable)
{
	char	*key;
	size_t	i;

	key = NULL;
	i = 0;
	while (variable[i] && variable[i] != '=')
	{
		key = ft_append_char_to_str(key, variable[i]);
		i++;
	}
	return (key);
}

static void	export_variable(t_shell *shell, char *variable)
{
	ssize_t	equal_char_index;
	char	*key;

	equal_char_index = ft_find_char(variable, '=');
	key = get_export_variable_key(variable);
	if (equal_char_index == -1)
		set_env_var(shell, variable, NULL, FALSE);
	else
		set_env_var(shell, key, &variable[equal_char_index + 1], FALSE);
	free(key);
	errno = 0;
}

void	export_builtin(t_shell *shell, char **cmd)
{
	size_t	index;

	index = 1;
	/* TODO: display correctement les variables exportees */
	if (cmd[index] == NULL)
		display_env(shell);
	while (cmd[index] != NULL)
	{
		if (is_alpha(cmd[index][0]) || cmd[index][0] == '_')
			export_variable(shell, cmd[index]);
		else
		{
			put_builtin_error("export", cmd[index], "not a valid identifier");
			errno = 1;
			return ;
		}
		index++;
	}
}
