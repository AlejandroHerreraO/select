/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:53:07 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/18 17:53:08 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

static char	*r_fi(int *fd, char **st)
{
	int		ret;
	char	*tmp;
	char	*r;

	tmp = ft_strnew(BUFF_SIZE + 1);
	ret = read(*fd, tmp, BUFF_SIZE);
	if (ret < 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[ret] = '\0';
	if (ret != 0 && !ft_strchr(tmp, '\n'))
		tmp = r_fi(fd, &tmp);
	if (!*st)
		r = ft_strdup(tmp);
	else
		r = ft_strjoin(*st, tmp);
	if (*st)
		ft_strdel(st);
	if (ret == 0)
		*fd = -1;
	free(tmp);
	return (r);
}

int			get_next_line2(const int fd, char **line)
{
	static char	*buf;
	char		*tmp;
	int			i;

	buf = r_fi((int *)&fd, &buf);
	i = 0;
	if (!ft_strcmp(buf, ""))
	{
		free(buf);
		return (0);
	}
	if (ft_strchr(buf, '\n') != NULL)
	{
		while (buf[i] != '\n')
			i++;
		*line = ft_strnew(i);
		ft_strncpy(*line, buf, i);
	}
	else
		*line = ft_strdup(buf);
	tmp = ft_strdup(buf + i + 1);
	free(buf);
	buf = tmp;
	return (1);
}
