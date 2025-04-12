/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib <mohchaib@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:32:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/12 17:46:22 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_execve(char *command, char **paths, char **envp)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split_pipex(command);
	if (!cmd)
		return (ft_putstr_fd("allocation error\n", 2),
			free_matrix(paths), exit(1));
	else if (!cmd[0])
		return (ft_putstr_fd("empty command\n", 2),
			free_matrix(paths), free_matrix(cmd),  exit(1));
	file_path = check_access(paths, cmd[0]);
	if (!file_path)
		return (ft_putstr_fd("command not found\n", 2),
			free_matrix(paths), free_matrix(cmd),  exit(1));
	if (execve(file_path, cmd, envp) == -1)
		return (ft_putstr_fd("execve failed\n", 2),
			free_matrix(paths), free_matrix(cmd), free(file_path), exit(1));
}

void initialize_pipex_struct(char **argv, char **envp, t_dict *archive)
{
	char	**paths;
	
	paths = ft_split(find_path(envp), ':');
	if (!paths)
		return (ft_putstr_fd("execve failed\n", 2), exit(1));
	archive->argv = argv;
	archive->envp = envp;
	archive->paths = paths;
}
