#include "our_shell.h"

/**
 * generate_prompt - Generate  shell prompt
 */


void generate_prompt(void)
{
	/*Check if reading from a terminal*/
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$", 1);
	}
}
