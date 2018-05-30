/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:17:00 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 20:32:11 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSEL_H
# define LIBSEL_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <term.h>
# include <signal.h>
# include <curses.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct				s_word
{
	char					*w;
	int						s;
	int						c;
	struct s_word			*next;
	struct s_word			*prev;
}							t_word;

typedef struct				s_term
{
	t_word					*words;
	int						fd;
	struct termios			*termio;
	struct termios			*termio_orig;
}							t_term;

int							ft_printf(const char *str, ...);
t_term						*new_trm(char **av);
void						ust_trm(t_term *trm);
void						set_trm(t_term *trm);
void						dst_trm(t_term **trm);
t_word						*new_word(char *w);
void						add_word(t_word **word, char *w);
void						rmv_word(t_word **word);
void						dst_word(t_word **word);
void						put_word(t_word *word);
void						out_word(t_word **word);
void						set_word(t_word *word);
void						move_down(t_word *word);
void						move_up(t_word *word);
void						end_c(t_word *word);
void						redraw(t_word *word, int mode);
void						set_signals(void);

#endif
