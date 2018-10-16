/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:35:34 by dshults           #+#    #+#             */
/*   Updated: 2018/05/28 15:35:38 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_map_token(t_filler *t)
{
	int y;

	y = 0;
	while (y < t->map_y)
		ft_strdel(&t->map[y++]);
	free(t->map);
	y = 0;
	while (y < t->token_y)
		ft_strdel(&t->token[y++]);
	free(t->token);
}

static void	send_results(t_filler *t)
{
	if (t->move == 0)
		t->move = 1;
	else if (t->move == 1)
		t->move = 0;
	else if (t->move == 2)
		t->move = 3;
	else if (t->move == 3)
		t->move = 2;
	ft_printf("%i %i\n", t->result_y, t->result_x);
}

static void	who_is_who(t_filler *t, char p)
{
	if (p == '1')
	{
		t->me = 'O';
		t->player = 'X';
	}
	else
	{
		t->me = 'X';
		t->player = 'O';
	}
}

int			main(void)
{
	signed char	play;
	t_filler	*t;
	char		*line;

	play = 1;
	t = ft_memalloc(sizeof(t_filler));
	if (!t)
		return (-1);
	get_next_line(0, &line);
	who_is_who(t, line[10]);
	ft_strdel(&line);
	while (play)
	{
		get_next_line(0, &line);
		t->map_y = ft_atoi(&line[8]);
		t->map_x = ft_atoi(&line[11]);
		ft_strdel(&line);
		if (get_map_token(t, line) == -1)
			return (-1);
		play = my_move(t);
		send_results(t);
		free_map_token(t);
	}
	free(t);
	return (0);
}
