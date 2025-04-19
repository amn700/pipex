/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib <mohchaib@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:50:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/19 03:30:11 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	read_doc_pipe(const char *limiter, int write_fd)
{
	char	*line;
	size_t	n;

	n = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, limiter, n))
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_range *i, int *fd, t_dict *a)
{
	int	p[2];

	i->start = 3;
	i->flag = 1;
	if (pipe(p) < 0)
		return (ft_putstr_fd("Creating Here_doc file failed\n", 2));
	fd[1] = open(a->argv[i->end], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] < 0)
	{
		close(p[0]);
		close(p[1]);
		return (ft_putstr_fd("Creating Here_doc file failed\n", 2));
	}
	read_doc_pipe(a->argv[2], p[1]);
	close(p[1]);
	fd[0] = p[0];
}
