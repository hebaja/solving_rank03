#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER
# define BUFFER 10
#endif

char*	filter(char *str, char *filt)
{
	int		len;
	char	*found;
	int		i;

	len = strlen(filt);
	i = -1;
	found = strstr(str, filt);
	if (found)
	{
		while (++i < len)
			found[i] = '*';
		return (found);
	}
	return (NULL);
}

int    main(int argc, char **argv)
{
    int    fd;
    char    *buf;
    char    *str;
	char	*res;
    int        bytes;
    int        pos;

    bytes = 0;
    pos = 0;
    if (argc == 2)
    {
        buf = malloc(sizeof(char *) * BUFFER);
        str = malloc(sizeof(char *) * BUFFER);
        memset(buf, 0, BUFFER);
        bytes = read(STDIN_FILENO, buf, BUFFER);
        memmove(str, buf, bytes);
        while (bytes)
        {
            pos += bytes;
            memset(buf, 0, BUFFER);
            bytes = read(STDIN_FILENO, buf, BUFFER);
            if (bytes > 0)
            {
                char    *tmp;
                tmp = str;
                str = realloc(tmp, pos + bytes + 1);
                memmove(&str[pos], buf, bytes);
            }
        }
        str[pos] = '\0';
        free(buf);

		res = filter(str, argv[1]);
		while (res)
			res = filter(str, argv[1]);
		printf("%s", str);

        free(str);
    }
    return (0);
}

