/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:39:26 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/21 13:19:40 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_1(char **argv, char **envp, int *p)
{
	int		filein;

	filein = open_file(argv[1], 2);
	if (filein == -1)
		error_file(2, argv[1]);
	dup2(p[WRITE_END], STDOUT_FILENO);
	close(p[WRITE_END]);
	dup2(filein, STDIN_FILENO);
	close(p[READ_END]);
	execute(argv[2], envp);
}

/* i used this fuction (Child )that run inside a fork, 
 * take the filein, put the output inside
 a pipe and then close with the exec function */

void	parent_process(char **argv, char **envp, int *p)
{
	int		fileout;

	fileout = open_file(argv[4], 1);
	if (fileout == -1)
		error_file(-1, argv[4]);
	dup2(p[READ_END], STDIN_FILENO);
	close(p[READ_END]);
	dup2(fileout, STDOUT_FILENO);
	close(p[WRITE_END]);
	execute(argv[3], envp);
}

/*i used this function (Parent) that take the data from the pipe,
  * * change the output for the
 fileout and also close with the exec function */

int	main(int argc, char **argv, char **envp)
{
	int	p[2];
	int	pid1;

	if (!envp[0])
		return (write(1, "Envirement unavailable\n",
				ft_strlen("Envirement unavailable\n")), -1);
	if (argc == 5)
	{
		if (pipe(p) == -1)
			error_file(0, NULL);
		pid1 = fork();
		if (pid1 == -1)
			error_file(0, NULL);
		if (pid1 == 0)
			child_process_1(argv, envp, p);
		else
			parent_process(argv, envp, p);
		waitpid(pid1, NULL, 0);
	}
	else
		write (2, "invalid number of argements\n", 28);
	return (0);
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong  waitpid(pid1, NULL, 0)aftr else*/
