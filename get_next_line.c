#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *saved;
    char    *allocated;
    int         readen;

    allocated = malloc((size_t) BUFFER_SIZE + 1);
    if (!allocated)
    {
        if (saved)
            free(saved);
        return (saved = NULL, NULL);
    }
    readen = 1;
    while (ft_strchr(saved, '\n') && readen > 0)
    {
        readen = read(fd, allocated, BUFFER_SIZE);
        saved = 
    }
    free(allocated);
    return (get_line(saved, readen));
}

// int main()
// {
//     int i = 1;
//     int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
//     if (fd == -1)
//         return (0);
//     char *s = get_next_line(fd);
//     printf("[%d] : %s", i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
// }