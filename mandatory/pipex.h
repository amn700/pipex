/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib <mohchaib@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:04 by marvin            #+#    #+#             */
/*   Updated: 2025/04/12 19:15:46 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
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

int			is_quote(char c);
int			is_whitespace(char c);
void		quotes(char *str, int *i, int *count, char type);
void		quotes_check(char *str, int *i, int *count);
int			count_words(char *str);
char		*ft_strdup_pipex(char *s);
char		**ft_split_pipex(char *str);
int			quote_pipex(char **str, char **matrix, char type, int i);
int			quotes_check_alloc(char **str, char **matrix, int *i);
char		**fill_matrix(char **matrix, char *str);
void		free_matrix(char **matrix);
void		here_doc(t_range *i, int fd[], char **argv);
void		read_doc(char *limitter, int fd[]);
void		set_stdout(int prev_pipe, t_range i, int pipefd[], int fd[]);
void		setup_execve(char *cmd, char **paths, char **envp);
void		pipex(int fd[], t_dict *archive);
char		*ft_strjoin_pipex(char const *s1, char const *s2);
char		*find_path(char **envp);
char		*ft_strjoin_pipex(char const *s1, char const *s2);
char		*find_path(char **envp);
char		*check_access(char **paths, char *cmd);
void		free_matrix(char **matrix);
int			count_words(char *str);
void		initialize_pipex_struct(char **argv, char **envp, t_dict *archive);
void		abort_exit(t_dict *archive, int *fd, int *pipefd, int code);
void		close_unused_fd(int fd[]);
char		*ft_strdup_pipex(char *str);

#endif