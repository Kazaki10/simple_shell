#include "our_shell.h"

/**
 * handle_sigint - Signal handler for SIGINT
 * @signum: The signal number
 *by oubaha & zaki
 */

void handle_sigint(__attribute__((unused))int signum)
{

	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
