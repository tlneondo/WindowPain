
#include <stdio.h>
#include <stdlib.h>
#include "vdf.h"


int main(int argc, char *argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }



    struct vdf_object* myVDF = malloc(sizeof(struct vdf_object));

    // Open the file for reading
    myVDF = vdf_parse_file(argv[1]);

    vdf_print_object(myVDF);

    // Close the file
    fclose(file);


}
