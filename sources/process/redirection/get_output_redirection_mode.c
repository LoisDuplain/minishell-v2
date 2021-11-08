/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_redirection_mode.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:11:52 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 12:12:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_output_redirection_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
}
