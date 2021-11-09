/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:59:10 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:26:03 by lduplain         ###   ########.fr       */
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

typedef struct s_cmd
{
	size_t			index;
	char			**args;
	size_t			size;
	t_bool			piped;
	struct s_cmd	*prev;
	struct s_cmd	*next;
	int				pipe[2];
}	t_cmd;

/*
**	END DEFINES
*/

#endif