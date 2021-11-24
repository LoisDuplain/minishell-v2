/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_backslash_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:12:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 10:25:23 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* TODO: Handle CTRL + BACKSLASH */
void	ctrl_backslash_signal(int signal)
{
	(void)signal;
	ft_putstr_nl("CTRL + BACKSLASH (TODO)");
}
