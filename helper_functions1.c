/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:32:04 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:15:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_stdout(int prev_pipe, t_range i, int pipefd[], int fd[])
{
	dup2(prev_pipe, STDIN_FILENO);
	if (i.start < i.end - 1)
		dup2(pipefd[1], STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	close(pipefd[0]);
}

void	setup_execve(char *command, char **paths, char **envp)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split(command, ' ');
	if (!cmd)
		exit(1);
	else if (!cmd[0])
	{
		perror("empty command");
		exit(1);
	}
	file_path = check_access(paths, cmd[0]);
	if (!file_path)
	{
		perror("Command not found");
		exit(1);
	}
	execve(file_path, cmd, envp);
	free(file_path);
	free_matrix(cmd);
	perror("execve failed");
	exit(1);
}

void	parent_stup(int pipefd[], int *prev_pipe, int fd[], pid_t pid)
{
	int	status;

	close(pipefd[1]);
	if (*prev_pipe != fd[0])
		close(*prev_pipe);
	*prev_pipe = pipefd[0];
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
}

char	**initialize_pipex_struct(char **argv, char **envp, t_dict *archive,
		t_range *i)
{
	char	**paths;

	i->flag = 0;
	i->start = 2;
	paths = ft_split(find_path(envp), ':');
	if (!paths)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	archive->argv = argv;
	archive->envp = envp;
	archive->paths = paths;
	return (paths);
}
