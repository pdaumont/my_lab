/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearTree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:07:46 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 15:07:50 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_tree(node **tree)
{
	node *tmptree;

	tmptree = *tree;
	if (!tree)
		return ;
	if (tmptree->left)
		clear_tree(&tmptree->left);
	if (tmptree->right)
		clear_tree(&tmptree->right);
	free(tmptree);
	*tree = NULL;
}
