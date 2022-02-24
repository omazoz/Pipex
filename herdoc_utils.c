/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:38:43 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/21 15:40:56 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	optimize(int pid, int p[2])
{
	waitpid(pid, NULL, 0);
	close(p[READ_END]);
	exit(1);
}

void	join_free(char **buff, char **line)
{
	*buff = ft_strjoin(*buff, *line);
	free(*line);
}

void	mini_optimize(int argc, int p[2])
{
	if (argc < 5)
		error_cmd(": To few arguments");
	if (pipe(p) == -1)
		error_file(0, NULL);
}

void	write_get(char **line)
{
	write(1, "here_doc> ", 10);
	*line = get_next_line(0);
}
