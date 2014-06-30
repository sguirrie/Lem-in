/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 18:29:03 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/22 18:32:06 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

int					ft_declare_rooms(t_anthill *ant_h)
{
	char			*line;
	char			**room;
	int				count;

	count = 0;
	while (get_next_line(&line))
	{
		room = valid_rooms(line);
		if (!room && (count == ant_h->start || count == ant_h->end))
			ft_error_room(line, ant_h);
		else if (room)
		{
			ft_record(line, ant_h);
			free(line);
			ant_h->node_tab[count] = ft_create_node(room);
		}
		else if (check_command(line, ant_h, count) || *line == '#')
			continue ;
		else
			break ;
		++count;
	}
	is_edge(ant_h, line, count);
	return (1);
}

char				**valid_rooms(char *line)
{
	char			**room;
	int				i;

	i = 0;
	room = ft_strsplit(line, ' ');
	if (room)
	{
		while (room[i])
			++i;
		if (i == 3 && valid_name(room[0]) && valid_coor(room[1], room[2]))
			return (room);
		ft_free_room(room);
	}
	return (NULL);
}

void				is_edge(t_anthill *ant_h, char *line, int count)
{
	if (ant_h->start == -1 || ant_h->end == -1 || !ant_h->node_tab[0] ||
		!ant_h->node_tab[1])
	{
		ft_putstr("ERROR\n");
		free(line);
		exit(1);
	}
	ant_h->node_nb = count;
	if (valid_edge(line, ant_h))
		ft_declare_edges(ant_h, line);
	else
	{
		ft_putstr("ERROR\n");
		free(line);
		exit(1);
	}
}

int					check_command(char *line, t_anthill *ant_h, int count)
{
	char			*temp;

	temp = ft_strtrim(line);
	if (!ft_strcmp(temp, "##start"))
	{
		free(temp);
		if (ant_h->start == -1)
			ant_h->start = count;
		else
			ft_error_room(line, ant_h);
		ft_record(line, ant_h);
		return (1);
	}
	else if (!ft_strcmp(temp, "##end"))
	{
		free(temp);
		if (ant_h->end == -1)
			ant_h->end = count;
		else
			ft_error_room(line, ant_h);
		ft_record(line, ant_h);
		return (1);
	}
	free(temp);
	return (0);
}

int					ft_error_room(char *line, t_anthill *ant_h)
{
	int				i;

	i = -1;
	while (++i < 2000)
		free(ant_h->node_tab[i]);
	free(ant_h->node_tab);
	line = NULL;
	free(line);
	free(ant_h->anth_rec);
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}
