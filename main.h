#ifndef MAIN_H
#define MAIN_H

int _getline(char **lineptr, size_t *n, FILE *stream);
char *getinput(void);
char **inptstr_tok(char *input, const char *delim);
int execution(char *argv, char **args, char **env, char *flname, int pcount);
int exit_shell(char **argv);

#endif /* ifndef MAIN_H */
