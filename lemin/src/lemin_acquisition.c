#include "../includes/lemin.h"
#include <stdio.h>

/*##############################################
probleme acquisition a regler si commentaire segfault a la fin dans arc
#############################################*/
void ft_putlstsalle(t_list **liste_salles)
{
  t_list *temp;

  temp = *liste_salles;
  while (temp)
  {
    printf("salle n %d: nom = %s, arc = %s\n",  temp->num, temp->content, temp->arcs);
    if (temp->start)
      printf("salle de départ\n");
    if (temp->end)
      printf("salle d'arrivée'\n");
    temp = temp->next;
  }
}

int is_alreadycreated(char *name, t_list **liste_salles)
{
  t_list *temp;

  temp = *liste_salles;
  while (temp)
  {
    if (ft_strcmp(name, temp->content) == 0)
      return (1);
    temp = temp->next;
  }
  return (0);
}

int is_allnumber(char *ligne)
{
  unsigned int i;

  i = 0;
  while (i < ft_strlen(ligne))
  {
    if (!ft_isdigit(ligne[i]))
      return(-1);
      i++;
  }
  return (0);
}

int is_nb_fourmis(t_home *fourmi, char **ligne)
{
  get_next_line(0, ligne);
  if (is_allnumber(*(ligne)) == -1)
    return(-1);
  fourmi->nb_fourmis = ft_atoi((const char*)(*(ligne)));
  printf("nombre fourmis == %d\n", fourmi->nb_fourmis);
  return(0);
}

int construction_arc(char *ligne, t_list **liste_salles)
{
  t_list *temp;
  char **arc_data;

  temp = *(liste_salles);
  arc_data = ft_strsplit(ligne,'-');
  while (temp)
  {
    if (ft_strcmp(arc_data[0], temp->content) == 0)
      {
        if (is_alreadycreated(arc_data[1], liste_salles) == 0)
        {
          ft_putstr("arc: salle d'arrivée invalide\n");
          return (-1);
        }
        if (temp->arcs)
            temp->arcs = ft_strjoin(temp->arcs, ft_strjoin(",",arc_data[1]));
        else
          temp->arcs = arc_data[1];
        return (0);
      }
    temp = temp->next;
  }
  ft_putstr("arc: salle de depart invalide\n");
  return (-1);
}

int construction_salle(char *ligne, t_list **liste_salles)
{
  char **new_salle;
  int   nb;

  if (!ligne)
  {
    ft_putstr("salle: ligne vide");
    return(-1);
  }

  if (!(*liste_salles))
  {
      new_salle = ft_strsplit(ligne, ' ');
      nb = 1;
  }
  else
        nb = (*(liste_salles))->num + 1;
        new_salle = ft_strsplit(ligne, ' ');
        if (is_alreadycreated(new_salle[0], liste_salles) == 1)
          return (-1);
  ft_lstadd(liste_salles, ft_lstnew(new_salle[0], sizeof(t_list*)));
  (*(liste_salles))->num = nb;
  (*(liste_salles))->x = ft_atoi(new_salle[1]);
  (*(liste_salles))->y = ft_atoi(new_salle[2]);
  return (0);
}

int is_correct(char *ligne)
{
  char **salle;
  char **arc;

  if (!ligne)
    return (-1);
  if ('#' == ligne[0])
  {
    if (ft_strcmp("##start", (const char*)ligne) == 0)
      return (3);
    if (ft_strcmp("##end", (const char*)ligne) == 0)
      return (4);
    else
      return (0);
  }
  else
    {
      salle = ft_strsplit(ligne, ' ');
      if (is_allnumber(salle[1]) == 0 && is_allnumber(salle[2]) == 0 && !salle[3])
      {
        free (salle);
        return (1);
      }
      arc = ft_strsplit(ligne, '-');
      if (arc[0] && arc[1] && !arc[2])
      {
        free (arc);
        return (2);
      }
      return (-1);
    }
}

int acquisition(t_home *fourmi)
{
  char *ligne;
  int set_start;
  int set_end;
  t_list *liste_salles;

ligne = NULL;
liste_salles = NULL;
set_start = 0;
set_end = 0;
if (is_nb_fourmis(fourmi, &ligne) == -1)
  {
    ft_putstr("première ligne invalide\n");
    return (-1);
  }
  while (get_next_line(0, &ligne))
  {
    printf("return is correct == %d\n", is_correct(ligne));
    switch (is_correct(ligne))
    {
      case -1:
        return (-1);
      case 0:
        break;
      case 1:
          if (construction_salle(ligne, &liste_salles) == -1)
            return (-1);
          break;
      case 2:
        if (construction_arc(ligne, &liste_salles) == -1)
          return (-1);
        break;
      case 3:
        if (set_start == 0)
          {
            if (get_next_line(0, &ligne) == -1 && is_correct(ligne) != 1)
              return (-1);
            set_start = 1;
            construction_salle(ligne, &liste_salles);
            liste_salles->start = 1;
            break;
          }
        else
          return (-1);
      case 4:
        if (set_end == 0)
        {
          if (get_next_line(0, &ligne) == -1 || is_correct(ligne) != 1)
            return (-1);
          set_end = 1;
          printf("is correct: %d\n", is_correct(ligne));
          construction_salle(ligne, &liste_salles);
          liste_salles->end = 1;
          break;
        }
        else
          return (-1);
    }
  }
  ft_putlstsalle(&liste_salles);
  *fourmi->liste_salles = liste_salles;
  return (0);
}
