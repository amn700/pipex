/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:31:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/12 16:00:26 by amn              ###   ########.fr       */
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

void close_unused_fd(int fd[])
{
    close(fd[0]);
    close(fd[1]);
}
