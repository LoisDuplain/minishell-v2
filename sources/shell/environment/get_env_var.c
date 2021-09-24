/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:24:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/24 16:05:30 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_shell *shell, char *key)
{
	ssize_t	env_var_index;

	if (ft_strcmp(key, "?") == 0)
	{
		/* TODO: PRINT ERRNO VALUE */
		return (ft_strdup("ERRNO VALUE (TODO)", FALSE));
	}
	env_var_index = get_env_var_index(shell, key);
	if (env_var_index == -1)
		return (NULL);
	return (ft_strdup(&shell->env[env_var_index][ft_strlen(key) + 1], FALSE));
}
