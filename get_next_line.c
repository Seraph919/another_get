#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
    if (!str)
        return (0);
	while (str[i])
		i++;
	return (i);
}

void  protected_alloc(char **saved, char **allocated)
{
    if (!*saved)
    {    
        *saved = ft_strdup("");
        if (!*saved)
            *saved = NULL;
    }
    *allocated = malloc((size_t) BUFFER_SIZE + 1);
    if (!*allocated)
    {
        if (*saved)
            free(*saved);
        *saved = NULL;
    }
}   

char    *get_line(char **saved, int readen)
{
    char *temp_saved;
    char *pos;
    if (readen > 0)
    {
        temp_saved = *saved;
        pos = ft_strchr(temp_saved, '\n');
        *saved = ft_strdup(pos + 1);
        *(pos + 1) = '\0';
        return (temp_saved);
    }
    temp_saved = ft_strdup(*saved);
	free(*saved);
    *saved = NULL;
    return (temp_saved);
}

char *get_next_line(int fd)
{
    static char *saved;
    char    *allocated;
    int         readen;
    int           boole;

    boole = 0;
    protected_alloc(&saved, &allocated);
    // printf("\n*****2******\n");
    readen = 1;
    while (!(ft_strchr(saved, '\n')) && readen > 0)
    {
        // printf("\n*****3******\n");
        readen = read(fd, allocated, BUFFER_SIZE);
        // printf("\n*****4******\n");
        allocated[readen] = '\0';
        if (readen == 0)
            break;
        if (readen == -1)
            return (free(allocated), free(saved), NULL);
        saved = ft_strjoin(saved, allocated);
        // printf("\n*****5******\n");
        if (!saved)
            return (free(allocated), free(saved), NULL);
        // printf("\n*****6******\n");
    }
    free(allocated);
    if (ft_strcmp(saved, "") == 0)
        return (free(saved), NULL);
    return (get_line(&saved, readen));
}

int main()
{
    int i = 1;
    int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
    if (fd == -1)
        return (0);
    char *s = get_next_line(fd);
    printf("[%d] : %s", i, s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

}