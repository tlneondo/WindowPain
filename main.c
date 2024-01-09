#include "./includes/vdf.h"
#include <stdlib.h>

int main(){

    struct vdf_object libraryPaths;

    //libraryPaths = malloc(sizeof(struct vdf_object *));
    
    
    libraryPaths = vdf_parse_file("/home/icyjiub/.steam/steam/steamapps/libraryfolders.vdf");

    //print objects

    vdf_print_object(libraryPaths);

    //access first library folder
    //create vdf option of it
    //print games in it
    //Installation status

   return 0; 
}

