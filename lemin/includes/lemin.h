#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"

typedef struct s_home
{
  int nb_fourmis;
  t_list *liste_salles;
}     t_home;

typedef struct s_djiska
{
  int start;
  int end;
  int nombre_salles;
  int *lamda;
  int min_lambda;
  int *p;
  int *t;
  t_chemins *tab_chemins;
  t_chemins *len_chemins;
  int max_chemins;

}     t_djiska;


int acquisition(t_home *fourmilliere);
int traitement(t_home *fourmi);
void ft_putlstsalle(t_list **liste_salles);
int **construction_matrice(t_list *liste_salles, int *nombre_salles);
int lst_len(t_list *liste_salles);
void ft_print_matrice(int **matrice, int len);
int ft_printf_result(t_djiska *resultat, t_list *liste_salles, int nb_fourmis);
//int impression(t_lst_chemins chemin);

#endif
