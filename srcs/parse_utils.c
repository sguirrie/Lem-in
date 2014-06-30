/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:18:36 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/17 19:51:49 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

t_node				*ft_create_node(char **room)
{
	t_node			*node;

	node = (t_node*)malloc(sizeof(*node));
	if (node)
	{
		node->name = room[0];
		node->weight = MAX_INT;
		node->x = ft_atoi(room[1]);
		node->y = ft_atoi(room[2]);
		node->degree = 0;
		node->available = -1;
	}
	ft_free_room(room);
	return (node);
}

int					valid_name(char *name)
{
	if (*name == 'L' || *name == '#')
		return (0);
	while (*name)
	{
		if (*name > 32 && *name <= 126)
			++name;
		else
			return (0);
	}
	return (1);
}

int					valid_coor(char *x, char *y)
{
	if (ft_isfulldigit(x) && ft_isfulldigit(y))
		return (1);
	else
		return (0);
}

void				ft_free_room(char **room)
{
	int				i;

	i = -1;
	while (room[++i])
	{
		room[i] = NULL;
		free(room[i]);
	}
	room = NULL;
	free(room);
}
