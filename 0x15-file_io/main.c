#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c); 

int main(int ac, char **av)
{
	ssize_t n;

	if (ac != 2)
			    
        dprintf(2, "Usage: %s filename\n", av[0]);
	exit(1);
						        
	n = read_textfile(av[1], 114);
	printf("\n(printed chars: %li)\n", n);
	n = read_textfile(av[1], 1024);
	printf("\n(printed chars: %li)\n", n);
	return (0);
}

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t  total_read;
	char *buff;
	

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return 0;
	}
	buff = malloc(sizeof(char) * letters);
	total_read = read(fd, buff, letters);

	if (total_read == -1)
	{
		perror("Failed to read file");    
		close(fd);
		return (0);
	}
	write(STDOUT_FILENO, buff, total_read);

	free(buff);
	close(fd);
	return (total_read);
}

