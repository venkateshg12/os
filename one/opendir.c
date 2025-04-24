#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directory operations

int main() {
    char dirname[256]; // Buffer to store the directory name
    DIR *dir;          // Pointer to a DIR structure
    struct dirent *entry; // Structure to hold directory entry information

    // Prompt the user to enter a directory name
    printf("ENTER DIRECTORY NAME: ");
    scanf("%s", dirname);

    // Open the directory
    dir = opendir(dirname);
    if (dir == NULL) { // Check if the directory exists
        printf("The given directory does not exist\n");
        return 1; // Exit with an error code
    }

    // Read and print the contents of the directory
    printf("Contents of the directory '%s':\n", dirname);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name); // Print each file/directory name
    }

    // Close the directory
    closedir(dir);

    return 0; // Exit successfully
}