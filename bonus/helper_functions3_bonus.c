/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:56:50 by mohchaib          #+#    #+#             */
/*   Updated: 2025/04/22 23:21:54 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_unused_fd(int fd[])
{
	close(fd[0]);
	close(fd[1]);
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
