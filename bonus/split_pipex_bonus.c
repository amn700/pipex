/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:19:06 by mohchaib          #+#    #+#             */
/*   Updated: 2025/04/21 06:25:02 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_matrix_abort(char **matrix, int i)
{
	while (i >= 0)
		free(matrix[i--]);
	free(matrix);
}

int	quote_pipex(char **str, char **matrix, char type, int i)
{
	int	j;

	j = 0;
	while ((*str)[j] && (*str)[j] != type)
		j++;
	if ((*str)[j] == type)
	{
		matrix[i] = ft_substr(*str, 0, j);
		if (!matrix[i])
		{
			free_matrix_abort(matrix, i - 1);
			ft_putstr_fd("allocation error\n", 2);
			return (0);
		}
		j++;
		(*str) += j;
	}
	else
	{
		free_matrix_abort(matrix, i);
		ft_putstr_fd("closing quote not found\n", 2);
		return (0);
	}
	return (1);
}

int	quotes_check_alloc(char **str, char **matrix, int *i)
{
	if (**str == 39)
	{
		(*str)++;
		if (!quote_pipex(str, matrix, 39, *i))
			return (0);
		(*i)++;
	}
	else if (**str == 34)
	{
		(*str)++;
		if (!quote_pipex(str, matrix, 34, *i))
			return (0);
		(*i)++;
	}
	return (1);
}

char	**fill_matrix(char **matrix, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && is_whitespace(*str))
			str++;
		if (!quotes_check_alloc(&str, matrix, &i))
			return (NULL);
		if (*str && !is_quote(*str) && !is_whitespace(*str))
		{
			matrix[i] = ft_strdup_pipex(str);
			if (!matrix[i])
			{
				free_matrix_abort(matrix, i - 1);
				ft_putstr_fd("allocation error\n", 2);
				return (NULL);
			}
			i++;
		}
		while (*str && !is_quote(*str) && !is_whitespace(*str))
			str++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**ft_split_pipex(char *s)
{
	char	**matrix;
	int		len;

	len = count_words((char *)s);
	matrix = malloc(sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	if (!fill_matrix(matrix, (char *)s))
		return (NULL);
	return (matrix);
}
