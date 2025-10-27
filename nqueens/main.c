#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

int	check_diagonal_back_up(char *arr, int pos, int N);
int	check_diagonal_back_down(char *arr, int pos, int N);
int	check_diagonal_forward_up(char *arr, int pos, int N);
int	check_diagonal_forward_down(char *arr, int pos, int N);

void	print_arr(char arr[], int N)
{
	int	i;

	i = -1;
	while (++i < N)
		printf("%c", arr[i]);
	printf("\n");
}

int	check_vertical(char *arr, int pos, int N)
{
	int		i;
	char	fixed;

	i = -1;
	fixed = arr[pos];
	while (++i < N)
	{
		if (fixed == arr[pos + 1])
			return 0;
	}
	while (pos--)
	{
		if (fixed == arr[pos])
			return (0);
	}
	return (1);
}

void	do_nqueens(char *arr, int pos, int i, int *flag, int *valids, int N)
{
	char	n;
	int		valid;

	pos++;
	valid = 1;
	if (flag && pos < N)
	{
		n = '0';
		arr[pos] = n;
		while (arr[pos] < (N + 48))
		{
			if (!check_vertical(arr, pos, N) ||
				!check_diagonal_back_up(arr, pos, N) ||
				!check_diagonal_back_down(arr, pos, N) ||
				!check_diagonal_forward_up(arr, pos, N) ||
				!check_diagonal_forward_down(arr, pos, N))
			{
				n++;
				if (n == (N + '0'))
					break ;
				arr[pos] = n;
				*flag = 0;
			}
			else
			{
				*flag = 1;
				(*valids)++;
				break ;
			}
		}
		// if (*flag)
		// 	print_arr(arr, N);
			// do_nqueens(arr, pos, i, flag, N);
	}
	if (pos != N - 1)
	{
		i = 0;
		if (*flag == 0 && n == ('0' + N))
		{
			arr[pos - 1] = arr[pos - 1] + 1;
			pos--;
		}
		// else
			// pos++;
		do_nqueens(arr, pos, i, flag, valids, N);
	}
}

void	loop_nqueens(int N)
{
	char	*arr;
	int		pos;
	int		flag;
	int		i;
	int		tmp_pos;
	int		valids;

	arr = (char *)malloc(sizeof(char) * (N + 1));
	pos = 0;
	flag = 1;
	i = -1;
	while (++i < N)
	{
		bzero(arr, N + 1);
		arr[pos] = i + 48;
		valids = 1;
		// tmp_pos = pos + 1;
		do_nqueens(arr, pos, i, &flag, &valids, N);
		if (valids == N)
			print_arr(arr, N);
	}
}

int	main(int argc, char **argv)
{
	int	N;

	if (argc == 2)
	{
		N = atoi(argv[1]);
		if (N >= 0 && N <= 3)
			return (0);
		else
			loop_nqueens(N);
	}

	return (0);
}
