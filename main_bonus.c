/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:14:46 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:17:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_range	i;
	t_dict	archive;
	char	**paths;
	int		fd[2];

	paths = initialize_pipex_struct(argv, envp, &archive, &i);
	i.end = argc - 1;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(&i, fd, argv);
	else
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			return (perror("Input file open failed"), 2);
		fd[1] = open(argv[i.end], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			return (perror("Output file open failed"), 3);
	}
	pipex(i, fd, &archive);
	if (i.flag)
		unlink("here_doc");
	return (close(fd[0]), close(fd[1]), free_matrix(paths), 0);
}
