/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:35:00 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 15:35:02 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_filler
{
	char		me;
	char		player;
	char		**map;
	int			map_x;
	int			map_y;
	char		**token;
	int			token_x;
	int			token_y;
	int			me_x;
	int			me_y;
	int			result_x;
	int			result_y;
	signed char	move;
}				t_filler;

int				get_map_token(t_filler *t, char *line);

int				my_move(t_filler *t);

int				try_place_token(t_filler *t, int i, int j);

#endif
