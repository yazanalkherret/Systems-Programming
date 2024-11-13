Assignment Description (given by professor)

Objective:

In this assignment you should implement a simple shell application. The goal of this assignment is to
assess your understanding of process management through the use of fork() and waitpid()
system calls. You will develop a simple shell that can execute commands by creating child processes
and waiting for them to finish.

Assignment Description:
Create a simple shell program in C that:
- Prompts the user to enter a command.
- Creates a child process using fork() to execute the command.
- The parent process waits for the child to complete using waitpid().
- The shell should continue running until the user types "exit" to quit.

Requirements:

Basic Functionality:
- Prompt the user to enter a command (e.g., ls, pwd, date).
- Use fork() to create a child process that will run the command.
- Use execvp() or a similar exec function to execute the command inside the child
process.
- Use waitpid() in the parent process to wait for the child to finish before prompting
for another command.

Error Handling:
- Handle invalid commands gracefully (e.g., "Command not found").
- Print appropriate error messages.