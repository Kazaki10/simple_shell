#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* handle built ins */
int checker(char **uti, char *tokens);
void print_promp(void);
void sig_handler(int m);
char **tkn_iz(char *line);
char *path_checker(char **path, char *cmd);
char *path_adding(char *path, char *uti);
int built_handler(char **command, char *line);
void exiting_cmd(char **tcmd, char *stn);
void env_printer(void);

/**
 * struct tool - Represents a tool or feature
 * @acti: Boolean indicating if the tool is active or not
 *
 * This structure is used to define a tool or feature, and the 'acti' member
 * indicates whether the tool is active or not.
 */
struct tool
{
bool acti;
} tool;

void buff_free(char **buf);

void cmd_execute(char *pcm, char **vra);
char *path_finder(void);

/**
 * struct builtin - Represents built-in commands or functions
 * @env: Pointer to a character representing the environment
 * @exit: Pointer to a character representing the exit status
 *
 * This structure is used to store information related to built-in commands
 * or functions in a program.
 */
struct builtin
{
char *env;
char *exit;
} builtin;

/**
 * struct items - Represents items or elements
 * @final_exit: Integer representing the final exit status
 * @line_c: Integer representing the line count
 *
 * This structure is used to store certain properties or data related to items
 * or elements in a program.
 */
struct items
{
int final_exit;
int line_c;
} items;

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#endif
