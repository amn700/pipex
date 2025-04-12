/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib <mohchaib@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:51:30 by mohchaib          #+#    #+#             */
/*   Updated: 2025/04/12 18:31:38 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_dict	archive;
	int		fd[2];

	if (argc != 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 1);
	initialize_pipex_struct(argv, envp, &archive);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		ft_putstr_fd("Opening input file failed\n", 2);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		return (ft_putstr_fd("Opening output file failed\n", 2),
			free_matrix(archive.paths), close(fd[0]), exit(1), 1);
	pipex(fd, &archive);
	abort_exit(&archive, fd, NULL, 0);
}
