#include "./includes/vdf.h"
#include <stdlib.h>

int main(){

    struct vdf_object libraryPaths;

    //libraryPaths = malloc(sizeof(struct vdf_object *));
    
    
    libraryPaths = vdf_parse_file("/home/icyjiub/.steam/steam/steamapps/libraryfolders.vdf");

   return 0; 
}

