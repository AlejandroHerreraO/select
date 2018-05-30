/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 05:56:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 18:43:11 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsel.h"

void	out_word(t_word **word)
{
	t_word *tmp;

	if ((*word)->c == 1)
	{
		(*word)->next->c = 1;
		rmv_word(word);
		redraw(*word, 0);
		return ;
	}
	tmp = *word;
	while (1)
	{
		if (tmp->c == 1)
		{
			tmp->next->c = 1;
			rmv_word(&tmp);
			break ;
		}
		tmp = tmp->next;
	}
	redraw(*word, 0);
}

void	set_word(t_word *word)
{
	t_word *tmp;

	tmp = word;
	while (1)
	{
		if (tmp->c == 1)
		{
			tmp->s = (tmp->s == 0 ? 1 : 0);
			tmp->c = 0;
			tmp->next->c = 1;
			break ;
		}
		tmp = tmp->next;
	}
	redraw(word, 0);
}

void	move_down(t_word *word)
{
	t_word *tmp;

	tmp = word;
	while (1)
	{
		if (tmp->c == 1)
		{
			tmp->c = 0;
			tmp->next->c = 1;
			break ;
		}
		tmp = tmp->next;
	}
	redraw(word, 0);
}

void	move_up(t_word *word)
{
	t_word *tmp;

	tmp = word;
	while (1)
	{
		if (tmp->c == 1)
		{
			tmp->c = 0;
			tmp->prev->c = 1;
			break ;
		}
		tmp = tmp->next;
	}
	redraw(word, 0);
}

void	end_c(t_word *word)
{
	t_word	*tmp;
	int		i;

	i = 0;
	tmp = word;
	while (1)
	{
		if (tmp->s == 1)
		{
			if (i != 0)
				ft_putchar(' ');
			ft_putstr(tmp->w);
			i = 1;
		}
		tmp = tmp->next;
		if (tmp == word)
			return ;
	}
}
