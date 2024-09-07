#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>




/* Pre-defined global variable */
extern char **environ;

/* Shell features implementation functions */
int _getline(char **lineptr, size_t *n, FILE *stream);
char *getinput(void);
char **inputstr_tok(char *input, const char *delim);
int execution(char **args, char *flname, int pcount);
int exit_shell(char **argv);
char *_getenv(const char *name);
char *find_cmd_in_path(char *cmd, char **args, char *flname, int pcount);
void change_dir(const char *dir);
char **split_cmds(char *input);


/* Helper functions 1 */
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);


/* Helper functions 2 */
int _isdigit(unsigned char c);
int _atoi(char *s);
int _putchar(char c);

/* Sub-files helper functions */
void free_args(char **args);
void exit_st(int exit_stat, char **args, char *flname, int pcount);
void free_path(char *path, char *path_copy);
int validate_cmd(char *cmd, char *dir, char *full_path, size_t size);
void error_msg(char **args, char *path, char *copy, char *flname, int pcount);
int non_interactive_exit(char **args, char *path, char *path_copy);

#endif /* MAIN_H */
