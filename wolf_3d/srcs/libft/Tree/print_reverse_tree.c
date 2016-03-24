/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printReverseTree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:08:13 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 15:08:17 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_reverse_tree(node *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		print_reverse_tree(tree->right);
	ft_putstr("Key =");
	ft_putnbr(tree->key);
	ft_putstr("content = ");
	ft_putlst(tree->content);
	ft_putstr("\n");
	if (tree->left)
		print_reverse_tree(tree->left);
}
