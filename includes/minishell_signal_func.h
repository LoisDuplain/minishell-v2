/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal_func.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:41:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/24 17:15:45 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNAL_FUNC_H
# define MINISHELL_SIGNAL_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Handle CTRL + C signal.
**	./shell/ctrl_c_signal.c
*/
void	ctrl_c_signal(int signal);

/*
**	Handle CTRL + BACKSLASH signal.
**	./shell/ctrl_backslash_signal.c
*/
void	ctrl_backslash_signal(int signal);

#endif
