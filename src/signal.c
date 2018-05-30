/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 08:08:06 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/29 20:43:46 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsel.h"

void	sig4(int n)
{
	(void)n;
	redraw(NULL, 1);
}

void	sig3(int n)
{
	struct termios	t;

	(void)n;
	tcgetattr(0, &t);
	t.c_iflag &= ~(IXON | ICRNL);
	t.c_lflag &= ~(ICANON | ECHO | IEXTEN);
	tcsetattr(0, TCSANOW, &t);
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	set_signals();
	redraw(NULL, 1);
}

void	sig2(int n)
{
	struct termios	t;
	char			copy[2];

	(void)n;
	tcgetattr(0, &t);
	t.c_iflag |= IXON | ICRNL;
	t.c_lflag |= ICANON | ECHO | IEXTEN;
	tcsetattr(0, TCSANOW, &t);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	signal(SIGTSTP, SIG_DFL);
	copy[0] = t.c_cc[VSUSP];
	copy[1] = 0;
	ioctl(0, TIOCSTI, copy);
}

void	sig(int n)
{
	struct termios	t;

	(void)n;
	tcgetattr(0, &t);
	t.c_iflag |= IXON | ICRNL;
	t.c_lflag |= ICANON | ECHO | IEXTEN;
	tcsetattr(0, TCSANOW, &t);
	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	exit(0);
}

void	set_signals(void)
{
	signal(SIGWINCH, sig4);
	signal(SIGCONT, sig3);
	signal(SIGTSTP, sig2);
	signal(SIGHUP, sig);
	signal(SIGINT, sig);
	signal(SIGKILL, sig);
	signal(SIGALRM, sig);
	signal(SIGPIPE, sig);
	signal(SIGTERM, sig);
	signal(SIGXCPU, sig);
	signal(SIGXFSZ, sig);
	signal(SIGVTALRM, sig);
	signal(SIGPROF, sig);
	signal(SIGUSR2, sig);
	signal(SIGUSR1, sig);
}
