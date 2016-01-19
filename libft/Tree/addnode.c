/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:07:27 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 16:17:42 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		error(node** tree, unsigned int key)
{
		if (!key)
	{
		ft_putstr("error: key missing\n");
		return (-1);
	}
	if (!tree)
	{
		ft_putstr("error: empty tree\n");
		return (-1);
	}
	return (0);
}

node	*new_node(unsigned int key, char *content)
{
	node	*elem;

		if ((elem = malloc(sizeof(node))) == NULL)
	{
		ft_putstr("error: malloc failed\n");
		return NULL;
	}
	elem->key = key;
	elem->left = NULL;
	elem->right = NULL;
	elem->content = ft_strdup(content);
	return (elem);
}

void	addnode(node** tree, unsigned int key, char *content)
{
	node	*tmp_node;
	node 	*tmp_tree;
	node	*elem;

	if (error(tree, key) == -1 || !(elem = new_node(key, content)))
		return ;
	tmp_tree = *tree;

	if (tmp_tree)
	{
		while (tmp_tree)
		{
			tmp_node = tmp_tree;
			if (key > tmp_tree->key)
			{
				tmp_tree = tmp_tree->right;
				if (!tmp_tree)
					tmp_node->right = elem;
			}
			else
			{
				tmp_tree = tmp_tree->left;
				if (!tmp_tree)
					tmp_node->left = elem;
			}
		}
	}
	else
		*tree = elem;
}
