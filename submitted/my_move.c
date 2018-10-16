/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:36:07 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 15:36:08 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		up_right(t_filler *t)
{
	int		y;
	int		x;

	y = 0;
	while (y < t->map_y)
	{
		x = t->map_x;
		while (x > 0)
		{
			if (try_place_token(t, y, x))
			{
				t->result_x = x;
				t->result_y = y;
				return (1);
			}
			x--;
		}
		y++;
	}
	return (0);
}

static int		down_right(t_filler *t)
{
	int		y;
	int		x;

	y = t->map_y;
	while (y > 0)
	{
		x = t->map_x;
		while (x > 0)
		{
			if (try_place_token(t, y, x))
			{
				t->result_x = x;
				t->result_y = y;
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static int		up_left(t_filler *t)
{
	int		y;
	int		x;

	y = 0;
	while (y < t->map_y)
	{
		x = 0;
		while (x < t->map_x)
		{
			if (try_place_token(t, y, x))
			{
				t->result_x = x;
				t->result_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int		down_left(t_filler *t)
{
	int		y;
	int		x;

	y = t->map_y;
	while (y > 0)
	{
		x = 0;
		while (x < t->map_x)
		{
			if (try_place_token(t, y, x))
			{
				t->result_x = x;
				t->result_y = y;
				return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

int				my_move(t_filler *t)
{
	if (t->move == 0)
	{
		if (down_right(t) || up_right(t) || down_left(t) || up_left(t))
			return (1);
	}
	else if (t->move == 1)
	{
		if (up_right(t) || down_right(t) || up_left(t) || down_left(t))
			return (1);
	}
	else if (t->move == 2)
	{
		if (down_left(t) || up_left(t) || down_right(t) || up_right(t))
			return (1);
	}
	else if (t->move == 3)
	{
		if (up_left(t) || down_left(t) || up_right(t) || down_right(t))
			return (1);
	}
	return (0);
}
