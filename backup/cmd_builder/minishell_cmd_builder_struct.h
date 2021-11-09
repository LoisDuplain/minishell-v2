/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builder_struct.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:29:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 12:01:33 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_BUILDER_STRUCT_H
# define MINISHELL_CMD_BUILDER_STRUCT_H

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
	t_cmd	*cmds;
}	t_cmd_container;

/* typedef struct s_cmd_builder
{
	char	*line;
	size_t	readed_index;
	char	***cmds;
	char	**cmd;
	char	*cmd_part;
}	t_cmd_builder; */

/*
**	END DEFINES
*/

#endif
