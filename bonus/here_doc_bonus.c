/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib <mohchaib@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:50:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/19 02:59:05 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	read_doc(char *limitter, int fd[])
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limitter, ft_strlen(limitter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd[0], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_range *i, int fd[], t_dict *archive)
{
	i->start = 3;
	i->flag = 1;
	unlink("here_doc");
	fd[0] = open("here_doc", O_WRONLY | O_CREAT, 0644);
	if (fd[0] < 0)
		ft_putstr_fd("Creating Here_doc file failed\n", 2);
	fd[1] = open(archive->argv[i->end], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] < 0)
		return (ft_putstr_fd("Opening output file failed\n", 2),
			free_matrix(archive->paths), close(fd[0]), exit(1));
	read_doc(archive->argv[2], fd);
	close(fd[0]);
	fd[0] = open("here_doc", O_RDONLY);
	if (fd[0] < 0)
		ft_putstr_fd("Creating Here_doc file failed\n", 2);
}
