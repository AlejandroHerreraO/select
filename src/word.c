/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:53:05 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 20:47:21 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsel.h"

t_word	*new_word(char *w)
{
	t_word	*word;

	word = (t_word *)malloc(sizeof(t_word));
	word->w = w;
	word->s = 0;
	word->c = 0;
	word->next = word;
	word->prev = word;
	return (word);
}

void	add_word(t_word **word, char *w)
{
	t_word *tmp;

	if (!*word)
	{
		*word = new_word(w);
		(*word)->c = 1;
		return ;
	}
	tmp = *word;
	while (tmp->next != *word)
		tmp = tmp->next;
	tmp->next = new_word(w);
	tmp->next->next = *word;
	tmp->next->prev = tmp;
	(*word)->prev = tmp->next;
}

void	rmv_word(t_word **word)
{
	t_word	*tmp;

	tmp = *word;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*word = tmp->next;
	if (*word == tmp)
		*word = NULL;
	free(tmp);
}

void	dst_word(t_word **word)
{
	while (*word)
		rmv_word(word);
}

void	put_word(t_word *word)
{
	t_word *tmp;

	tmp = word;
	if (!word)
		return ;
	while (1)
	{
		if (tmp->c == 1)
			ft_putstr_fd(tgetstr("us", NULL), 2);
		if (tmp->s == 1)
			ft_putstr_fd(tgetstr("so", NULL), 2);
		ft_putendl_fd(tmp->w, 2);
		ft_putstr_fd(tgetstr("ue", NULL), 2);
		ft_putstr_fd(tgetstr("se", NULL), 2);
		tmp = tmp->next;
		if (tmp == word)
			break ;
	}
}
