#include "our_shell.h"

/**
 * main - print name of the program
 * @argc: number of argument
 * credit to imane lag
 * @argv: array name
 * Return:0 success
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *cmd;
	size_t buff_size;
	ssize_t line_length;
	/*Check if reading from a pipe*/
	int is_pipe = !isatty(0);

	should_exit = 0;


	signal(SIGINT, handle_sigint);

	while (!should_exit)
	{
	if (!is_pipe)
	{
		generate_prompt();
	}

	cmd = NULL;
	buff_size = 0;
	line_length = getline(&cmd, &buff_size, stdin);
	if (line_length == -1)
		{
		if (isatty(0))
		my_putstring("\n");
		break;
		}
	/*Remove the trailing newline character*/
	cmd[strcspn(cmd, "\n")] = '\0';

	if (strlen(cmd) > 0)
		{
		/*Execute the command*/
		exect_cmd(cmd, argv, path_var);
		}
		free(cmd);
	}
	return (0);
}
