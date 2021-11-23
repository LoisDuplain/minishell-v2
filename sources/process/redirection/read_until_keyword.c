/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_keyword.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:21:27 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 13:48:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	read_until_keyword(char *keyword)
{
	int		file_fd;
	char	*line;

	file_fd = open("read_until_buffer", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_fd == -1)
		return (put_error("minishell", "file", "can't open buffer"));
	while (1)
	{
		line = readline("\033[0;31m>\033[0m ");
		if (line == NULL || ft_strcmp(line, keyword) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fdnl(file_fd, line);
		free(line);
	}
	close(file_fd);
	return (TRUE);
}
