/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:37 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:54:52 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_error(char *program, char *part1, char *part2)
{
	ft_putstr_err(program);
	ft_putstr_err(": ");
	ft_putstr_err(part1);
	ft_putstr_err(": ");
	ft_putstr_errnl(part2);
}
