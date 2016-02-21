#include "../includes/lemin.h"
#include <stdio.h>

int ft_print_arc(t_list *liste_salles)
{
  t_list *temp;
  char **str;
  int i;

  temp = liste_salles;
  while(temp)
  {
    if (temp->arcs)
    {
      str = ft_strsplit(temp->arcs, ',');
      i = 0;
      while (str[i])
      {
        ft_putstr(temp->content);
        ft_putchar('-');
        ft_putstr(str[i]);
        ft_putstr("\n");
        i++;
      }
    }
    temp = temp->next;
  }
  return (0);
}
void ft_print_salle_2(t_list *temp)
{
  while(temp)
  {
    if (temp->end == 1)
        ft_putstr("##end\n");
    if (temp->start)
      ft_putstr("##start\n");
      ft_putchar(temp->content[0]);
      ft_putstr(" ");
      ft_putnbr(temp->x);
      ft_putstr(" ");
      ft_putnbr(temp->y);
      ft_putstr("\n");
      temp = temp->next;
  }
}
int ft_print_salle(t_list *liste_salles)
{
  t_list *temp;

  temp = liste_salles;
  while (temp)
    temp = temp->next;
  temp = liste_salles;
  ft_lstrevert(&temp);
  ft_print_salle_2(temp);
  ft_print_arc(temp);
  ft_lstrevert(&temp);
  return (0);
}
int min_ligne(int *ligne, int nb_chemins)
{
  int i;
  int min;
  int j;

  i = 1;
  j = 1;
  min = ligne[1];
  while (i <= nb_chemins)
  {
    if (min > ligne[i])
    {
      min = ligne[i];
      j = i;
    }
    i++;
  }
  return (j);
}
void mise_a_jour_matrice(int ***matrice, int nb_chemins, int nb_fourmis, int ligne)
{
  int j;

  while (ligne <= nb_fourmis)
  {
    j = 1;
    while (j <= nb_chemins)
    {
      (*matrice)[ligne][j] = (*matrice)[ligne - 1][j] + 1;
      j++;
    }
    ligne++;
  }
}
void modification_matrice(int ***matrice, int nb_chemins, int nb_fourmis, int ligne)
{
  int j;
  int min;

  j = 1;

  min = min_ligne((*matrice)[ligne], nb_chemins);
  while (j <= nb_chemins)
  {
    if (j != min)
    {
      (*matrice)[ligne + 1][j] = (*matrice)[ligne][j];
      (*matrice)[ligne][j] = 0;
    }
    j++;
  }
  if (ligne == nb_fourmis - 1)
    return ;
  mise_a_jour_matrice(matrice, nb_chemins, nb_fourmis, ligne + 2);
  modification_matrice(matrice, nb_chemins, nb_fourmis, ligne + 1);
}

void modification_matrice_derniere(int ***matrice, int nb_chemins, int nb_fourmis)
{
  int j;
  int min;

  j = 1;

  min = min_ligne((*matrice)[nb_fourmis], nb_chemins);
  while (j <= nb_chemins)
  {
    if (j != min)
      (*matrice)[nb_fourmis][j] = 0;
    j++;
  }
}

void remplir_matrices_secondaires(int ****p_matrices, t_djiska *resultat, int nb_chemins, int nb_fourmis)
{
  int k;
  int i;
  int j;
  int f;
  t_chemins *temp;

  k = nb_chemins - 1;
  f = nb_fourmis;
  temp = resultat->tab_chemins;
  while (k >= 0)
  {
    i = 1;
    while (i <= (*p_matrices)[k][0][0])
    {
      (*p_matrices)[k][i][0] = f;
      f--;
      i++;
    }
    i = 1;
    while (i <= (*p_matrices)[k][0][0])
    {
      j = 1;
      while (j <= (*p_matrices)[k][0][1])
      {
          if (j == (*p_matrices)[k][0][1])
          {
            (*p_matrices)[k][i][j] = resultat->end;
          }
          else
            (*p_matrices)[k][i][j] = (temp)->content[(*p_matrices)[k][0][1]- j - 1];
          j++;
      }
      i++;
    }
    temp = temp->next;
    k--;
  }
}

char *trouver_sommet(int number, t_list *liste_salles)
{
  t_list *temp;

  temp = liste_salles;
  while (temp->num != number)
      temp = temp->next;
  return (temp->content);
}

void imprimer_matrices_secondaires(int ****p_matrices, t_djiska *resultat, int nb_chemins, t_list *liste_salles, int compteur)
{
  int k;
  int i;
  int j;
  int stop;
  //char *sommet;


  k = 0;
  stop = 0;
  compteur = compteur + 1;
  while (k < nb_chemins)
  {
    if ((*p_matrices)[k][1][(*p_matrices)[k][0][1]] == 0)
      stop++;
    k++;
  }
  if (stop == nb_chemins)
  {
    ft_putstr("nombre de tours = ");
    ft_putnbr(compteur);
    ft_putstr("\n");
        return ;
  }

  k = 0;
  while (k < nb_chemins)
  {
    j = 1;
    while (j <= (*p_matrices)[k][0][1])
    {
          i = (*p_matrices)[k][0][0];
        while ( i > 1 && (*p_matrices)[k][i][j] == 0)
            i--;
        if (i == 1 && (*p_matrices)[k][i][j] != 0)
        {
          if (j == 1 || (*p_matrices)[k][i][j - 1] == 0)
          {
;
            printf("L%d-%s ", (*p_matrices)[k][i][0], trouver_sommet((*p_matrices)[k][i][j], liste_salles));
            (*p_matrices)[k][i][j] = 0;
          }
        }
        else
        {
          if (i > 1 && (j == 1 || (*p_matrices)[k][i - 1][j - 1] == 0))
          {
            printf("L%d-%s ", (*p_matrices)[k][i][0], trouver_sommet((*p_matrices)[k][i][j], liste_salles));
          (*p_matrices)[k][i][j] = 0;
          }
        }
          j++;
    }
    k++;
  }
  liste_salles = liste_salles;
  resultat= resultat;
      ft_putstr("\n");
  imprimer_matrices_secondaires(p_matrices, resultat, nb_chemins, liste_salles, compteur);



}
void lets_go_girls(int **matrice, t_djiska *resultat, int nb_chemins, int nb_fourmis, t_list *liste_salles)
{
  int ***p_matrices;
  int i;
  int j;
  int k;

  j = 0;
  if ((p_matrices = (int***)malloc(sizeof(int**) * (nb_chemins))) == NULL)
    return ;
  while (j < nb_chemins)
  {
      i = 1;
      k = 0;
      while (i <= nb_fourmis)
      {
        if (matrice[i][j + 1] != 0)
          k++;
        i++;
      }
      if ((p_matrices[j] = (int**)malloc(sizeof(int*) * (k + 1))) == NULL)
        return ;
      i = 0;
      while (i <= k)
      {
        if ((p_matrices[j][i] = (int*)malloc(sizeof(int) * (matrice[0][j + 1] + 2))) == NULL)
          return ;
        i++;
      }
      p_matrices[j][0][0] = k;
      p_matrices[j][0][1] = matrice[0][j + 1];
      j++;
  }

  remplir_matrices_secondaires(&p_matrices, resultat, nb_chemins, nb_fourmis);
  imprimer_matrices_secondaires(&p_matrices, resultat, nb_chemins, liste_salles, 0);
}

int **repartition_fourmis(t_djiska *resultat, int nb_chemins, int nb_fourmis, t_list *liste_salles)
{
  int **matrice;
  t_chemins *temp;
  int i;
  int j;


  if ((matrice = (int**)malloc(sizeof(int*) * (nb_fourmis + 1))) == NULL)
    return (NULL);
  if ((matrice[0] = (int*)malloc(sizeof(int) * (nb_chemins + 1))) == NULL)
      return (NULL);
  temp = resultat->len_chemins;
  i = nb_chemins;
  matrice[0][0] = 0;
  while(temp && i > 0)
  {
    matrice[0][i] = temp->content[0];
    i--;
    temp = temp->next;
  }
  i = 1;
  while ( i <= nb_fourmis)
  {
    if ((matrice[i] = (int*)malloc(sizeof(int) * (nb_chemins + 1))) == NULL)
        return (NULL);
    matrice[i][0] = i;
    j = 1;
    while (j <= nb_chemins)
    {
      matrice[i][j] = matrice[0][j] + i - 1;
      j++;
    }
    i++;
  }
  modification_matrice(&matrice, nb_chemins, nb_fourmis, 1);
  modification_matrice_derniere(&matrice, nb_chemins, nb_fourmis);
  lets_go_girls(matrice, resultat, nb_chemins, nb_fourmis, liste_salles);
   return (matrice);
}


void ft_move_little_ants(t_djiska *resultat, int nb_fourmis, t_list *liste_salles)
{
  t_chemins *temp;
  int i;
  int **matrice;

  temp = resultat->len_chemins;
  i = 0;
  while (temp)
  {
    i++;
    temp = temp->next;
  }
  if (i == 0)
  {
    ft_putstr("aucun chemin possible, il faut le creuser\n");
    return ;
  }
  if ((matrice = repartition_fourmis(resultat, i, nb_fourmis, liste_salles)) == NULL)
      return ;
}

int ft_printf_result(t_djiska *resultat, t_list *liste_salles, int nb_fourmis)
{
  ft_putnbr(nb_fourmis);
  ft_putstr("\n");
  ft_print_salle(liste_salles);
  ft_putstr("\n");
  ft_move_little_ants(resultat, nb_fourmis, liste_salles);

  return (0);
}
