/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:58:01 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/03 06:12:31 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_save(char *save)
{
	char	*new_save;
	char	*newline;

	if (!save)
		return (NULL);
	newline = ft_strchr(save, '\n');
	if (!newline)
	{
		free(save);
		return (NULL);
	}
	if (*(newline + 1) == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = ft_strdup(newline + 1);
	free(save);
	return (new_save);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*rtn;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		++i;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rtn[i] = save[i];
		++i;
	}
	if (save[i] == '\n')
		rtn[i++] = '\n';
	rtn[i] = '\0';
	return (rtn);
}

static char	*ft_read_loop(int fd, char *save, char *temp)
{
	ssize_t	read_rtn;
	char	*buff;

	while (!ft_strchr(save, '\n'))
	{
		read_rtn = read(fd, temp, BUFFER_SIZE);
		if (read_rtn < 0)
		{
			free(save);
			return (NULL);
		}
		if (read_rtn == 0)
			break ;
		temp[read_rtn] = '\0';
		buff = ft_strjoin(save, temp);
		if (!buff)
		{
			free(save);
			return (NULL);
		}
		free(save);
		save = buff;
	}
	return (save);
}

static char	*ft_read(int fd, char *save)
{
	char	*temp;
	char	*new_save;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
	{
		free(save);
		return (NULL);
	}
	if (!save)
	{
		save = ft_strdup("");
		if (!save)
		{
			free(temp);
			return (NULL);
		}
	}
	new_save = ft_read_loop(fd, save, temp);
	free(temp);
	return (new_save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = ft_read(fd, save);
	if (!save || !*save)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
