/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:38:41 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 15:12:17 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	(*get_builtin(char *builtin_str))(t_shell *shell, char **cmd)
{
	if (ft_strcmp(builtin_str, "cd") == 0)
		return (&cd_builtin);
	else if (ft_strcmp(builtin_str, "echo") == 0)
		return (&echo_builtin);
	else if (ft_strcmp(builtin_str, "env") == 0)
		return (&env_builtin);
	else if (ft_strcmp(builtin_str, "exit") == 0)
		return (&exit_builtin);
	else if (ft_strcmp(builtin_str, "export") == 0)
		return (&export_builtin);
	else if (ft_strcmp(builtin_str, "pwd") == 0)
		return (&pwd_builtin);
	else if (ft_strcmp(builtin_str, "unset") == 0)
		return (&unset_builtin);
	else
		return (NULL);
}
