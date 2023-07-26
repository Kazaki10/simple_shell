#ifndef _SHELL_H_
#define _SHELL_H_

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>

/* for read write buffers */
#define BUFFER_SIZE 1024
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/*external variables*/
extern char **environ;
int should_exit;
char *path_var;

/* Function Prototypes */
void handle_cd(char **args);
void execute_builtin_cmvd(char **args);
void handle_exit(char **args);
void handle_sigint(__attribute__((unused))int signum);
void generate_prompt(void);
int main(__attribute__((unused))int argc, char **argv);
int is_builtin_cmvd(const char *command);
int check_cmd_path(const char *cmvd, char *cmd_path, char *path_var);
void store_path_var(char **path_var);
void exect_cmd(char *cmd, char **argv, char *path_var);
void freechar(char **arr);

/**
 * execut_exter_cmd - execute external command
 *
 * @cmd: command string (unused).
 * @args: array of arguments for the command.
 * @path_var: value of the PATH environment variable.
 * @argv: program arguments (unused).
 */
void execut_exter_cmd(__attribute__((unused)) char *cmd, char **args,
		char *path_var, char **argv);

/*string functions*/
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
void my_putstring(char *str);
int	my_strlen(char *s);
char *my_strchr(const char *s, char c);
char *_getenv(const char *token);
char *our_getline(void);


#endif
