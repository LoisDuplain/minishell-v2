/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:28:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:57:36 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_builtin(t_shell *shell, char **args)
{
	char	*pwd;

	(void)shell;
	(void)args;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		put_error("pwd", "getcwd error", strerror(errno));
		errno = 1;
		return ;
	}
	ft_putstr_nl(pwd);
	free(pwd);
	errno = 0;
}
