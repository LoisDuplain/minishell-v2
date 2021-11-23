/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:59:10 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:01:39 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_STRUCT_H
# define MINISHELL_CMD_STRUCT_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	START DEFINES
*/

typedef struct s_shell_redir
{
	int	fd_backup;
	int	fd_replaced;
}	t_shell_redir;

typedef struct s_cmd
{
	size_t			index;
	char			**tokens;
	char			**args;
	size_t			size;
	struct s_cmd	*prev;
	struct s_cmd	*next;
	t_bool			piped;
	int				pipe[2];
	pid_t			pid;
	t_shell_redir	out_redir;
	t_shell_redir	in_redir;
}	t_cmd;

/*
**	END DEFINES
*/

#endif