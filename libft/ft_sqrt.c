/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/08 16:29:51 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return (0);
}
