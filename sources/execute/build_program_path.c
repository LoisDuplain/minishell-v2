/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:28:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:36:10 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_program_path(char *path, char *program)
{
	return (ft_append_strs(path,
			ft_append_strs("/", program, FALSE, FALSE), FALSE, TRUE));
}
