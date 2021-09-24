/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_backslash_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:12:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/24 17:15:06 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_backslash_signal(int signal)
{
	(void)signal;
	/* TODO: Handle CTRL + BACKSLASH */
	ft_putstr_nl("CTRL + BACKSLASH (TODO)");
}
