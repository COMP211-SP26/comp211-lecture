#include "Exec.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static pid_t spawn_tree(Node* node, int input_fd, int output_fd);
static void close_if_needed(int fd);

void exec_tree(Node* node) {
    if (!node) {
        return;
    }

    pid_t pid = spawn_tree(node, STDIN_FILENO, STDOUT_FILENO);
    if (pid < 0) {
        return;
    }

    waitpid(pid, NULL, 0);
}

static pid_t spawn_tree(Node* node, int input_fd, int output_fd) {
    if (!node) {
        return -1;
    }

    if (node->type == NODE_COMMAND) {
        // TODO: Parent creates a child process
        pid_t pid;

        if (pid == 0) {
            // TODO: Child redirects stdin

            // TODO child redirects stdout

            // TODO child closes original fds

            // TODO: Child replaces iteself with the command
        }

        // TODO: Parent closes fds it no longer needs

        // Parent returns child pid
        return pid;
    }

    if (node->type == NODE_PIPE) {
        // TODO: create a pipe

        // TODO: Start the left side
        // - where should it read from?
        // - where should it write to?
        pid_t left_pid;

        // TODO: Start the right side
        // - where should it read from?
        // - where should it write to?
        pid_t right_pid;

        // TODO: Close both ends of the pipe

        // Wait for left side to finish
        waitpid(left_pid, NULL, 0);

        // Return the pid of the right side
        return right_pid;
    }

    close_if_needed(input_fd);
    close_if_needed(output_fd);
    return -1;
}

static void close_if_needed(int fd) {
    if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO) {
        close(fd);
    }
}