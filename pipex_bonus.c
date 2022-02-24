/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:39:26 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/21 16:48:52 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process that create a fork and a pipe, put the output inside a pipe
   and then close with the exec function. The main process will change his stdin
   for the pipe file descriptor. */
void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		error_file(0, NULL);
	pid = fork();
	if (pid == -1)
		error_file(0, NULL);
	if (pid == 0)
	{
		close(p[READ_END]);
		dup2(p[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/*Function  make a child process that will read from the stdin with
  get_next_line until finding the limiter  and then put the output inside a
  pipe */

void	here_doc(char *limiter, int argc, char **argv, int fd2)
{
	int		p[2];
	char	*line;
	char	*buff;
	int		pid;

	mini_optimize(argc, p);
	pid = fork();
	if (pid == 0)
	{
		buff = (char *)malloc(ft_strlen(line));
		while (1)
		{
			write_get(&line);
			if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
			{
				fd2 = open_file(argv[argc - 1], 1);
				write(fd2, buff, ft_strlen(buff));
				free(line);
				break ;
			}
			join_free(&buff, &line);
		}
		free(buff);
	}
	optimize(pid, p);
}

/* Main function that run the childs process with the right file descriptor
   or display an error message if arguments are wrong. It will run here_doc
   function if the "here_doc" string is find in argv[1]*/

void	cmd(int cmd_count, char **argv, char **envp, int i)
{
	while (cmd_count - 1)
	{
		child_process(argv[i++], envp);
		cmd_count--;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fileout;
	int	cmd_count;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			cmd_count = argc - 4;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc, argv, 0);
		}
		else
		{
			i = 2;
			cmd_count = argc - 3;
			fileout = open_file(argv[argc - 1], 1);
			dup2(open_file(argv[1], 2), STDIN_FILENO);
		}
		cmd(cmd_count, argv, envp, i);
		dup2(fileout, 1);
		return (execute(argv[argc - 2], envp));
	}
	arg_error(argv[0]);
}
