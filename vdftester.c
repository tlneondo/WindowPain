
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


    //to get the value of AppState
    //location of string appstate = myVDF->data.data_array.data_value[7]->key
    //myVDF->data.data_array.data_value[5]->data

    printf("\n\n%s", myVDF->data.data_array.data_value[3]->key);
    printf(": %d\n", myVDF->data.data_array.data_value[3]->data);


    // Close the file
    fclose(file);


}
