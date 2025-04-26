/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:51:22 by mohchaib          #+#    #+#             */
/*   Updated: 2025/04/26 09:42:32 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	set_stdout(int prev_pipe, t_range i, int pipefd[], int fd[])
{
	if (prev_pipe < 0 || (fd[1] < 0 && i.start == i.end -1))
		return ;
	dup2(prev_pipe, STDIN_FILENO);
	if (i.start < i.end - 1)
		dup2(pipefd[1], STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	close_unused_fd(fd);
	close_unused_fd(pipefd);
}

void	setup_execve(char *command, char **paths, char **envp)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split_pipex(command);
	if (!cmd)
		return (free_matrix(paths), exit(1));
	else if (!cmd[0])
		return (ft_putstr_fd("empty command\n", 2), free_matrix(paths),
			free_matrix(cmd), exit(1));
	file_path = check_access(paths, cmd[0]);
	if (!file_path)
		return (ft_putstr_fd("command not found\n", 2), free_matrix(paths),
			free_matrix(cmd), exit(1));
	if (execve(file_path, cmd, envp) == -1)
		return (ft_putstr_fd("execve failed\n", 2), free_matrix(paths),
			free_matrix(cmd), free(file_path), exit(1));
}

void	parent_setup(int pipefd[], int *prev_pipe, int fd[])
{
	close(pipefd[1]);
	if (*prev_pipe != fd[0])
		close(*prev_pipe);
	*prev_pipe = pipefd[0];
}

void	initialize_pipex_struct(char **argv, char **envp, t_dict *archive,
		t_range *i)
{
	char	**paths;

	i->start = 2;
	paths = ft_split(find_path(envp), ':');
	if (!paths)
		return (ft_putstr_fd("Memory allocation failed\n", 2), exit(1));
	archive->argv = argv;
	archive->envp = envp;
	archive->paths = paths;
}
