/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 06:29:06 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
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
}			t_range;

typedef struct s_dict
{
	char	**argv;
	char	**envp;
	char	**paths;
}			t_dict;

void		set_stdout(int prev_pipe, t_range i, int pipefd[], int fd[]);
void		setup_execve(char *command, char **paths, char **envp);
void		parent_setup(int pipefd[], int *prev_pipe, int fd[]);
void		pipex(t_range i, int fd[], t_dict *archive);
void		here_doc(t_range *i, int *fd, t_dict *archive);
char		*check_access(char **paths, char *command);
char		*find_path(char **envp);
void		free_matrix(char **matrix);
void		abort_exit(t_dict *archive, int *fd, int *pipefd, int code);

void		initialize_pipex_struct(char **argv, char **envp, t_dict *archive,
				t_range *i);
int			is_quote(char c);
int			is_whitespace(char c);
void		abort_exit(t_dict *archive, int *fd, int *pipefd, int code);
char		*ft_strdup_pipex(char *str);
char		**ft_split_pipex(char *s);
int			count_words(char *str);
void		close_unused_fd(int fd[]);
#endif