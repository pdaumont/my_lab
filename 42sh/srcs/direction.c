/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:48:53 by pdaumont          #+#    #+#             */
/*   Updated: 2015/10/19 14:57:23 by pdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"
#include "../libft/includes/libft.h"

t_list	*parsing_by_redirection_output_7(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "<", 2) == 0)
		{
			if (!temp->prev || !temp->next)
			{
				ft_putstr("erreur: redirection input");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stdin = fd;
				temp->fd_stdout = (temp->prev)->fd_stdin// probleme pour recuperer les infos 






				
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_8);
}



t_list	*parsing_by_redirection_output_6(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "2>", 2) == 0)
		{
			if (!temp->prev)
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stderr = fd;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_7);
}

t_list	*parsing_by_redirection_output_5(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "&>", 2) == 0)
		{
			if (!(temp->prev) || !(temp->next))
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stderr = fd;
				(temp->prev)->fd_stdin = fd;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_6);
}


t_list	*parsing_by_redirection_output_4(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "2>&1", 4) == 0)
		{
			if (!(temp->prev) || !(temp->next))
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else if (!(temp->next))
			{
				(temp->prev)->fd_stderr = (temp->prev)->fd_stdin;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
			else
			{
				
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_5);
}

t_list	*parsing_by_redirection_output_3(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "2>>", 3) == 0)
		{
			if (!(temp->prev) || !(temp->next))
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stderr = fd;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_4);
}

t_list	*parsing_by_redirection_output_2(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, ">", 1) == 0 || ft_strncmp(temp->content, "1>", 2) == 0)
		{
			if (!(temp->prev) || !(temp->next))
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stdout = fd;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_3);
}

t_list	*parsing_by_redirection_output(t_list *liste)
{
	t_list	*temp;
	int		fd;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, ">>", 2) == 0 || ft_strncmp(temp->content, "1>>", 3) == 0)
		{
			if (!(temp->prev) || !(temp->next))
			{
				ft_putstr("erreur: redirection output");
				exit(0);
			}
			else
			{
				if ((fd = open(ft_strjoin("./",(temp->next)->content), O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
				{
					ft_putstr("erreur: open failed\n");
					perror("error");
					exit(0);
				}
				(temp->prev)->fd_stdout = fd;
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (parsing_by_redirection_output_2(liste));
}


t_list	*parsing_arg(t_list	*liste)
{
	t_list *temp;

	temp = liste;
	while (temp)
	{
		if (ft_strncmp(temp->content, "-", 1) == 0)
		{
			if (!((temp->prev)->content))
			{
				ft_putstr("erreur: arguments");
				exit(0);
			}
			else
			{
				((temp->prev)->argv) = ft_strjoin((temp->prev)->argv, temp->content);
				(temp->prev)->next = temp->next;
				if (temp->next)
					(temp->next)->prev = temp->prev;
				//free possible
			}
		}
		temp = temp->next;
	}
	return (liste);

}

t_list	*parsing_by_space(t_list *liste)
{
	t_list	*new_el = NULL;
	t_list	*last;
	char 	**tab;
	int		i;
	int		j;

	while (liste)
	{
		i = 0;
		j = 0;
		if (liste->content)
			tab = ft_strsplit(liste->content, ' ');
		while (tab[i])
		{
			if (j == 0)
			{
				new_el = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
				new_el->prev = liste->prev;
				new_el->next = liste->next;
				if (liste->prev)
					(liste->prev)->next = new_el;
				if (liste->next)
					(liste->next)->prev = new_el;
				//free possible
				liste = new_el;
			}
			else
			{
				new_el = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
				new_el->prev = liste;
				new_el->next = liste->next;
				liste->next = new_el;
				liste = new_el;
				if (liste->next)
					(liste->next)->prev = new_el;
			}
			j = 1;
			i++;		
		}
		last = liste; 
		liste = liste->next;
	}
	while (last->prev)
		last = last->prev;
	return last;
}


int	main(int argc, char **argv)
{

	t_list	*liste = NULL;

	char	*tab[4];
	int n = -1;

	tab[0] = "commande1 -arg1 -arg2 -arg3 -arg4 >> file";



tab[0] = "commande1 -arg1 -arg2 -arg3 -arg4 >> file | cat -e ; echo toot";
	"commande1" "-arg1" "-arg2" "-arg3" "-arg4" ">>" "file" "|" "cat" "-e" ";" "echo" "toot"


										";"
							"|"						"echo" -> "toto"
    "commande1"	"-arg1" ...			"cat" -> "-e"


	//tab[1] = NULL;
	tab[1] = "commande3 -arg5 >> file2 > file3";
	//tab[2] = NULL;
	tab[2] = "commande6 -arg6 commande7 -arg7";
	tab[3] = NULL;

	while (tab[++n])
		ft_lstadd(&liste, ft_lstnew(tab[n], ft_strlen(tab[n]) + 1));
	//while (liste->next)
	//{
	liste = parsing_by_space(liste);
	liste = parsing_arg(liste);
	liste = parsing_by_redirection_output(liste);
	while (liste)
	{
		//if (liste->prev)
			//printf("%s->", (liste->prev)->content);
		printf("%s/ args = %s/ fd_stdout = %d  ->", liste->content, liste->argv, liste->fd_stdout);

		//if (liste->next)
			//printf("%s\n", (liste->next)->content);
		liste = liste->next; 
	}
	return (0);
}