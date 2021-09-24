/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:59:57 by jcambaki          #+#    #+#             */
/*   Updated: 2021/09/24 16:43:00 by lduplain         ###   ########.fr       */
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
int	main(int argc, char **argv, char **env);

#endif