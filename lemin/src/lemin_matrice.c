#include "../includes/lemin.h"
#include <stdio.h>

void ft_print_matrice(int **matrice, int len)
{
  int j;
  int i;

  j = 0;
  while (j <= len)
  {
    i = 0;
    while (i <= len)
    {
      printf(" %d", matrice[j][i]);
      i++;
    }
    printf("\n");
    j++;
  }
}

void construction_ligne(int **ligne, int len)
{
  int i;

  i = 1;
  while (i <= len)
  {
    (*ligne)[i] = 2147483647;
    i++;
  }
}

int lst_len(t_list *liste_salles)
{
  t_list  *temp;
  int     i;

  i = 0;
  temp = liste_salles;
  while (temp)
  {
    i++;
    temp = temp->next;
  }
  return (i);
}

void placer_0(int **mat, int len)
{
  int i;
  int j;

  i = 1;
  j = 1;
  while (i <= len)
  {
    j = 0;
    while (j <= len)
    {
      if (mat[i][0] == mat[0][j])
        mat[i][j] = 0;
        j++;
    }
    i++;
  }
}
int *conversion_int(char **char_arcs, t_list *liste_salles)
{
    int *arcs;
    int i;
    int len;
    t_list *temp;

    i = 0;
    len = 0;
    while (char_arcs[len])
      len++;
    arcs = (int*)malloc(sizeof(int) * len);
    while(i < len)
    {
      temp = liste_salles;
      while (ft_strcmp(temp->content, char_arcs[i]) != 0)
        temp = temp->next;
      arcs[i] = temp->num;
      i++;
    }
    return (arcs);
}

void placer_arcs_sur_ligne(int **mat, t_list  *salle, t_list *liste_salles)
{
  char **char_arcs;
  int *arcs;
  int j;
  int i;
  int k;

  i = 1;
  k = 0;
  char_arcs = ft_strsplit(salle->arcs, ',');
  if (!char_arcs)
    return ;
  arcs = conversion_int(char_arcs, liste_salles);
  while (salle->num != mat[i][0])
    i++;
  while (arcs[k])
  {
    j = 1;
    while (mat[0][j] != arcs[k])
      j++;
    mat[i][j] = 1;
    k++;
  }
}
void placer_arcs(int **mat, t_list *liste_salles)
{
  t_list  *salle;
  salle = liste_salles;
  while (salle)
  {
      placer_arcs_sur_ligne(mat, salle, liste_salles);
      salle = salle->next;
  }
}

void remplir_premiere_ligne(int ***mat, int **ligne, t_list *liste_salles)
{
  t_list *temp;
  int i;

  (*ligne)[0] = 0;
  temp = liste_salles;
  i = 1;
  while (temp)
  {
      (*ligne)[i] = temp->num;
      temp = temp->next;
      i++;
  }
  (*mat)[0] = *ligne;
}
int **construction_matrice(t_list *liste_salles, int *nombre_salles)
{
  t_list  *temp;
  int     *ligne;
  int     **mat;
  int     i;
  int     j;

  j = 1;
  i = lst_len(liste_salles);
  if ((mat = (int**)malloc(sizeof(int*) * (i + 1))) == NULL)
    return (NULL);
  if ((ligne = (int*)malloc(sizeof(int) * (i + 1))) == NULL)
     return (NULL);
  remplir_premiere_ligne(&mat, &ligne, liste_salles);
  temp = liste_salles;
  while (temp)
  {
    if ((ligne = (int*)malloc(sizeof(int) * (i + 1))) == NULL)
     return (NULL);
    ligne[0] = temp->num;
    construction_ligne(&ligne, i);
    mat[j]= ligne;
    temp = temp->next;
    j++;
  }
  placer_0(mat, i);
  placer_arcs(mat, liste_salles);
  ft_print_matrice(mat, i);
  printf("\n");
  *nombre_salles = i;
  return (mat);
}
