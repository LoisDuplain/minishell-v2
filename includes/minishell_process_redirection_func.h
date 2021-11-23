/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_process_redirection_func.h               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:16:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/22 18:26:22 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROCESS_REDIRECTION_FUNC_H
# define MINISHELL_PROCESS_REDIRECTION_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Check if string (char *)arg is a redirection string.
**	Redirections: '<<', '<', '>>', '>'.
**	./process/redirection/is_redirection.c
*/
t_bool	is_redirection(char *arg);

/*
**	Get the output redirection mode by redirection string (char *)redirection.
**	Mode: '>>' => 'O_APPEND' | '>' => O_TRUNC
**	./process/redirection/get_output_redirection_mode.c
*/
int		get_output_redirection_mode(char *redirection);

/*
**	Start a shell redirection.
**	./process/redirection/start_shell_redirection.c
*/
void	start_shell_redirection(t_shell_redir *shell_redir,
			int to_replace, int by);

/*
**	Stop a shell redirection.
**	./process/redirection/stop_shell_redirection.c
*/
void	stop_shell_redirection(t_shell_redir *shell_redir);

/*
**	Execute the right redirection.
**	./process/redirection/dispatch_redirection.c
*/
t_bool	dispatch_redirection(t_cmd *cmd, size_t arg_index);

/*
**	Read on STDIN and write result into "read_until_buffer"
**	until user write string (char *)keyword.
**	./process/redirection/read_until_keyword.c
*/
t_bool	read_until_keyword(char *keyword);

/*
**	Start a redirection with a target file.
**	./process/redirection/start_file_redirection.c
*/
t_bool	start_file_redirection(t_shell_redir *shell_redir, char *file,
		int mode, int to_replace);

#endif
