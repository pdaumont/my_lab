#include "../includes/lemin.h"
#include <stdio.h>

int construction_ligne(int *ligne, )
{

  return (0);
}
int construction_matrice(int ****matrice, t_list *liste_salles)
{
  t_list  *temp;
  int     *ligne;
  int     **mat;
  int     i;
  char    *arcs;

  temp = liste_salles;
  i = 0;
  while (temp)
  {
    i++;
    temp = temp->next;
  }
  mat = (int**)malloc(sizeof(int*) * i + 1);
  mat[i] = 0;
  temp = liste_salles;
  while (temp)
  {
    if (temp->arcs)
    {
      arcs = ft_strsplit(temp->arcs,',');
      i = 0;
      while (arcs[i])
        i++;
      ligne = (int*)malloc(sizeof(int) + 1);
      construction_ligne(&ligne, temp->arcs);
    }

    else

    temp = temp->next;
  }
  return (0);
}

int traitement(t_home *fourmi)
{
  int ***matrice;

  construction_matrice(&matrice, (*fourmi)->liste_salles);
  return (0);
}
