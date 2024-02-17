/**
 * read_textfile - function to read text content from file
 * @filename: name of file to read
 * @letters: number of characters to display
 * Return: number of characters written
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff;
	ssize_t num_read, total_written;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Failed to open file");
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		perror("Failed to allocate memory");
		close(fd);
		free(buff);
		return (0);
	}
	while ((num_read = read(fd, buff, letters)) > 0)
	{
		total_written = write(STDOUT_FILENO, buff, num_read);

	}
	free(buff);
	close(fd);
	return (total_written);

}

