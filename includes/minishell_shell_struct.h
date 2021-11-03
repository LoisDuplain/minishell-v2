/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shell_struct.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:35:45 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 16:53:51 by lduplain         ###   ########.fr       */
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
	int		pipe[2];
	int		fd_backup;
	int		fd_replaced;
}	t_shell;

/*
**  END DEFINES
*/

#endif
