/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:48:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 15:34:00 by lduplain         ###   ########.fr       */
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
**	CD builtin..
**	./builtin/cd_builtin.c
*/
void	cd_builtin(t_shell *shell, char **cmd);

/*
**	ECHO builtin..
**	./builtin/echo_builtin.c
*/
void	echo_builtin(t_shell *shell, char **cmd);

/*
**	PWD builtin..
**	./builtin/pwd_builtin.c
*/
void	pwd_builtin(t_shell *shell, char **args);

#endif