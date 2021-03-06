/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:38:04 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 15:28:28 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_builtin(t_shell *shell, char **cmd)
{
	char	*path;
	char	*old_pwd;

	if (cmd[1] == NULL || ft_strcmp(cmd[1], "~") == 0)
		path = get_env_var(shell, "HOME");
	else
		path = ft_strdup(cmd[1]);
	if (path == NULL)
		return ;
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		put_error("cd", path, strerror(errno));
		shell->exit_status = 1;
	}
	else
	{
		set_env_var(shell, "OLDPWD", old_pwd, FALSE);
		update_prompt(shell);
		shell->exit_status = 0;
	}
	free(path);
	free(old_pwd);
}
