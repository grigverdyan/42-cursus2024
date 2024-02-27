#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char *get_next_line(int fd);
int alloc_number(void);

int main(int argc, char **argv)
{
    char *line;
    int fd = 0;

    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
            return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        write(1, line, strlen(line));
        free(line);
    }
    if (fd > 0)
        close(fd);
    return (0);
}
