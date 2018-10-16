/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:36:16 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 15:36:18 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	new token touches only one of my board's peaces
**	and doesn't touch any of the opponent's peaces
*/

static int		can_place_it(t_filler *t, int y, int x)
{
	int		match;
	int		yy;
	int		xx;

	match = 0;
	yy = 0;
	while (yy < t->token_y)
	{
		xx = 0;
		while (xx < t->token_x)
		{
			if ((t->map[yy + y][xx + x] == t->me)
					&& t->token[yy][xx] == '*')
				match++;
			else if ((t->map[yy + y][xx + x] == t->player)
					&& t->token[yy][xx] == '*')
				return (0);
			xx++;
		}
		yy++;
	}
	if (match == 1)
		return (1);
	return (0);
}

int				try_place_token(t_filler *t, int y, int x)
{
	if (y + t->token_y > t->map_y)
		return (0);
	else if (x + t->token_x > t->map_x)
		return (0);
	else
		return (can_place_it(t, y, x));
}
