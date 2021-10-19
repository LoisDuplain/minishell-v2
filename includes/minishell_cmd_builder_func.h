/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builder_func.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:30:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:35:19 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_BUILDER_FUNC_H
# define MINISHELL_CMD_BUILDER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new cmd_builder strucutre.
**	./cmd_builder/create_cmd_builder.c
*/
t_cmd_builder	*create_cmd_builder(char *line);

/*
**	Destroy cmd_builder strucutre.
**	./cmd_builder/destroy_cmd_builder.c
*/
void			*destroy_cmd_builder(t_cmd_builder **cmd_builder);

/*
**	Get the length of cmds (array containing multiple cmd).
**	./cmd_builder/get_cmds_length.c
*/
size_t			get_cmds_length(t_cmd_builder *cmd_builder);

/*
**	Append current cmd with current next part and set next to null.
**	./cmd_builder/next_cmd_part.c
*/
void			next_cmd_part(t_cmd_builder *cmd_builder);

/*
**	Append cmds with current cmd and set next to null.
**	./cmd_builder/next_cmd_part.c
*/
void			next_cmd(t_cmd_builder *cmd_builder);

/*
**	Display a cmd_bulder as text.
**	./cmd_builder/display_cmd_builder.c
*/
void	display_cmd_builder(t_cmd_builder *cmd_builder);

#endif
