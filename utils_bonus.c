/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:23:15 by omazoz            #+#    #+#             */
/*   Updated: 2022/01/21 13:31:09 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char *) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int		i;
	char	line[8000000];
	char	buffer[1];

	i = 0;
	ft_bzero(line, 8000000);
	while (read(fd, buffer, 1) > 0)
	{
		line[i++] = buffer[0];
		if (buffer[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
