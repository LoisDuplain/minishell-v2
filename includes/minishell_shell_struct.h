/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shell_struct.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:35:45 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/28 13:03:56 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SHELL_STRUCT_H
# define MINISHELL_SHELL_STRUCT_H

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

typedef struct s_shell
{
	char	**env;
	char	*prompt;
	char	*line;
	char	**cmd;
}	t_shell;

/*
**  END DEFINES
*/

#endif
