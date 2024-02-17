/**
 * create_file - function to create new file
 * @filename: name of file
 * @text_content: text to be included in file
 * Return: 1 if sucessful, -1 if fail
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	write(fd, text_content, _strlen(text_content));
	close(fd);
	return (1);
}
/**
 * _strlen - function to find length of string
 * @src: source string
 * Return: string length
 */
size_t _strlen(const char *src)
{
	size_t length = 0;

	while (src[length] != '\0')
	{
		length++;
	}
	return (length);
}
