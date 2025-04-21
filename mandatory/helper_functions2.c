/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:19:45 by mohchaib          #+#    #+#             */
/*   Updated: 2025/04/21 06:12:20 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	return (c == 34 || c == 39);
}

int	is_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	quotes(char *str, int *i, int *count, char type)
{
	int	j;

	j = *i;
	while (str[j] && str[j] != type)
		j++;
	if (str[j] == type)
	{
		j++;
		*i = j;
		(*count)++;
	}
	else
		ft_putstr_fd("closing quote not found\n", 2);
}

void	quotes_check(char *str, int *i, int *count)
{
	if (str[*i] == 39)
	{
		(*i)++;
		quotes(str, i, count, 39);
	}
	else if (str[*i] == 34)
	{
		(*i)++;
		quotes(str, i, count, 34);
	}
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		quotes_check(str, &i, &count);
		if (str[i] && !is_quote(str[i]) && !is_whitespace(str[i]))
			count++;
		while (str[i] && !is_quote(str[i]) && !is_whitespace(str[i]))
			i++;
	}
	return (count);
}
