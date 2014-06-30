/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:01:40 by sguirrie          #+#    #+#             */
/*   Updated: 2014/03/22 17:36:54 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <libft.h>

# define BUFF_SIZE 32
# define MAX_INT 2147483647
# define NODE_NB 2000

typedef struct			s_node
{
	char				*name;
	int					x;
	int					y;
	int					weight;
	int					degree;
	int					available;
}						t_node;

typedef struct			s_anthill
{
	int					lem_nb;
	int					node_nb;
	int					start;
	int					end;
	t_node				**node_tab;
	int					**edges;
	char				*anth_rec;
}						t_anthill;

typedef struct			s_queue
{
	int					min;
	int					node_id;
	int					degree;
}						t_queue;
/*
** function prototypes
*/

int				name_check(char **names, t_anthill *ant_h);
int				valid_edge(char *line, t_anthill *ant_h);
int				get_next_line(char **line);
void			first_line_ok(char *line, int *num);
int				ft_isfulldigit(char *str);
int				ft_declare_rooms(t_anthill *ant_h);
char			**valid_rooms(char *line);
t_node			*ft_create_node(char **room);
int				valid_name(char *name);
int				valid_coor(char *x, char *y);
void			ft_declare_edges(t_anthill *ant_h, char *first);
void			fill_edges(char *line, t_anthill *ant_h);
int				**ft_init_edges(t_anthill *ant_h, char *line);
void			is_edge(t_anthill *ant_h, char *line, int count);
void			ft_record(char *line, t_anthill *ant_h);
void			ft_disp_anthill(t_anthill *ant_h);
void			init_degrees(t_anthill *ant_h);
void			set_weight(t_anthill *ant_h, int line, int weight);
int				ft_min_weight(t_anthill *ant_h, int room);
int				move_lem(t_anthill *ant_h);
int				check_command(char *line, t_anthill *ant_h, int count);
void			ft_free_room(char **room);
int				ft_error_room(char *line, t_anthill *ant_h);
void			ft_set_min(t_anthill *ant_h, t_queue *min, int queue, int id);
void			ft_go(t_anthill *ant_h, int min, int i, int room);
void			ft_end_free(t_anthill *ant_h);
void			ft_error(t_anthill *ant_h);
void			ft_moveit(t_anthill *ant_h, int antz[]);

#endif /* !LEM_IN_H */
