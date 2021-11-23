/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:23:13 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 14:23:21 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_program_path(t_shell *shell, char *program)
{
	char	*path_env_var;
	char	**splitted_path;
	size_t	index;
	char	*result;

	path_env_var = get_env_var(shell, "PATH");
	if (path_env_var == NULL)
		return (NULL);
	splitted_path = ft_split(path_env_var, ":");
	free(path_env_var);
	if (splitted_path == NULL)
		return (NULL);
	index = 0;
	while (splitted_path[index] != NULL)
	{
		if (program_exists_at(splitted_path[index], program))
		{
			result = build_program_path(splitted_path[index], program);
			ft_destroy_splitted(&splitted_path);
			return (result);
		}
		index++;
	}
	ft_destroy_splitted(&splitted_path);
	return (NULL);
}
