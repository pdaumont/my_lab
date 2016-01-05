#ifndef SH_H
#define SH_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include <sys/types.h> 
# include <sys/stat.h> 
# include <dirent.h>
# include <fcntl.h>
# include "../includes/grammar_symbols.h"
# include "../includes/lexeur_parseur.h"


int 		test_erreur(int ac);
void		loop(char ***env);
void		prompt(char **cmd, char **env);
int			display_prompt(int c);
int			get_next_line(int fd, char **line);
char		**clear_cmd(char **cmd);
char		*tab_to_space(char *str);
int			is_exit(char *str);
void		execute(char **tab, char ***penv);
void		free_tab(char **tab);
int			built_in_pipe(int i, char **tab, char ***penv);
void		b_env(char **env);
void		b_setenv(int i, char **tab, char ***env);
char 		**ad_elem_to_tab(char **tab, char *elem);
int			is_new_elem(int i, char **tab, char ***penv);
void		b_unsetenv(int i, char **tab, char ***penv);
void		b_cd(int i, char **tab, char ***penv);
char		*bin_finder(char **tab, char ***penv);
void		test_erreur_env(char ***penv);
char		**split_cmds(char **cmd);
void		lexing_parsing_main(char **read, node **tree);
#endif