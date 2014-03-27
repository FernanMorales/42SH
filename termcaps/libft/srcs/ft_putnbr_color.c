/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:21:42 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/12 17:22:47 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>


void		ft_putnbr_color(char *COLOR, int nb)
{
	char	*tmp;

	tmp = ft_strsub(COLOR, 0, 5);
	ft_putstr(tmp);
	ft_putnbr(nb);
	ft_putstr(&COLOR[5]);
	free(tmp);
}

