/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:28:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 15:32:52 by lduplain         ###   ########.fr       */
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
		ft_putstr_err("pwd: getcwd error: ");
		ft_putstr_errnl(strerror(errno));
		return ;
	}
	ft_putstr_nl(pwd);
	free(pwd);
	errno = 0;
}
