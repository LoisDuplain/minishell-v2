/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_container_struct.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:02:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:00:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_CONTAINER_STRUCT_H
# define MINISHELL_CMD_CONTAINER_STRUCT_H

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

typedef struct s_cmd_container
{
	char	*line;
	size_t	readed_index;
	t_cmd	**cmds;
	char	**tokens;
	char	*token;
}	t_cmd_container;

/*
**	END DEFINES
*/

#endif