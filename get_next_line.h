#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 22
#endif

# include <unistd.h>
# include <fcntl.h>
#include <stdint.h>
# include <stdio.h>
# include <string.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);

#endif