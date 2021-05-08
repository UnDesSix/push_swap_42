#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <../../libft/libft.h>

int		ft_atoi_spe(const char *str, int *result);
int		parse_arg(char *arg, int **final_list);
#endif
