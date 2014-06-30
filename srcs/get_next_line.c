/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 19:07:50 by sguirrie          #+#    #+#             */
/*   Updated: 2014/02/21 17:44:30 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>
#include <libft.h>

static int			ft_buff_read(char *buff, char **line)
{
	char			*temp;
	char			*remain;

	temp = *line;
	remain = ft_strchr(buff, '\n');
	if (remain == NULL)
	{
		*line = ft_strjoin(*line, buff);
		if (temp != NULL && *line == NULL)
			free(temp);
		return (0);
	}
	else
	{
		*line = ft_strjoin(*line, ft_strsub(buff, 0, (remain - buff)));
		if (temp != NULL)
			free(temp);
		return (1);
	}
}

static int			ft_cue(char **cue, char *buff, char **line)
{
	if (cue && *cue)
	{
		if (ft_strchr(buff, '\n'))
			*cue = ft_strchr(buff, '\n') + 1;
	}
	if (ft_buff_read(*cue, line) == 1)
	{
		ft_strncpy(buff, *cue, BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

int					get_next_line(char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;
	char			*cue;

	*line = ft_strnew(1);
	ft_bzero(*line, 1);
	if (buff[0] != '\0')
	{
		if (ft_cue(&cue, buff, line))
			return (1);
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (ft_buff_read(buff, line) == 1)
			return (1);
	}
	if (*line[0] != '\0')
		return (1);
	return (0);
}
