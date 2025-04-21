/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:14:46 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 06:00:17 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	abort_exit(t_dict *archive, int *fd, int *pipefd, int code)
{
	if (fd != NULL)
		close_unused_fd(fd);
	if (pipefd != NULL)
		close_unused_fd(pipefd);
	free_matrix(archive->paths);
	exit(code);
}

int	main(int argc, char **argv, char **envp)
{
	t_range	i;
	t_dict	archive;
	int		fd[2];

	initialize_pipex_struct(argv, envp, &archive, &i);
	i.end = argc - 1;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(&i, fd, &archive);
	else
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_putstr_fd("Opening input file failed\n", 2);
		fd[1] = open(argv[i.end], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			return (ft_putstr_fd("Opening output file failed\n", 2),
				free_matrix(archive.paths), close(fd[0]), exit(1), 1);
	}
	pipex(i, fd, &archive);
	abort_exit(&archive, fd, NULL, 0);
}
