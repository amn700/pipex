/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:27:40 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_range i, int fd[], t_dict *archive)
{
	int		status;
	int		prev_pipe;
	pid_t	pid;
	int		pipefd[2];

	prev_pipe = fd[0];
	while (i.start < i.end)
	{
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
		{
			set_stdout(prev_pipe, i, pipefd, fd);
			setup_execve(archive->argv[i.start], archive->paths, archive->envp);
		}
		else
			parent_stup(pipefd, &prev_pipe, fd, pid);
		i.start++;
	}
	close(prev_pipe);
	while (wait(&status) > 0)
		;
}
