/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:59:57 by jcambaki          #+#    #+#             */
/*   Updated: 2021/11/03 15:57:02 by lduplain         ###   ########.fr       */
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

# include "minishell_shell_struct.h"
# include "minishell_cmd_builder_struct.h"

# include "minishell_process_execute_func.h"
# include "minishell_builtin_func.h"
# include "minishell_process_func.h"
# include "minishell_cmd_builder_func.h"
# include "minishell_parser_func.h"
# include "minishell_signal_func.h"
# include "minishell_shell_func.h"
# include "minishell_shell_environment_func.h"

/*
**  END CUSTOM INCLUDES	
*/

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
void	put_error(char *program, char *part1, char *part2);

#endif