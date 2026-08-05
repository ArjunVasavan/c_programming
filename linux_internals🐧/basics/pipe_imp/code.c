/*
┌────────────────────────────────────────────────────────────────────────────┐
│                          DOCUMENTATION DETAILS                             │
├────────────────────────────────────────────────────────────────────────────┤
│                                                                            │
│  Author          Arjun Vasavan                                             │
│  Date            December 12, 2025                                         │
│  Description     Program to implement 'n' pipes to execute 'n+1' command   │
│                                                                            │
│                                                                            │
└────────────────────────────────────────────────────────────────────────────┘
SAMPLE EXECUTION
────────────────────────────────────────────────────────────────────────────────

1-> ./pipe (No arguments)
   Error: No arguments passed, Provide atleast one pipe or more
   Usage: ./pipe <command1> '|' <command2>
   Usage: ./pipe <command1> '|' <command2> '|' <command3> etc

2-> ./pipe ls '|' wc
    5 25 4

3-> ./pipe ls -l '|' grep "pattern" '|' wc -l 
    5 5 25
────────────────────────────────────────────────────────────────────────────────
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: No arguments passed, Provide atleast one pipe or more\n");
        fprintf(stderr, "Usage: %s <command1> '|' <command2>\n", argv[0]);
        fprintf(stderr, "Usage: %s <command1> '|' <command2> '|' <command3> etc\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int command_index[argc];
    int index = 0;
    command_index[0] = 1;
    index += 1;
    int total_pipe_count = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            argv[i] = NULL;
            command_index[index] = i + 1;
            index += 1;
            total_pipe_count += 1;
        }
    }
    
    if (total_pipe_count > 0) {
        if (command_index[0] >= argc || (total_pipe_count > 0 && command_index[total_pipe_count] >= argc)) {
            fprintf(stderr, "Error: Invalid pipe placement\n");
            exit(EXIT_FAILURE);
        }
    }
    
    // Create all pipes needed
    int pipes[total_pipe_count][2];
    for (int i = 0; i < total_pipe_count; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
    
    // Fork processes for each command
    for (int i = 0; i <= total_pipe_count; i++) {
        pid_t pid = fork();
        
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        
        if (pid == 0) {  // Child process
            // If not the first command, redirect stdin from previous pipe
            if (i > 0) {
                if (dup2(pipes[i-1][0], STDIN_FILENO) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            
            // If not the last command, redirect stdout to next pipe
            if (i < total_pipe_count) {
                if (dup2(pipes[i][1], STDOUT_FILENO) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            
            // Close all pipe file descriptors
            for (int j = 0; j < total_pipe_count; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            
            execvp(argv[command_index[i]], argv + command_index[i]);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    
    // Parent closes all pipe file descriptors
    for (int i = 0; i < total_pipe_count; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    
    // Wait for all children
    for (int i = 0; i <= total_pipe_count; i++) {
        if (wait(NULL) == -1) {
            perror("wait");
        }
    }
    
    return 0;
}
