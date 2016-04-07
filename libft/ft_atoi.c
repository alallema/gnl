/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 12:48:59 by alallema          #+#    #+#             */
/*   Updated: 2015/11/28 19:04:32 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int nb;
	int neg;

	neg = 0;
	nb = 0;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (str[i] - 48) + (10 * nb);
		i++;
	}
	if (neg == 1)
		nb = nb * -1;
	return (nb);
}
