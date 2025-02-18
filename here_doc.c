/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:50:26 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:16:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	here_doc(t_range *i, int fd[], char **argv)
{
	i->start = 3;
	i->flag = 1;
	unlink("here_doc");
	fd[0] = open("here_doc", O_WRONLY | O_CREAT, 0644);
	if (fd[0] < 0)
	{
		perror("Here_doc file open failed");
		exit(2);
	}
	fd[1] = open(argv[i->end], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] < 0)
	{
		perror("Output file open failed");
		exit(2);
	}
	read_doc(argv[2], fd);
	close(fd[0]);
	fd[0] = open("here_doc", O_RDONLY);
	if (fd[0] < 0)
	{
		perror("Here_doc file open failed");
		exit(2);
	}
}
