/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:52:48 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/18 17:52:50 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H
# define BUFF_SIZE 12
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

int	get_next_line2(const int fd, char **line);

#endif
