#include "../includes/checker.h"

int		ft_error(int code, int *final_list)
{
	if (code == 0)
		printf("Error arguments\n");
	else if (code == 1)
		printf("Error list\n");
	else if (code == 2)
		printf("Same number\n");
	if (final_list != NULL)
		free(final_list);
	return (0);
}

int		main(int argc, char **argv)
{
	int		*final_list;
	int		list_nbr;
	char	*line;


	final_list = NULL;
	if (argc != 2)
		return (ft_error(0, final_list));
	list_nbr = parse_arg(argv[1], &final_list);
	if (list_nbr < 0)
		return (ft_error(1, final_list));
	if (unique_values(final_list, list_nbr) == FALSE)
		return (ft_error(2, final_list));
	for (int i = 0; i < list_nbr; i++)
		printf("value %3d : %3d\n", i, final_list[i]);
	while (get_next_line(0, &line) != 0)
	{
		check_ope_name(line);
		free(line);
	}
	free(final_list);
	return (0);
}
