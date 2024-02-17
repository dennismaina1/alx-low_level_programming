#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <fnctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int _putchar(char c);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
size_t _strlen(const char *src);
ssize_t read_textfile(const char *filename, size_t letters);
#endif
