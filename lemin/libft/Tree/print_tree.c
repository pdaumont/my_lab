/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:08:24 by pdaumont          #+#    #+#             */
/*   Updated: 2015/11/11 15:08:26 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tree(node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		print_tree(tree->left);
	ft_putstr("Key =");
	ft_putnbr(tree->key);
	ft_putstr(" content = ");
	ft_putstr(tree->content);
	ft_putstr("\n");
	if (tree->right)
		print_tree(tree->right);
}
