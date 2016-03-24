/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:48:05 by acollet           #+#    #+#             */
/*   Updated: 2015/01/06 15:30:40 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	return (c == ' '
	|| c == '\t'
	|| c == '\n'
	|| c == '\v'
	|| c == '\r'
	|| c == '\f');
}

int			ft_atoi(const char *str)
{
	int val;
	int isneg;

	while (is_space(*str))
		str++;
	val = 0;
	isneg = 0;
	if (*str == '-' || *str == '+')
	{
		isneg = (*str == '-') ? 1 : 0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10;
		val += *str - '0';
		str++;
	}
	return (!isneg) ? val : -val;
}
