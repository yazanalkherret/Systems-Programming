#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
const int MAX_INPUT = 1024;
char *arg_list[150]; // For storing tokens of the input command
pid_t pid;
int status;

void tokenizeCommand(char *str) {
	int i = 0;
	const char delim[] = " ";
	arg_list[i] = strtok(str, delim); // Get the first token
// Continue to get the rest of the tokens
	while (arg_list[i] != NULL) {
		arg_list[++i] = strtok(NULL, delim); // Get the next token
	}
}
int main(void) {
	char input[MAX_INPUT];
	printf("Welcome to Simple Shell! Type 'exit' to quit.\n");


	while(1) {
		printf("\n> ");
		fgets(input, MAX_INPUT, stdin); // Used fgets() instead of gets() for safety (compiler issued warning when using gets())
        input[strcspn(input, "\n")] = '\0'; // Remove the newline character
		if(!strcmp(input, "exit"))//Breaks loop if the user inputs "exit"
			break;

		tokenizeCommand(input);

		pid = fork();
		if(pid == 0) {
            //Child process
			execvp(arg_list[0], arg_list);
			fprintf(stderr, "Error: Command not found\n");
			exit(EXIT_FAILURE);
		}
		else {
            //Parent process
			int w = waitpid(pid, &status, 0);

			if (w == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status))
			{
				printf("\nexited, status=%d\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("\nkilled by signal %d\n", WTERMSIG(status));
			}
			else if (WIFSTOPPED(status))
			{
				printf("\nstopped by signal %d\n", WSTOPSIG(status));
			}
			else if (WIFCONTINUED(status))
			{
				printf("\ncontinued\n");
			}
		}
	}

	printf("Goodbye!\n");
	return 0;
}

