/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_builtin_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:48:35 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/04 17:50:34 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_builtin_error(char *builtin, char *content, char *error)
{
	ft_putstr_err(builtin);
	ft_putstr_err(": ");
	ft_putstr_err(content);
	ft_putstr_err(": ");
	ft_putstr_errnl(error);
}
