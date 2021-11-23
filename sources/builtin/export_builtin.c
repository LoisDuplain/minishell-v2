/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:35:00 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/21 18:53:16 by lduplain         ###   ########.fr       */
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
	shell->exit_status = 0;
}

static void	display_env_variables(t_shell *shell)
{
	char	**sorted_env_variables;
	size_t	index;

	sorted_env_variables = sort_str_array(shell->env);
	index = 0;
	while (sorted_env_variables[index] != NULL)
	{
		ft_printf("declare -x %s\n", sorted_env_variables[index]);
		index++;
	}
	ft_destroy_string_array(&sorted_env_variables);
	shell->exit_status = 0;
}

void	export_builtin(t_shell *shell, char **cmd)
{
	size_t	index;

	index = 1;
	if (cmd[index] == NULL)
		display_env_variables(shell);
	while (cmd[index] != NULL)
	{
		if (is_alpha(cmd[index][0]) || cmd[index][0] == '_')
			export_variable(shell, cmd[index]);
		else
		{
			put_error("export", cmd[index], "not a valid identifier");
			shell->exit_status = 1;
			return ;
		}
		index++;
	}
}
