#include "icyDataTypes.h"
#include <stdio.h>>
#include <string.h>
#include "vdf.h"

//"contructors"

userFile* buildUser(){
    userFile newU = malloc(sizeof(userFile*));


    

    



    return newU;
}

driveFile* buildDFile(enum dType d, int cDrive, int rwob, char* nm, char* mnt, userFile* p){
    driveFile* newD = malloc(sizeof(driveFile*));
    newD->driveT = d;
    newD->isWindowsCDrive = cDrive;
    newD->isReadOnlyonBoot = rwob;
    newD->name = malloc(strlen(nm) * sizeof(char*));
    newD->mountPoint = malloc(strlen(mnt) * sizeof(char*));

   

    //link to parent user
    newD->parent = p;

    return newD;
}


gameFile* buildGFile(char* acf, driveFile* parent, gType g, enum tType t, driveFile* WindowsDest ){
    gameFile* newG = malloc(sizeof(gameFile*));

    struct vdf_object* myVDF = malloc(sizeof(struct vdf_object));
    myVDF = vdf_parse_file(acf); //parse acf file

    newG->steamID = myVDF->data.data_array.data_value[0]->data;
    newG->name = myVDF->data.data_array.data_value[2]->data;
    newG->folderName = myVDF->data.data_array.data_value[4]->data;
    newG->state = myVDF->data.data_array.data_value[3]->data;
    newG->gameType = g;
    newG->trackingType = t;

    //check if there are workshop files


    //set parent
    newG->parentDrive = parent;

    if(g == WINDOWS){
        if(WindowsDest == NULL){
            printf("\n ERROR: Destination Drive not set up.\n");
            return -1;
        }else{
            newG->WindowsDrive = WindowsDest;
        }
    }

    vdf_free_object(myVDF);
    free(myVDF);
    return newG;
}

//call system function to rsync to sync folder contained in gamefile object to Windows Drive
int syncGameFiles(gameFile* gametoSync){
    if(gametoSync == NULL){
        return -1;
        printf("Error in GameFile Sync\n");
    }
    //get source directories from gamefiles
    char* source = strcat(gametoSync->parentDrive->steamAppsFolder,gametoSync->folderName);
    char* sourceACFa = strcat( =gametoSync->parentDrive->steamAppsFolder, "appmanifest_");
    char* sourceACFb = strcat(sourceACFa, gametoSync->steamID);
    char* sourceACFfin = strcat(sourceACFb, ".acf");
    char* dest = strcat(gametoSync->WindowsDrive->steamAppsFolder,gametoSync->folderName);
    char* destACF = gametoSync->WindowsDrive->steamAppsFolder;

    printf("Syncing Game to Windows Partition\n");
    //sync folders
    system("rsync -avu " source " " dest");
    //sync acf files

    system("rsync -avu " sourceACFfin " " destACF " ");
    printf("Sync Complete\n");

    return 0;
}