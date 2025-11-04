#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

int	check_diagonal_back_up(char *arr, int pos, int SIZE);
int	check_diagonal_back_down(char *arr, int pos, int SIZE);
int	check_diagonal_forward_up(char *arr, int pos, int SIZE);
int	check_diagonal_forward_down(char *arr, int pos, int SIZE);
int	check_vertical(char *arr, int pos, int SIZE);

void	print_arr(char arr[], int SIZE)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		printf("%c", arr[i]);
	printf("\n");
}

void	nqueens(char *arr, int n, int next_pos, int SIZE, char **results, int *results_count)
{
	if (next_pos == SIZE || n - 48 == SIZE)
		return ;
	arr[next_pos] = n;
	if (check_vertical(arr, next_pos, SIZE) &&
		check_diagonal_back_up(arr, next_pos, SIZE) &&
		check_diagonal_back_down(arr, next_pos, SIZE) &&
		check_diagonal_forward_up(arr, next_pos, SIZE) &&
		check_diagonal_forward_down(arr, next_pos, SIZE))
	{
		if (arr[next_pos] == SIZE + 48)
			return ;
		n = '0';
		nqueens(arr, n, ++next_pos, SIZE, results, results_count); // Loops for the next when match is good
		if (next_pos == SIZE)
		{
			// results[*results_count] = strdup(arr) arr;
			results[*results_count] = (char *)malloc(sizeof(char) * (SIZE + 1));
			strcpy(results[*results_count], arr);
			(*results_count)++;
		}
		else
		{
			arr[next_pos - 1]++;
			if (arr[next_pos - 1] == SIZE + '0')
				return ;
			n = '0';
			nqueens(arr, n, next_pos, SIZE, results, results_count); // 
		}
	}
	else
	{
		if (arr[next_pos] == SIZE - 1 + 48)
			return ;
		n++;
		nqueens(arr, n, next_pos, SIZE, results, results_count);	//Loops for the next to try to find a good match 
	}

}

int	main(int argc, char **argv)
{
	int		SIZE;
	char	*arr;
	char	**results;
	int		results_count;
	int		i;
	char	n;
	int		next_pos;
	int		curr_pos;

	results_count = 0;
	results = (char **)malloc(sizeof(char *) * 128);
	// i = -1;
	// while (++i < 128)
		// results[i] = (char *)malloc(sizeof(char) * (SIZE + 1));
	bzero(results, sizeof(char *) * 128);
	i = -1;
	if (argc == 2)
	{
		SIZE = atoi(argv[1]);
		if (SIZE >= 0 && SIZE <= 3)
			return (0);
		else
		{
			arr = (char *)malloc(sizeof(char) * (SIZE + 1));
			n = '0';
			next_pos = 1;
			curr_pos = 0;
			while (++i < SIZE)
			{
				bzero(arr, SIZE + 1);
				arr[curr_pos] = n;
				nqueens(arr, '0', next_pos, SIZE, results, &results_count);
				n++;
			}
			
		}
	}
	free(arr);
	free(results);
	return (0);
}
