#include "../includes/lemin.h"
#include <stdio.h>

int min(int *lamda, int nombre_salles, int *t)
{
  int min;
  int i;

  min = 2147483647;
  i = 0;
  while (i < nombre_salles)
  {
    if (lamda[i] < min && lamda[i]!= 0)
    {
      if (i > 0 && t[i]!= 0)
        min = lamda[i];
    }
      i++;
  }
  return (min);
}

void initialiser_t(t_djiska *resultat, int **matrice)
{
  int i;

  i = 0;
  resultat->t = (int*)malloc(sizeof(int) * (resultat->nombre_salles));
  while (i < resultat->nombre_salles)
  {
    (resultat->t)[i] = matrice[0][i + 1];
    i++;
  }
  i = 0;
  while (i < resultat->nombre_salles)
  {
    if ((resultat->t)[i] == resultat->start)
      (resultat->t)[i] = 0;
      i++;
  }
}

void initialiser_p(t_djiska *resultat)
{
    int i;

    i = 0;
    while (i < resultat->nombre_salles)
    {
      if (((resultat->lamda))[i] < 2147483647 && ((resultat->lamda))[i] > 0)
        (resultat->p)[i] = resultat->start;
        i++;
    }
}


int initialisation_structure_djiska_3(t_djiska *resultat, int **matrice)
{
  if (!(resultat->t = (int*)malloc(sizeof(int) * (resultat->nombre_salles - 2))))
    return (-1);
  initialiser_t(resultat, matrice);
  initialiser_p(resultat);
  return (0);
}


int initialisation_structure_djiska_2(int **matrice, t_djiska *resultat)
{
  int i;
  int j;

    i = 0;
    j = 0;
    if ((resultat->lamda = (int*)malloc(sizeof(int) * resultat->nombre_salles)) == NULL)
      return (-1);
    if ((resultat->p = (int*)malloc(sizeof(int) * resultat->nombre_salles)) == NULL)
      return (-1);
    while (matrice[i][0] != resultat->start)
      i++;
    while (j < resultat->nombre_salles)
    {
      (resultat->lamda)[j] = matrice[i][j + 1];
      j++;
    }

    return (0);
}

int is_t_empty(t_djiska *resultat)
{
    int i;

    i = 0;
    while (i < resultat->nombre_salles - 1)
    {
      if ((resultat->t)[i] != 0)
        return (0);
      i ++;
    }
    return (1);
}

int choisir_i(t_djiska *resultat)
{
  int i;

  i = 0;
  resultat->min_lambda = min(resultat->lamda, resultat->nombre_salles, resultat->t);
  if (resultat->min_lambda == 2147483647)
    return (-1);
  while (i < resultat->nombre_salles)
    {
      if ((resultat->lamda)[i] == resultat->min_lambda && resultat->t[i] != 0)
          return (i);
      i++;
    }
    return (-1);
}
int compter_successeurs(int **matrice, int sommet, t_djiska *resultat)
{
      int nb_st;
      int i;
      int j;

      i = 1;
      j = 1;
      nb_st = 0;
      while (matrice[i][0] != sommet)
        i++;
      while (j <= resultat->nombre_salles)
      {
          if (matrice[i][j] == 1)
              nb_st++;
          j++;
      }
      return (nb_st);
}
void remplir_successeurs(int **successeurs, int **matrice, int sommet, t_djiska *resultat)
{
  int i;
  int j;
  int k;
  int x;

  i = 0;
  k = 0;
  while (matrice[i][0] != sommet)
    i++;
  while (j <= resultat->nombre_salles)
    {
        if (matrice[i][j] == 1)
        {
          x = 0;
          while (x < resultat->nombre_salles)
          {
            if ((resultat->t)[x] == matrice[0][j])
              break;
            x++;
          }
          if (x != resultat->nombre_salles)
          {
            (*successeurs)[k] = matrice[0][j];
            k++;
          }
        }
        j++;
    }
    (*successeurs)[k] = 0;
}

int *trouver_successeurs(int **matrice, int sommet, t_djiska *resultat)
{
  int *successeurs;
  int nb_st;

  nb_st = compter_successeurs(matrice, sommet, resultat);
  if ((successeurs = (int*)malloc(sizeof(int) * (nb_st + 1))) == NULL)
    return (NULL);
  remplir_successeurs(&successeurs, matrice, sommet, resultat);
  return (successeurs);
}

void modifier_lambda_et_p(int *successeurs, t_djiska *resultat, int sommet, int** matrice)
{
  int k;
  int x;
  int y;
  int i;
  int j;


  k = 0;
  while (successeurs[k] != 0)
  {
      x = 0;
      y = 0;
      i = 1;
      j = 1;
      while ((resultat->t)[x] != sommet)
        x++;
      while ((resultat->t)[y] != successeurs[k])
        y++;
      while (matrice[i][0] != sommet)
        i++;
      while (matrice[0][j] != successeurs[k])
        j++;
      if (resultat->lamda[y] > resultat->lamda[x] + matrice[i][j])
        {
          //printf("lamda %d = %d; lamda %d + matrice [%d][%d] = %d\n", y, resultat->lamda[y],x, i, j, resultat->lamda[x] + matrice[i][j]);
          resultat->lamda[y] = resultat->lamda[x] + matrice[i][j];
          resultat->p[y] = sommet;
        }
      k++;
    }
}

int ft_calcul_du_plus_court_chemin(t_djiska *resultat, int **matrice)
{
  int i;
  int *successeurs;
  int sommet;

  successeurs = NULL;
  while (is_t_empty(resultat) == 0)
  {
    if ((i = choisir_i(resultat)) == -1)
      return (-1);
    sommet = (resultat->t)[i];
    printf("sommet = %d\n", sommet);
  if (!(successeurs = trouver_successeurs(matrice, sommet, resultat)))
     return (-1);
    modifier_lambda_et_p(successeurs, resultat, sommet, matrice);
    (resultat->t)[i] = 0;
    i = 0;
    while (i < resultat->nombre_salles)
    {
      printf("%d,", (resultat->lamda)[i]);
      i++;
    }
     i = 0;
       printf("\n");
    while (i < resultat->nombre_salles)
    {
      printf("%d,", (resultat->t)[i]);
      i++;
    }
    i = 0;
      printf("\n");
   while (i < resultat->nombre_salles)
   {
     printf("p =%d,", (resultat->p)[i]);
     i++;
   }
     printf("\n");
  }
  return (0);
}

/*void nettoyage_matrice(int ***p_matrice)
{

}*/
int initialisation_structure_djiska(t_djiska *resultat, t_list *liste_salles, int nombre_salles)
{
    t_list  *temp;

    temp = liste_salles;
    while (temp)
    {
      if (temp->start == 1)
        resultat->start = temp->num;
      if (temp->end == 1)
        resultat->end = temp->num;
      temp = temp->next;
    }
    if ((resultat->start == 0) ||(resultat->end == 0))
    {
      ft_putstr("traitement: pas de début ou de fin\n");
      return -1;
    }
    resultat->nombre_salles = nombre_salles;
    return (0);
}

int *allocation_memoire_tab_int(int *tab_int, int x)
{
  int i;

  i = 0;
  while (tab_int[i] != -1)
    i++;
  return ((int*)malloc(sizeof(int) * (i + x)));
}

void copie_tab_int(int *src, int **dest, int x)
{
  int i;

  i = 0;
  while (src[i] != -1)
  {
    (*dest)[i + x] = src[i];
        i++;
  }
}

int *remplir_chemin(t_djiska *resultat, int i)
{
  int j;
  int k;
  int x;
  int *chemin;

  j = 0;
  x = 0;
  while (resultat->t[j] != resultat->end)
    j++;
  chemin = (int*)malloc(sizeof(int) * (i + 1));
  chemin[0] = (resultat->p)[j];
//  printf("chemin [%d] = %d\n", x, chemin[x]);
  x++;
  while (resultat->p[j] != resultat->start)
  {
    k = 0;
    while (resultat->t[k] != resultat->p[j])
      k++;
    chemin[x] = resultat->p[k];
    //printf("chemin [%d] = %d\n", x, chemin[x]);
    x++;
    j = k;
  }
  chemin[x] = -1;
//  printf("chemin [%d] = %d\n", x, chemin[x]);
  return (chemin);
}

void trouver_chemin(t_djiska *resultat, int i)
{
  int j;

  j = 0;
  ft_lstaddchemins(&(resultat->tab_chemins), ft_lstnewchemins(remplir_chemin(resultat, i), sizeof(int) * (i + 1)));
    t_chemins *temp;

    temp = resultat->tab_chemins;

      while (j < 4)
      {
            printf("temp = %d\n",temp->content[j]);
            j++;
      }
}
int trouver_longeur_chemin(t_djiska *resultat, int i)
{

  if (resultat->lamda[i] == 2147483647)
    return (-1);
  ft_lstaddchemins(&(resultat->len_chemins), ft_lstnewchemins(&resultat->lamda[i], sizeof(int*)));
      return (0);
}
int traitement_des_resultats(t_djiska *resultat, int **matrice)
{
  int i;

  i = 0;
  initialiser_t(resultat, matrice);
  while (resultat->end != resultat->t[i])
    i++;
  if (trouver_longeur_chemin(resultat, i) == -1)
    return -1;
  trouver_chemin(resultat, (resultat->len_chemins)->content[0]);
  return (0);
}

void modifier_matrice(int ***matrice, t_djiska *resultat)
{
  int i;
  int j;
  int x;

  i = 0;
  x = 0;
  while ((*matrice)[i][0] != resultat->start)
    i++;
  while ((resultat->tab_chemins)->content[x] != resultat->start)
    x++;
  while (x - 1 >= 0)
  {
    j = 0;
    while ((*matrice)[0][j] != (resultat->tab_chemins)->content[x - 1])
      j++;
    printf( "content = %d\n", (resultat->tab_chemins)->content[x - 1]);
    printf("i = %d: j= %d\n", i, j);
    (*matrice)[i][j] = 2147483647;
    i = 0;
    while ((*matrice)[i][0] != (resultat->tab_chemins)->content[x - 1])
      i++;
    x--;
  }
  j = 0;
  while ((*matrice)[0][j] != resultat->end)
    j++;
  (*matrice)[i][j] = 2147483647;
}

int verification_chemin(t_list *liste_salles, int **matrice, int len)
{
  int max_chemins;
  t_list *temp;
  int i;
  int j;

  temp = liste_salles;
  i = 1;
  j = 1;
  while (temp->end == 0)
    temp = temp->next;
  while (temp->num != matrice[0][j])
    j++;
  while (i <= len)
    {
      if (matrice[i][j] == 1)
        max_chemins++;
        i++;
    }
    printf(" max chemins = %d\n", max_chemins );
  return (max_chemins);
}


int Dijkstra(int **matrice, t_djiska *resultat, int nb_fourmis, t_list *liste_salles, int nombre_salles)
{
  int i;
  int total_len;

  total_len = 0;
  i = 0;
  if (initialisation_structure_djiska(resultat, liste_salles, nombre_salles) != 0)
    return (-1);
  while(nb_fourmis - total_len >= 0 && i < resultat->max_chemins)
  {
    if (total_len != 0)
      modifier_matrice(&matrice, resultat);
    ft_print_matrice(matrice, resultat->nombre_salles);
    if (initialisation_structure_djiska_2(matrice, resultat) != 0)
        return (-1);
    if (initialisation_structure_djiska_3(resultat, matrice) != 0)
        return (-1);
    ft_calcul_du_plus_court_chemin(resultat, matrice);
    if (traitement_des_resultats(resultat, matrice) == -1)
    {
        ft_printf_result(resultat, liste_salles, nb_fourmis);
        return (0);
    }
    total_len = total_len + (resultat->len_chemins)->content[0];
    i++;
  }
  return (0);
}


int traitement(t_home *fourmi)
{
  int   **matrice;
  int   nombre_salles;
  t_djiska  *resultat;

  nombre_salles = 0;

  if ((resultat = (t_djiska*)malloc(sizeof(t_djiska))) == NULL)
    return (-1);
  if (!(matrice = construction_matrice(fourmi->liste_salles, &nombre_salles)))
    {
          ft_putstr("traitement: erreur dans la création de la matrice\n");
          return (-1);
    }
  if ((resultat->max_chemins = verification_chemin((*fourmi).liste_salles, matrice, nombre_salles)) == 0)
  {
        ft_putstr("traitement:aucun chemin possible - fin de la procédure\n");
        return (-1);
  }
  resultat->len_chemins = NULL;
  resultat->tab_chemins = NULL;
  if ( Dijkstra(matrice, resultat, fourmi->nb_fourmis,(*fourmi).liste_salles,
  nombre_salles) != 0)
    {
          ft_putstr("traitement:Dijkstra a échoué\n");
          return (-1);
    }
  return (0);
}
