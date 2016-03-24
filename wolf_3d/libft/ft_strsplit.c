/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:03 by acollet           #+#    #+#             */
/*   Updated: 2015/03/24 18:41:12 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		countwords(char const *s, char sep)
{
	size_t	i;
	int		out;

	i = 0;
	out = 1;
	while (*s)
	{
		if (*s == sep && !out)
			out = 1;
		else if (*s != sep && out)
		{
			i++;
			out = 0;
		}
		s++;
	}
	return (i);
}

static int		wordlen(char const *s, char sep, size_t begin)
{
	int	cpt;

	cpt = 0;
	while (s[begin] && s[begin] != sep)
	{
		cpt++;
		begin++;
	}
	return (cpt);
}

static void		tab_push(char **tab, char const *s, char sep)
{
	size_t	len;
	size_t	i;
	int		cpt;

	cpt = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != sep)
		{
			len = wordlen(s, sep, i);
			tab[cpt++] = ft_strdup(ft_strsub(s, i, len));
		}
		i += (s[i] != sep) ? len : 1;
	}
	tab[cpt] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	tab_push(tab, s, c);
	return (tab);
}
