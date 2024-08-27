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

extern char **environ;
int _getline(char **lineptr, size_t *n, FILE *stream);
char *getinput(void);
char **inputstr_tok(char *input, const char *delim);
int execution(char *argv, char **args, char **env, char *flname, int pcount);
int exit_shell(char **argv);
char *_getenv(const char *name);
char *find_cmd_in_path(char *cmd);
void change_dir(const char *dir);
char **split_cmds(char *input);

#endif /* MAIN_H */
