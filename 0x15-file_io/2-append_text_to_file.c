/*header files*/
#include "main.h"

/**
 * append_text_to_file - function to append text to file
 * @filename: the file name append text
 * @text_content: the content to be appended
 * Return: 1 if successful -1 if fail
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int len, fd, writ;
	char newline = '\n';

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; )
			len++;
	}
	fd = open(filename, O_RDWR | O_APPEND | O_CREAT, 0600);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	writ = write(fd, text_content, len);
	if (writ == -1)
	{
		return (-1);
	}

	writ = write(fd, &newline, 1);

	close(fd);
	return (1);
}
