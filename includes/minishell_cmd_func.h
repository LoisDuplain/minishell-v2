/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_func.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:11:54 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 14:01:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_FUNC_H
# define MINISHELL_CMD_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create cmd structure.
**	./cmd/create_cmd.c
*/
t_cmd	*create_cmd(size_t index, char **args);

/*
**	Destroy cmd structure.
**	./cmd/destroy_cmd_container.c
*/
void	*destroy_cmd(t_cmd *cmd);

/*
**	Display cmd.
**	./cmd/destroy_cmd_container.c
*/
void	display_cmd(t_cmd *cmd);

#endif