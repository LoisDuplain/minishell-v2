/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_container_func.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:27:16 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:49:01 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_CONTAINER_FUNC_H
# define MINISHELL_CMD_CONTAINER_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Init cmd_container structure.
**	./cmd_container/init_cmd_container.c
*/
void	init_cmd_container(t_cmd_container *cmd_container);

/*
**	Destroy/reset cmd_container structure.
**	./cmd_container/destroy_cmd_container.c
*/
void	*destroy_cmd_container(t_cmd_container *cmd_container);

/*
**	Get the size of the cmds t_cmd array.
**	./cmd_container/get_cmds_size.c
*/
size_t	get_cmds_size(t_cmd_container *cmd_container);

/*
**	Append cmds with current cmd and set next to null.
**	./cmd_container/next_cmd.c
*/
void	next_cmd(t_cmd_container *cmd_container);

/*
**	Add a t_cmd slot in cmd_container->cmds array.
**	./cmd_container/realloc_cmds.c
*/
t_cmd	**realloc_cmds(t_cmd_container *cmd_container);

/*
**	Append current cmd with current next part and set next to null.
**	./cmd_container/next_cmd_part.c
*/
void	next_cmd_part(t_cmd_container *cmd_container);

/*
**	Display cmd container.
**	./cmd_container/display_cmd_container.c
*/
void	display_cmd_container(t_cmd_container *cmd_container);

#endif