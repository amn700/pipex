/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:31:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/28 08:15:08 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*copy(char *new, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = '/';
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new);
}

char	*ft_strjoin_pipex(char const *s1, char const *s2)
{
	int		size;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	new[size] = 0;
	return (copy(new, (char *)s1, (char *)s2));
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*check_access(char **paths, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
	{
		path = ft_strdup(cmd);
		if (!path)
			return (NULL);
		return (path);
	}
	while (paths[i])
	{
		path = ft_strjoin_pipex(paths[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
