#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <string.h>

pid_t get_tid() {
    return syscall(SYS_gettid);
}

/* Reads and prints selected task_struct-derived fields from /proc/<pid>/status */
void print_task_struct_info(pid_t pid, pid_t tid, const char* label) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/task/%d/status", pid, tid);

    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    printf("\n===== %s (reading kernel task_struct via %s) =====\n", label, path);

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        /* Print only the fields that map directly to task_struct members */
        if (strncmp(line, "Name:", 5) == 0  ||   /* task_struct->comm */
            strncmp(line, "State:", 6) == 0 ||   /* task_struct->__state */
            strncmp(line, "Tgid:", 5) == 0  ||   /* task_struct->tgid */
            strncmp(line, "Pid:", 4) == 0   ||   /* task_struct->pid */
            strncmp(line, "PPid:", 5) == 0  ||   /* task_struct->real_parent->pid */
            strncmp(line, "Threads:", 8) == 0 ||
            strncmp(line, "VmRSS:", 6) == 0) {   /* from task_struct->mm */
            printf("  %s", line);
        }
    }

    fclose(fp);
}

void* thread_function(void* arg) {
    pid_t my_pid = getpid();
    pid_t my_tid = get_tid();
    print_task_struct_info(my_pid, my_tid, "THREAD's task_struct");
    return NULL;
}

int main() {
    print_task_struct_info(getpid(), getpid(), "MAIN PROCESS's task_struct");

    /* ---------- Create a PROCESS ---------- */
    pid_t pid = fork();
    if (pid == 0) {
        print_task_struct_info(getpid(), getpid(), "CHILD PROCESS's task_struct");
        exit(0);
    }
    waitpid(pid, NULL, 0);

    /* ---------- Create a THREAD ---------- */
    pthread_t tid;
    pthread_create(&tid, NULL, thread_function, NULL);
    pthread_join(tid, NULL);

    return 0;
}
