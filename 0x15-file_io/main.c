#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int append_text_to_file(const char *filename, char *text_content);
size_t _strlen(const char *src);
int create_file(const char *filename, char *text_content);
int _putchar(char c); 

int main(int ac, char **av)
{

        int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s filename text\n", av[0]);
		exit(1);
	}
	        res = append_text_to_file(av[1], av[2]);
		printf("-> %i)\n", res);
	        return (0);
}
