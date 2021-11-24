/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_process_piped_func.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:16:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 19:14:01 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROCESS_PIPED_FUNC_H
# define MINISHELL_PROCESS_PIPED_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Close pipe fds.
**	./process/piped/close_pipe.c
*/
void	close_pipe(t_cmd *cmd);

/*
**	Redirect STDIN and STDOUT to the matching pipe fd.
**	./process/piped/start_piped_redirections.c
*/
void	start_piped_redirections(t_cmd *cmd);

/*
**	Wait pid of piped commands.
**	./process/piped/wait_pipeds.c
*/
void	wait_pipeds(t_shell *shell, t_cmd *cmd);

/*
**	 Process piped commands.
**	./process/piped/process_piped.c
*/
t_cmd	*process_pipeds(t_shell *shell, t_cmd *cmd);

#endif
