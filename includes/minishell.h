/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:59:57 by jcambaki          #+#    #+#             */
/*   Updated: 2021/11/24 19:07:23 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**  START DEFINES
*/

# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif

# ifndef READLINE_PATH
#  define READLINE_PATH "/usr/local/opt/readline/include/readline/readline.h"
# endif

# ifndef HISTORY_PATH
#  define HISTORY_PATH "/usr/local/opt/readline/include/readline/history.h"
# endif

/*
**  END DEFINES
*/

/*
**  START STANDARD INCLUDES	
*/

# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

/*
**  END STANDARD INCLUDES	
*/

/*
**  START CUSTOM INCLUDES	
*/

# include "../libft/libft.h"
# include READLINE_PATH
# include HISTORY_PATH

# include "minishell_cmd_struct.h"
# include "minishell_cmd_container_struct.h"
# include "minishell_shell_struct.h"

# include "minishell_cmd_func.h"
# include "minishell_cmd_container_func.h"
# include "minishell_process_piped_func.h"
# include "minishell_process_redirection_func.h"
# include "minishell_execute_func.h"
# include "minishell_builtin_func.h"
# include "minishell_process_func.h"
# include "minishell_tokenizer_func.h"
# include "minishell_signal_func.h"
# include "minishell_shell_func.h"
# include "minishell_shell_environment_func.h"

/*
**  END CUSTOM INCLUDES	
*/

t_shell	*g_shell;

/*
**  Main function.
**  ./main.c
*/
int		main(int argc, char **argv, char **env);

/*
**  Hard exit.
**  ./exit_shell.c
*/
void	exit_shell(t_shell *shell, char *message);

/*
**	Print an error.
**  ./put_error.c
*/
t_bool	put_error(char *program, char *part1, char *part2);

#endif