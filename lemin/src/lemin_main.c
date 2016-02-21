#include <stdio.h>
#include "../includes/lemin.h"

//gerer les fuites
int main()
{
  t_home  fourmilliere;
  //t_lst_chemins   *paths;
  if (acquisition(&fourmilliere) == -1)
  {
    printf("erreur lors de l'aquisition");
    return (0);
  }
  if (traitement(&fourmilliere) == -1)
  {
    printf("erreur lors du traitement");
    return (0);
  }
/*  if (impression(paths) == -1)
  {
    printf("erreur lors de l'impression");
    return (0);
  }*/
  return(0);
}
