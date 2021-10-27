/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_process_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:49:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 14:41:59 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROCESS_FUNC_H
# define MINISHELL_PROCESS_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Process parsed commands.
**	./process/process_cmds.c
*/
void	process_cmds(t_shell *shell, t_cmd_builder *cmd_builder);

/*
**	Process parsed command.
**	./process/process_cmd.c
*/
void	process_cmd(t_shell *shell, char **cmd, size_t cmd_len);

/*
**	Get processed argument.
**	./process/get_processed_arg.c
*/
char	*get_processed_arg(t_shell *shell, char *arg);

/*
**	When parser finds a quote, it executes get_processed_quote on an arg.
**	./process/get_processed_quote.c
*/
char	*get_processed_quote(t_shell *shell, char *arg,
			size_t arg_len, size_t *i);

/*
**	Get an env var after '$' character.
**	./process/get_env_var_name.c
*/
char	*get_env_var_name(char *arg, size_t arg_len, size_t *i);

/*
**	Append env var value to (char *)str.
**	./process/append_env_var_to_str.c
*/
char	*append_env_var_to_str(t_shell *shell, char *str, char *key);

#endif
