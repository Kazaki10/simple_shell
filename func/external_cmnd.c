#include "our_shell.h"

/**
 * execut_exter_cmd - Executes an external command
 * @cmd: The command name
 * @args: An array of command arguments
 * @path_var: The value of the PATH environment variable
 * @argv: The program name and command line arguments
 */

void execut_exter_cmd(__attribute__((unused)) char *cmd, char **args,
		char *path_var, __attribute__((unused)) char **argv)
{
    /* Check the command path */
    char command_path[BUFFER_SIZE];
    int status;
    pid_t pid;

    if (!check_cmd_path(args[0], command_path, path_var))
    {
                write(STDOUT_FILENO, "sh: 1: ", strlen("sh: 1: "));
        write(STDOUT_FILENO, args[0], strlen(args[0]));
        write(STDOUT_FILENO, ": not found\n", strlen(": not found\n"));
        return;
    }

    /* Fork a child process to execute the command */
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }
    else if (pid == 0)
    {
        /* Execute the command */
        execve(command_path, args, environ);
        /* If execve returns, an error occurred */
        write(STDOUT_FILENO, "sh: 1: ", strlen("sh: 1: "));
        write(STDOUT_FILENO, args[0], strlen(args[0]));
        write(STDOUT_FILENO, ": not found\n", strlen(": not found\n"));
        _exit(127);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
