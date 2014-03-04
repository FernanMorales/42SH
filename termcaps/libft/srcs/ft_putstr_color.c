/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 19:36:13 by pvarin            #+#    #+#             */
/*   Updated: 2014/01/12 20:39:41 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>


void		ft_putstr_color(char *COLOR, char *str)
{
	ft_putstr(ft_strsub(COLOR, 0, 5));
	ft_putstr(str);
	ft_putstr(&COLOR[5]);
}

