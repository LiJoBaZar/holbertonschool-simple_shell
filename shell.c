#include "shell.h"

/**
 * main
 *
 *
 *
 */
int main(void)
{
	int exec = 0;
	char *line;
	char **tokens;
	ssize_t num_read;

	while (true)
	{
		if (isatty(STDIN_FILENO) == 1 && exec == 0)
		{
			write(STDOUT_FILENO, "$ ", 2);
			line = read_line(&num_read);
			tokens = token_generate(line, num_read);

			if (num_read == EOF)
			{
				write(2, "Exiting shell....\n", 18);
				exit(0);
			}
			if (num_read == 1)
				continue;

			if (tokens[0] != NULL)
				execute(tokens);
		}
		else
		{
			line = read_line(&num_read);
			write(STDOUT_FILENO, tokens, num_read);
			break;
		}
		free(tokens);
		free(line);
	}
	return (EXIT_SUCCESS);
}
