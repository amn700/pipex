/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:27:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/22 23:37:53 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
			abort_exit(archive, fd, pipefd, 1);
		pid = fork();
		if (pid < 0)
			abort_exit(archive, fd, pipefd, 1);
		else if (pid == 0)
		{
			set_stdout(prev_pipe, i, pipefd, fd);
			setup_execve(archive->argv[i.start], archive->paths, archive->envp);
		}
		else
			parent_setup(pipefd, &prev_pipe, fd);
		i.start++;
	}
	while (wait(&status) > 0)
		;
}
