/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 18:23:53 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/17 17:54:11 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

int					**ft_init_edges(t_anthill *ant_h, char *line)
{
	int				i;

	i = -1;
	ant_h->edges = (int**)malloc(sizeof(int*) * ant_h->node_nb);
	if (ant_h->edges)
	{
		while (++i < ant_h->node_nb)
		{
			ant_h->edges[i] = (int*)malloc(sizeof(int) * ant_h->node_nb);
			if (!ant_h->edges[i])
				ft_error_room(line, ant_h);
		}
		i = -1;
		while (++i < ant_h->node_nb)
			ft_bzero(ant_h->edges[i], ant_h->node_nb);
	}
	return (ant_h->edges);
}

void				ft_declare_edges(t_anthill *ant_h, char *first)
{
	char			*line;

	if ((ant_h->edges = ft_init_edges(ant_h, first)))
	{
		fill_edges(first, ant_h);
		ft_record(first, ant_h);
		free(first);
		while (get_next_line(&line))
		{
			if (valid_edge(line, ant_h))
				fill_edges(line, ant_h);
			else if (*line == '#')
				continue ;
			else
				break ;
			ft_record(line, ant_h);
			free(line);
		}
		free(line);
	}
	else
		ft_error_room(first, ant_h);
}

int					valid_edge(char *line, t_anthill *ant_h)
{
	char			**names;
	int				i;

	i = 0;
	names = ft_strsplit(line, '-');
	if (names)
	{
		while (names[i])
			++i;
		if (i != 2 || !ft_strcmp(names[0], names[1]) ||
			!name_check(names, ant_h))
		{
			ft_free_room(names);
			return (0);
		}
		else
		{
			ft_free_room(names);
			return (1);
		}
	}
	return (0);
}

int					name_check(char **names, t_anthill *ant_h)
{
	int				i;
	int				nb;

	nb = ant_h->node_nb;
	i = 0;
	while (i < nb && ft_strcmp(names[0], ant_h->node_tab[i]->name))
		++i;
	if (i == nb)
		return (0);
	i = 0;
	while (i < nb && ft_strcmp(names[1], ant_h->node_tab[i]->name))
		++i;
	if (i == nb)
		return (0);
	return (1);
}

void				fill_edges(char *line, t_anthill *ant_h)
{
	char			**names;
	int				count_1;
	int				count_2;

	count_1 = -1;
	count_2 = -1;
	names = ft_strsplit(line, '-');
	if (names)
	{
		while (++count_1 < ant_h->node_nb)
		{
			if (!ft_strcmp(ant_h->node_tab[count_1]->name, names[0]))
				break ;
		}
		while (++count_2 < ant_h->node_nb)
		{
			if (!ft_strcmp(ant_h->node_tab[count_2]->name, names[1]))
				break ;
		}
		ant_h->edges[count_1][count_2] = 1;
		ant_h->edges[count_2][count_1] = 1;
		return ;
	}
	ft_free_room(names);
}

