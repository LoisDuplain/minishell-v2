/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exists_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:30:25 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:36:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	program_exists_at(char *path, char *program)
{
	char		*full_path;
	struct stat	buffer;
	t_bool		result;

	if (path == NULL)
		full_path = program;
	else
		full_path = build_program_path(path, program);
	result = stat(full_path, &buffer) == 0;
	if (path != NULL)
		free(full_path);
	return (result);
}
