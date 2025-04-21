/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:31:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 06:18:22 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	abort_exit(t_dict *archive, int *fd, int *pipefd, int code)
{
	if (fd != NULL)
		close_unused_fd(fd);
	if (pipefd != NULL)
		close_unused_fd(pipefd);
	free_matrix(archive->paths);
	exit(code);
}

char	*ft_strdup_pipex(char *str)
{
	int		i;
	int		size;
	char	*new;

	size = 0;
	while (!is_whitespace(str[size]) && !is_quote(str[size]) && str[size])
		size++;
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	new[size] = '\0';
	return (new);
}
