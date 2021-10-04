/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:38:04 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 16:04:09 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(t_shell *shell, char **cmd)
{
	char	*path;

	/* TODO: Set old pwd */
	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~") == 0)
		path = get_env_var(shell, "HOME");
	else
		path = ft_strdup(cmd[1], FALSE);
	if (path == NULL)
		return ;
	if (chdir(path) == -1)
	{
		ft_putstr_err("cd: ");
		ft_putstr_err(path);
		ft_putstr_errnl(": No such file or directory");
		errno = 1;
	}
	else
	{
		update_prompt(shell);
		errno = 0;
	}
	free(path);
}
