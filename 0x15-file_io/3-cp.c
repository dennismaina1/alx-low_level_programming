/* header files */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - main function to copy file to another
 * @ac: argument count
 * @av: argument value
 * Return: 0 if success, 97,98,99,100 if fail
 */
int main(int ac, char **av)
{
	int fd1, fd2, res;
	ssize_t numread;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(fd1, "Error: Can't read from file: %s", av[1]);
		exit(98);
	}
	fd2 = open(av[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd2 == -1)
	{
		dprintf(fd2, "Error: Can't write to :%s", av[2]);
		exit(99);
	}

	while ((numread = read(fd1, buffer, sizeof(buffer))) > 0)
	{
		write(fd2, buffer, numread);

	}
	res = close(fd1);
	if (res != 0)
	{
		dprintf(2, "Error: Can't close fd %d", fd1);
		exit(100);
	}
	res = close(fd2);
	if (res != 0)
	{
		dprintf(2, "Error: Can't close fd %d", fd2);
	}
	return (0);
}
