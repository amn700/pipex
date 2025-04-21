/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:27:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 06:27:24 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_fd(int fd[])
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}

static void	close_all_fd(int fd[], int pipefd[])
{
	close_unused_fd(pipefd);
	close_unused_fd(fd);
}

void	pipex(int fd[], t_dict *archive)
{
	int		status;
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		abort_exit(archive, fd, NULL, 1);
	pid = fork();
	if (pid < 0)
		abort_exit(archive, fd, pipefd, 1);
	else if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_all_fd(fd, pipefd);
		setup_execve(archive->argv[2], archive->paths, archive->envp);
	}
	else
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close_all_fd(fd, pipefd);
		setup_execve(archive->argv[3], archive->paths, archive->envp);
		waitpid(pid, &status, 0);
	}
}
