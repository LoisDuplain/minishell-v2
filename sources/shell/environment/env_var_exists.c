/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:47:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 22:54:17 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	env_var_exists(t_shell *shell, char *key)
{
	char	*env_var_value;

	env_var_value = get_env_var(shell, key);
	if (env_var_value == NULL)
		return (FALSE);
	free(env_var_value);
	return (TRUE);
}
