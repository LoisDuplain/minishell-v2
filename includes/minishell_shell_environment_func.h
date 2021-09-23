/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shell_environment_func.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:51:53 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 22:52:46 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SHELL_ENVIRONMENT_FUNC_H
# define MINISHELL_SHELL_ENVIRONMENT_FUNC_H

/*
**	START CUSTOM INCLUDES
*/

# include "minishell.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Create new string array containing the default environment string array.
**	./shell/environment/create_env.c
*/
char	**create_env(char **default_env);

/*
**	Display envrionment string array.
**	./shell/environment/display_env.c
*/
void	display_env(t_shell *shell);

/*
**	Get environment string array size.
**	./shell/environment/get_env_length.c
*/
size_t	get_env_length(t_shell *shell);

/*
**	Get environment variable value by environment key in environment string array.
**	./shell/environment/get_env_value.c
*/
char	*get_env_var(t_shell *shell, char *key);

/*
**	Check if environment string array contains key.
**	./shell/environment/env_var_exists.c
*/
t_bool	env_var_exists(t_shell *shell, char *key);

#endif
