/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_keyword.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:21:27 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 14:08:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_until_keyword_behavior(char *keyword, int file_fd)
{
	char	*line;

	signal(SIGINT, NULL);
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
	exit(0);
}

t_bool	read_until_keyword(char *keyword)
{
	pid_t	pid;
	int		file_fd;
	int		status;

	file_fd = open("read_until_buffer", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_fd == -1)
		return (put_error("minishell", "file", "can't open buffer"));
	pid = fork();
	if (pid == -1)
		put_error("minishell", "fork error", strerror(errno));
	else if (pid == 0)
		read_until_keyword_behavior(keyword, file_fd);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
			return (FALSE);
		close(file_fd);
	}
	return (TRUE);
}
