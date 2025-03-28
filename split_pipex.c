/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:19:06 by mohchaib          #+#    #+#             */
/*   Updated: 2025/03/20 20:09:59 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	quote_pipex(char **str, char **matrix, char type, int i)
{
	int	j;

	j = 0;
	while ((*str)[j] && (*str)[j] != type)
		j++;
	if ((*str)[j] == type)
	{
		matrix[i] = ft_substr(*str, 0, j);
		j++;
		(*str) += j;
	}
	else
	{
		perror("closing quote not found !!");
		exit(1);
	}
}

void	quotes_check_alloc(char **str, char **matrix, int *i)
{
	if (**str == 39)
	{
		(*str)++;
		quote_pipex(str, matrix, 39, *i);
		(*i)++;
	}
	else if (**str == 34)
	{
		(*str)++;
		quote_pipex(str, matrix, 34, *i);
		(*i)++;
	}
}

char	**fill_matrix(char **matrix, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && is_whitespace(*str))
			str++;
		quotes_check_alloc(&str, matrix, &i);
		if (*str && !is_quote(*str) && !is_whitespace(*str))
			matrix[i++] = ft_strdup_pipex(str);
		while (*str && !is_quote(*str) && !is_whitespace(*str))
			str++;
	}
	matrix[i] = NULL;
	return (matrix);
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
	if (new == NULL)
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
