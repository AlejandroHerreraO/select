/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 05:56:42 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 20:20:00 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsel.h"

void	ust_trm(t_term *trm)
{
	tcsetattr(0, TCSANOW, trm->termio_orig);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
}

void	set_trm(t_term *trm)
{
	trm->termio->c_iflag &= ~(IXON | ICRNL);
	trm->termio->c_lflag &= ~(ICANON | ECHO | IEXTEN);
	trm->termio->c_cc[VTIME] = 1;
	trm->termio->c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, trm->termio);
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

t_term	*new_trm(char **av)
{
	t_term			*trm;
	char			*terms;
	char			*a;
	t_word			*words;
	int				i;

	if (!(terms = getenv("TERM")))
		return (NULL);
	a = (char *)malloc(2049 * sizeof(char));
	trm = (t_term *)malloc(sizeof(t_term));
	trm->fd = tgetent(a, terms);
	ft_strdel(&a);
	words = NULL;
	i = 0;
	while (av[++i])
		add_word(&words, av[i]);
	trm->words = words;
	trm->termio = (struct termios *)malloc(sizeof(struct termios));
	trm->termio_orig = (struct termios *)malloc(sizeof(struct termios));
	tcgetattr(0, trm->termio);
	tcgetattr(0, trm->termio_orig);
	return (trm);
}

void	dst_trm(t_term **trm)
{
	dst_word(&((*trm)->words));
	close((*trm)->fd);
	free((*trm)->termio);
	free((*trm)->termio_orig);
	free(*trm);
	*trm = NULL;
}
