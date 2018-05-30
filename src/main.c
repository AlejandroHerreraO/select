/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:44:03 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 21:11:44 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsel.h"

static int	check_size(t_word *word)
{
	struct winsize	sz;
	t_word			*tmp;
	int				i;
	int				j;
	int				k;

	if (!word)
		return (1);
	ioctl(0, TIOCGWINSZ, &sz);
	tmp = word;
	i = 0;
	j = 0;
	while (++i)
	{
		k = ft_strlen(tmp->w);
		j = (k > j ? k : j);
		tmp = tmp->next;
		if (tmp == word)
			break ;
	}
	if (sz.ws_row <= i || sz.ws_col < j)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, sz.ws_row + 1), 2);
	if (sz.ws_row <= i || sz.ws_col < j)
		return (0);
	return (1);
}

void		redraw(t_word *word, int mode)
{
	static t_word	*w;

	if (mode == 0)
		w = word;
	write(2, "\e[1;1H\e[2J", 10);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 2);
	if (!check_size(w))
	{
		ft_putendl_fd("The Window is too small!", 2);
		return ;
	}
	put_word(w);
}

static int	read_in(t_term *trm, char flag[5])
{
	ft_memset(flag, 0, 5);
	while (read(0, flag, 4) != -1)
	{
		if (!trm->words || !ft_strcmp(flag, "\x1b"))
			return (0);
		else if (flag[0] == '\x1b')
		{
			if (flag[2] == 'A')
				move_up(trm->words);
			if (flag[2] == 'B')
				move_down(trm->words);
			if (flag[2] == '3')
				out_word(&trm->words);
		}
		else if (flag[0] == 32)
			set_word(trm->words);
		else if (flag[0] == 127)
			out_word(&trm->words);
		if (flag[0] == 13)
			return (1);
		ft_memset(flag, 0, 5);
	}
	return (1);
}

int			main(int ac, char **av)
{
	char	flag[5];
	t_term	*trm;
	int		n;

	n = 0;
	if (ac == 1)
	{
		ft_printf("usage: ./ft_select target(s)\n");
		return (0);
	}
	if (!(trm = new_trm(av)))
	{
		ft_printf("missing TERM enviromental variable\n");
		return (0);
	}
	set_trm(trm);
	redraw(trm->words, 0);
	set_signals();
	ft_memset(flag, 0, 5);
	n = read_in(trm, flag);
	ust_trm(trm);
	if (n == 1)
		end_c(trm->words);
	dst_trm(&trm);
	return (0);
}
