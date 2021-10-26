/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_env_var_in_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:59:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/26 17:04:00 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_env_var_to_str(t_shell *shell, char *str, char *key)
{
	char	*result;

	result = ft_append_strs(str,
			get_env_var(shell, key), TRUE, TRUE);
	free(key);
	return (result);
}
