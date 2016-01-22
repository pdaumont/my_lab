/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchNode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:08:30 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 15:08:36 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_node(node *tree, unsigned int key)
{
	while (tree)
	{
		if (key == tree->key)
			return (1);
		if (key > tree->key)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (0);
}
