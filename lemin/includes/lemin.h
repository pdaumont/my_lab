#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"

typedef struct s_home
{
  int nb_fourmis;
  t_list *liste_salles;
}     t_home;

/*typedef struct  s_lst_chemins
{
  int *chemin;
  s_lst_chemins *next;
}     t_lst_chemins;
*/


int acquisition(t_home *fourmilliere);
int traitement(t_list *liste_salles);
//int impression(t_lst_chemins chemin);

#endif
