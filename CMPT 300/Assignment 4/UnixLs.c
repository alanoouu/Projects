#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void nodeOptioni(DIR *dirParam, struct dirent *fileParam) {
    struct stat fileinode;

    while ((fileParam = readdir(dirParam)) != NULL) {
        stat(fileParam->d_name, &fileinode);
        printf("%s\n", fileParam->d_name);
        printf("inode number: %d\n\n", fileinode.st_ino);
    }
}

void printStats (DIR *dirParam, struct dirent *fileParam) {
    while ((fileParam = readdir(dirParam)) != NULL) {
        printf("%s\n", fileParam->d_name);
    }
}

int main(int argc, char *argv[]) {

    DIR *directory;
    struct dirent *file;

    // For no command entered
    if (argc <= 1) {
        printf("No command entered");
        return -1;
    }

    // For -i
    if (argc > 2) {
        if (*argv[2] == '-') {
            directory = opendir(".");
            nodeOptioni(directory, file);
        }
        return 0;

        // For ls
    } else if (*argv[1] == 'l') {
        directory = opendir(".");
        printStats(directory, file);
        // For other
    } else {
        directory = opendir(argv[1]);
        printStats(directory, file);
    }

    // To check if directory is valid
    if (directory == NULL) {
        perror("Unable to open folder.");
        return -1;
    }

    closedir(directory);

    return 0;
}