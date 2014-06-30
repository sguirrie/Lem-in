/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 20:17:44 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/22 18:17:02 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

void			ft_go(t_anthill *ant_h, int min, int i, int room)
{
	if (ant_h->node_tab[min]->available == 0 || min == ant_h->end)
	{
		ant_h->node_tab[room]->available = 0;
		ant_h->node_tab[min]->available = 1;
		ft_putchar('L');
		ft_putnbr(i + 1);
		ft_putchar('-');
		ft_putstr(ant_h->node_tab[min]->name);
		ft_putchar(' ');
	}
	else
		ant_h->node_tab[min]->available += 1;
}

void			ft_set_min(t_anthill *ant_h, t_queue *min, int queue, int id)
{
	min->min = queue;
	min->node_id = id;
	min->degree = ant_h->node_tab[id]->degree;
}

void			ft_end_free(t_anthill *ant_h)
{
	int			i;

	i = -1;
	while (++i < NODE_NB)
		free(ant_h->node_tab[i]);
	free(ant_h->node_tab);
	i = -1;
	while (++i < ant_h->node_nb)
		free(ant_h->edges[i]);
	free(ant_h->edges);
}

void			ft_moveit(t_anthill *ant_h, int antz[])
{
	int					j;
	int					room;
	int					min;

	j = -1;
	while (++j < ant_h->lem_nb)
	{
		if ((room = antz[j]) != ant_h->end)
		{
			min = ft_min_weight(ant_h, antz[j]);
			if (ant_h->node_tab[min]->available == 0 || min == ant_h->end)
				antz[j] = min;
			ft_go(ant_h, min, j, room);
		}
	}
	ft_putstr("\n");
}