/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:04 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:13:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_range
{
	int		start;
	int		end;
	int		flag;
}			t_range;

typedef struct s_dict
{
	char	**argv;
	char	**envp;
	char	**paths;
}			t_dict;

void		set_stdout(int prev_pipe, t_range i, int pipefd[], int fd[]);
void		setup_execve(char *command, char **paths, char **envp);
void		parent_stup(int pipefd[], int *prev_pipe, int fd[], pid_t pid);
void		pipex(t_range i, int fd[], t_dict *archive);
void		read_doc(char *limitter, int fd[]);
void		here_doc(t_range *i, int fd[], char **argv);
char		*check_access(char **paths, char *command);
char		*find_path(char **envp);
char		**initialize_pipex_struct(char **argv, char **envp, t_dict *archive,
				t_range *i);
void		free_matrix(char **matrix);

#endif