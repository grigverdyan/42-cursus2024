#ifndef PARSE_ARGUMENTS_H
# define PARSE_ARGUMENTS_H

int		check_args(int argc, char **argv, int *unordered);
void	check_num(char *num, char **temp, int *nums_count);
void	check_num1(char *num, char **temp);


int		get_nums_count(char **argv);
int		*get_nums(int nums_count, char **argv);
void	check_duplicates(int *unordered, int size);


#endif /* PARSE_ARGUMENTS_H */