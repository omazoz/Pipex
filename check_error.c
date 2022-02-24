/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:56:12 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/20 16:37:36 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_error(char *cmd)
{
	ft_putstr_fd("error: command not found: ", 2);
	write(2, cmd, ft_strlen(cmd));
	ft_putstr_fd("\n", 2);
	exit(EXIT_SUCCESS);
}

void	error_cmd(char *file)
{
	perror("error");
	write(2, file, ft_strlen(file));
	exit(EXIT_FAILURE);
}

void	error_file(int fd, char *file)
{
	if (fd == 0)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (fd == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (fd == 2)
	{
		perror("Error");
		(void)file;
	}
}
