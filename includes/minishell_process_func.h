/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_process_func.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:49:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/20 13:00:41 by lduplain         ###   ########.fr       */
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

#endif
