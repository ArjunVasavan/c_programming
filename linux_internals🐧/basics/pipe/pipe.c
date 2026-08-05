#include <stdio.h>               // Header file for standard input and output including printf, scanf, etc
#include <fcntl.h>               // Header file for file control operations including open, fcntl, etc
#include <unistd.h>              // Header file for POSIX operating system API including fork, dup, close, etc
#include <sys/types.h>           // Header file for data types including pid_t, off_t, etc
#include <sys/wait.h>            // Header file for wait function including waitpid, WIFEXITED, WEXITSTATUS, etc
#include <string.h>              // Header file for string operations including strcmp, strcpy, strlen, etc
int backup;                      // Backup variable to store the index of the second command after pipe symbol
int main(int argc, char *argv[]) // Main function
{
  int i = 0;    // Index variable
  if (argc < 2) // Check if there are enough arguments
  {
    printf("Error: No arguments passed Usage: ./pipe   <command1 > '|'   <command2> \n"); // Print error message
    return 1;                                                                             // Return 1 to indicate error
  }
  while (i != argc) // Loop through all arguments
  {
    if (strcmp(argv[i], "|") == 0) // Check if the argument is a pipe symbol
    {
      backup = i + 1; // Store the index of the second command
      argv[i] = NULL; // Replace the pipe symbol with NULL to separate the two commands
      break;          // Break the loop
    }
    i++; // Increment index variable
  }
  if (backup == 0) // Check if the pipe symbol was found
  {
    printf("Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2>\n"); // Print error message
    return 1;                                                                                     // Return 1 to indicate error
  }
  int fd[2], status;  // File descriptor array for pipe and status variable for waitpid
  int ret = pipe(fd); // Create a pipe
  int pid1 = fork();  // Child 1
  if (pid1 == 0)      // In Child 1
  {
    close(fd[0]);              // Close unused read end of pipe
    dup2(fd[1], 1);            // Redirect stdout to write end of pipe
    execvp(argv[1], argv + 1); // Execute first command
  }
  else
  {
    int pid2 = fork(); // Child 2
    if (pid2 == 0)     // In Child 2
    {
      close(fd[1]);                        // Close unused write end of pipe
      dup2(fd[0], 0);                      // Redirect stdin to read end of pipe
      execvp(argv[backup], argv + backup); // Execute second command
    }
    else
    {
      sleep(1); // Delay to ensure children have executed

      waitpid(pid1, &status, WNOHANG); // In Parent
      waitpid(pid2, &status, WNOHANG); // Wait for both children to finish
      // Close both ends of pipe in parent
      close(fd[0]);
      close(fd[1]);
      return 0;
    }
  }
}
