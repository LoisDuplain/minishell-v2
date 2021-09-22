/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:36:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/14 13:04:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_prompt(t_shell *shell)
{
	char	*new_prompt;

	new_prompt = ft_calloc(PATH_MAX + 1, sizeof(char));
	if (new_prompt == NULL)
		return ;
	if (getcwd(new_prompt, PATH_MAX) == NULL)
	{
		free(new_prompt);
		return ;
	}
	new_prompt = ft_append_strs("\033[0;34m", new_prompt, FALSE, TRUE);
	new_prompt = ft_append_strs(new_prompt, " \033[0;35m> \033[0m", TRUE, FALSE);
	free(shell->prompt);
	shell->prompt = new_prompt;
}
