/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shell_func.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:34:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 16:00:31 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SHELL_FUNC_H
# define MINISHELL_SHELL_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new shell structure.
**	./shell/create_shell.c
*/
t_shell	create_shell(char **env);

/*
**	Destroy shell structure.
**	./shell/destroy_shell.c
*/
void	*destroy_shell(t_shell *shell);

/*
**	Update prompt in shell structure.
**	./shell/update_prompt.c
*/
void	update_prompt(t_shell *shell);

/*
**	Free previous allocated line string and read the new one.
**	./shell/set_line.c
*/
void	set_line(t_cmd_container *cmd_container, char *line);

#endif
