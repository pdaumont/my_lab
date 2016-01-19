/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:13:27 by pdaumont          #+#    #+#             */
/*   Updated: 2015/04/28 12:13:18 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_countwords(char const *s, char c)
{
	int i;
	int cpt;
	int in;

	i = 0;
	cpt = 0;
	in = 0;
	while (s[i])
	{
		if ((s[i] == c && in == 0) || (s[i] != c && in == 1))
			i++;
		if (s[i] != c && in == 0)
		{
			in = 1;
			cpt++;
			i++;
		}
		if (s[i] == c && in == 1)
		{
			in = 0;
			i++;
		}
	}
	return (cpt);
}

static	char	**ft_create_tab(int cpt)
{
	char **tab;

	tab = (char **)malloc((cpt + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

static	char	**ft_putintab(char const *s, char **tab, char c)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			tab[j] = ft_strsub(s, i, len);
			j++;
			i = i + len;
			len = 1;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_putintab(s, ft_create_tab(ft_countwords(s, c)), c));
}
