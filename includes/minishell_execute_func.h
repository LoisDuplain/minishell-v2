/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:16:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:06:36 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTE_FUNC_H
# define MINISHELL_EXECUTE_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Execute parsed and transormed cmd.
**	./execute/execute_cmd.c
*/
void	execute_cmd(t_shell *shell, t_cmd *cmd);

/*
**	Execute a program.
**	./execute/execute_program.c
*/
void	execute_program(t_shell *shell, char *program_path, t_cmd *cmd);

/*
**	Get full program by it's name.
**	(Function search program in PATH environment variable)
**	./execute/get_program_path.c
*/
char	*get_program_path(t_shell *shell, char *program);

/*
**	Build full program path.
**	Example:
**	path = "/bin"
**	progran = "ls"
**	result = "/bin/ls"
**	./execute/build_program_path.c
*/
char	*build_program_path(char *path, char *program);

/*
**	Check if program is in path folder.
**	./execute/program_exists_at.c
*/
t_bool	program_exists_at(char *path, char *program);

#endif
