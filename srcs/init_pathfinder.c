/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pathfinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:41:55 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/22 17:43:38 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

void					init_degrees(t_anthill *ant_h)
{
	int					i;
	int					j;

	i = -1;
	while (++i < ant_h->node_nb)
	{
		j = -1;
		while (++j < ant_h->node_nb)
		{
			if (ant_h->edges && ant_h->edges[i][j])
				++ant_h->node_tab[i]->degree;
		}
	}
	ant_h->node_tab[ant_h->end]->weight = 0;
	ant_h->node_tab[ant_h->end]->available = 0;
	set_weight(ant_h, ant_h->end, 0);
	if (ant_h->node_tab[ant_h->start]->available != -2)
		ft_error(ant_h);
}

void					set_weight(t_anthill *ant_h, int line, int weight)
{
	int					i;

	i = -1;
	while (++i < ant_h->node_nb)
	{
		if (ant_h->edges[line][i] && i != ant_h->end)
		{
			if (i == ant_h->start)
					ant_h->node_tab[i]->available = -2;
			else if (ant_h->node_tab[i]->degree != 1 &&
					 ant_h->node_tab[i]->weight > weight + 1)
			{
				ant_h->node_tab[i]->weight = weight + 1;
				set_weight(ant_h, i, weight + 1);
				ant_h->node_tab[i]->available = 0;
			}
		}
	}
}

int						move_lem(t_anthill *ant_h)
{
	int					antz[ant_h->lem_nb];
	int					i;

	i = -1;
	while (++i < ant_h->lem_nb)
		antz[i] = ant_h->start;
	i = -1;
	while (1)
	{
		while (++i < ant_h->lem_nb)
		{
			if (antz[i] != ant_h->end)
			{
				ft_moveit(ant_h, antz);
				i = -1;
			}
			else if (i == ant_h->lem_nb - 1)
				return (0);
		}
	}
}

int						ft_min_weight(t_anthill *ant_h, int room)
{
	int					i;
	t_queue				min_weight;
	int					queue;

	i = -1;
	min_weight.min = MAX_INT;
	min_weight.degree = 0;
	min_weight.node_id = -1;
	while (++i < ant_h->node_nb)
	{
		if (ant_h->edges[room][i])
		{
			if (i == ant_h->end)
				return (i);
			queue = ant_h->node_tab[i]->weight + ant_h->node_tab[i]->available;
			if (queue < min_weight.min)
				ft_set_min(ant_h, &min_weight, queue, i);
			else if (queue == min_weight.min &&
					 (ant_h->node_tab[i]->degree < min_weight.degree))
				ft_set_min(ant_h, &min_weight, queue, i);
		}
	}
	return (min_weight.node_id);
}

void					ft_error(t_anthill *ant_h)
{
	ft_end_free(ant_h);
	ft_putendl_fd("Error", 2);
	exit(1);
}
