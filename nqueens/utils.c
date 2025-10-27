int	check_diagonal_back_up(char *arr, int pos, int N)
{
	char	fixed;

	if (pos == 0)
		return (1);
	fixed = arr[pos];
	while (pos >= 0)
	{
		fixed--;
		if (fixed < '0' || fixed >= ('0' + N))
			break ;
		if (fixed == arr[pos - 1])
			return (0);
		pos--;
	}
	return (1);
}

int	check_diagonal_back_down(char *arr, int pos, int N)
{
	char	fixed;

	if (pos == N - 1)
		return (1);
	fixed = arr[pos];
	while (pos < N)
	{
		fixed--;
		if (fixed < '0' || fixed >= ('0' + N))
			break ;
		if (fixed == arr[pos + 1])
			return (0);
		pos++;
	}
	return (1);
}

int	check_diagonal_forward_up(char *arr, int pos, int N)
{
	char	fixed;

	if (pos == 0)
		return (1);
	fixed = arr[pos];
	while (pos >= 0)
	{
		fixed++;
		if (fixed < '0' || fixed >= ('0' + N))
			break ;
		if (fixed == arr[pos - 1])
			return (0);
		pos--;
	}
	return (1);
}

int	check_diagonal_forward_down(char *arr, int pos, int N)
{
	char	fixed;

	if (pos == N - 1)
		return (1);
	fixed = arr[pos];
	while (pos < N)
	{
		fixed++;
		if (fixed < '0' || fixed >= ('0' + N))
			break ;
		if (++fixed == arr[pos + 1])
			return (0);
		pos++;
	}
	return (1);
}
