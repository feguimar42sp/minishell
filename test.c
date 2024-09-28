
#include <stdio.h>
#include <unistd.h>

extern char **environ; // Declare environ

int main(int argc, char *argv[]) {
    // Print all environment variables
    for (char **env = environ; *env != 0; env++) {
        printf("%s\n", *env);
    }
    return 0;
}