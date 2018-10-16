/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:35:16 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 15:35:17 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	  move 0	  move 1	  move 2	  move 3
**
**				my position on the map
**
**		*.			..			.*			..
**		..			*.			..			.*
**
**				my first move strategy
**
**	down_right	 up_right	 down_left	  up_left
*/

static void		set_first_move(t_filler *t)
{
	if (t->map_x / t->me_x > 1)
	{
		if (t->map_y / t->me_y > 1)
			t->move = 0;
		else
			t->move = 1;
	}
	else
	{
		if (t->map_y / t->me_y > 1)
			t->move = 2;
		else
			t->move = 3;
	}
}

static void		find_me(t_filler *t)
{
	int		y;
	int		x;

	y = 0;
	while (y < t->map_y)
	{
		x = 0;
		while (x < t->map_x)
		{
			if (t->map[y][x] == t->me)
			{
				t->me_x = x;
				t->me_y = y;
			}
			x++;
		}
		y++;
	}
	set_first_move(t);
}

static int		token(t_filler *t, char *line)
{
	int		n;
	int		y;

	n = 6;
	y = 0;
	get_next_line(0, &line);
	t->token_y = ft_atoi(&line[n]);
	while (ft_isdigit(line[n]))
		n++;
	n++;
	t->token_x = ft_atoi(&line[n]);
	ft_strdel(&line);
	t->token = (char **)malloc(sizeof(char *) * t->token_y);
	if (!t->token)
		return (-1);
	while (y < t->token_y)
	{
		get_next_line(0, &line);
		t->token[y] = ft_strdup(line);
		y++;
		ft_strdel(&line);
	}
	return (0);
}

static int		map(t_filler *t, char *line)
{
	int		y;

	y = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	t->map = (char **)malloc(sizeof(char *) * t->map_y);
	if (!t->map)
		return (-1);
	while (y < t->map_y)
	{
		get_next_line(0, &line);
		t->map[y] = ft_strdup(&line[4]);
		y++;
		ft_strdel(&line);
	}
	return (0);
}

int				get_map_token(t_filler *t, char *line)
{
	if (map(t, line) == -1)
		return (-1);
	if (token(t, line) == -1)
		return (-1);
	if (!t->me_x && !t->me_y)
		find_me(t);
	return (0);
}
