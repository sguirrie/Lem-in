/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:01:40 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/22 18:29:38 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Lem-in.h>

int					main(void)
{
	char			*line;
	int				nb;
	t_anthill		ant_h;
	int				i, j;

	i = j = 0;
	get_next_line(&line);
	first_line_ok(line, &nb);
	ant_h.lem_nb = nb;
	ant_h.start = -1;
	ant_h.end = -1;
	ant_h.anth_rec = ft_strdup(line);
	ant_h.node_tab = (t_node**)malloc(sizeof(ant_h.node_tab) * NODE_NB);
	ant_h.edges = NULL;
	ft_bzero(ant_h.node_tab, NODE_NB);
	free(line);
	ft_declare_rooms(&ant_h);
	init_degrees(&ant_h);
	ft_disp_anthill(&ant_h);
	move_lem(&ant_h);
	ft_end_free(&ant_h);
	return (0);
}

void				first_line_ok(char *line, int *num)
{
	char			*cl_line;

	cl_line = ft_strtrim(line);
	if (ft_strchr(cl_line, ' ') || ft_strchr(cl_line, '\t') ||
		!ft_isfulldigit(cl_line))
	{
		ft_putstr_fd("init error : first line -> one number only\n", 2);
		free(line);
		free(cl_line);
		exit(1);
	}
	*num = ft_atoi(cl_line);
	if (!(*num))
	{
		ft_putstr_fd("ERROR\n", 2);
		free(line);
		free(cl_line);
		exit(1);
	}
	free(cl_line);
}

int					ft_isfulldigit(char *str)
{
	if (*str == '-')
		++str;
	while (*str)
	{
		if (ft_isdigit(*str))
			++str;
		else
			return (0);
	}
	return (1);
}

void				ft_record(char *line, t_anthill *ant_h)
{
	char			*temp;

	temp = ant_h->anth_rec;
	ant_h->anth_rec = ft_strjoin(ant_h->anth_rec, "\n");
	free(temp);
	temp = ant_h->anth_rec;
	ant_h->anth_rec = ft_strjoin(ant_h->anth_rec, line);
	free(temp);
}

void				ft_disp_anthill(t_anthill *ant_h)
{
	write(1, ant_h->anth_rec, ft_strlen(ant_h->anth_rec));
	write(1, "\n\n", 2);
	free(ant_h->anth_rec);
}
