/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:48:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:55:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_FUNC_H
# define MINISHELL_BUILTIN_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	CD builtin.
**	./builtin/cd_builtin.c
*/
void	cd_builtin(t_shell *shell, char **cmd);

/*
**	ECHO builtin.
**	./builtin/echo_builtin.c
*/
void	echo_builtin(t_shell *shell, char **cmd);

/*
**	PWD builtin.
**	./builtin/pwd_builtin.c
*/
void	pwd_builtin(t_shell *shell, char **args);

/*
**	EXIT builtin.
**	./builtin/exit_builtin.c
*/
void	exit_builtin(t_shell *shell, char **args);

/*
**	EXPORT builtin.
**	./builtin/export_builtin.c
*/
void	export_builtin(t_shell *shell, char **cmd);

/*
**	UNSET builtin.
**	./builtin/unset_builtin.c
*/
void	unset_builtin(t_shell *shell, char **cmd);

/*
**	ENV builtin.
**	./builtin/env_builtin.c
*/
void	env_builtin(t_shell *shell, char **cmd);

/*
**	Get builtin from string builtin name.
**	./builtin/get_builtin.c
*/
void	(*get_builtin(char *builtin_str))(t_shell *shell, char **cmd);

#endif