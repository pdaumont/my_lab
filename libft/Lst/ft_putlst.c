#include "libft.h"

void	ft_putlst(t_list *liste)
{
	t_list *temp;

	temp = liste;
	while (temp)
	{
		ft_putstr(temp->content);
		ft_putstr("\n");
		temp = temp->next;
	}
}