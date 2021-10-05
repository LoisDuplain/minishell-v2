/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:48:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/05 13:15:18 by lduplain         ###   ########.fr       */
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
**	Builtins can produce some errors, this function has been created to print
**	it correctly.
**	./builtin/put_builtin_error.c
*/
void	put_builtin_error(char *builtin, char *content, char *error);

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

#endif