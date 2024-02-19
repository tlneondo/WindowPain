#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vdf.h"
#include "icyFunc.h"





//input getter for 100 chars

char* getInput(){

    char input[MAX_INPUT_LENGTH];

    // Print a prompt
    printf("Enter command (or 'exit' to quit): ");

    // Read input from the user
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        exit;
    }

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if the user wants to exit
    if (strcmp(input, "exit") == 0) {
        printf("Exiting program.\n");
        exit;
    }

    // Process the input
    printf("You entered: %s\n", input);
    return input;
}



userFile* buildUser(char* steamID, char* userName){
    userFile* newU = malloc(sizeof(userFile*));
    newU->steamUserID = steamID;
    newU->name = userName;
    newU->driveList = malloc(sizeof((driveNode*) * 50));
    newU->gameList = malloc(sizeof((gameNode*) * 50));

    //temp limit of 50 games, 50 drives

    return newU;
}

void addDrivetoUser(userFile* receive){

    struct tempInput{
        enum dType d;
        int cDrive;
        int rwob;
        char* nm;
        char* mnt;
        userFile* p;
    } tempInput;

    printf("Adding Drive, Please enter info:\n");
    printf("Please Enter LINUXDRIVE or WINDOWSDRIVE\n");
    tempInput.d = getInput();
    printf("Is this drive mounted Read only on Boot?\n");
    tempInput.rwob = getInput();
    printf("What should the name of this drive be?");
    tempInput.nm = getInput();
    printf("Where is this drive mounted?\n");
    tempInput.mnt = getInput();

    driveNode* tempNode;
    driveNode* tempNodeOld;
    tempNode = receive->driveList;

    while(tempNode->next != NULL){
        //iterate to last entry in the node list
        tempNodeOld = tempNode;
        tempNode = tempNode->next;
        tempNodeOld->next = tempNode;
    }

    tempNode->entry =  buildDFile(tempInput.d,tempInput.rwob,tempInput.nm,tempInput.mnt);

    return;
}

void addGametoUser(userFile* receive){

    struct tempInput{
        
=
    } tempInput;

    printf("Adding Drive, Please enter info:\n");
    printf("Please Enter LINUXDRIVE or WINDOWSDRIVE\n");
    tempInput.d = getInput();
    printf("Is this drive mounted Read only on Boot?\n");
    tempInput.rwob = getInput();
    printf("What should the name of this drive be?");
    tempInput.nm = getInput();
    printf("Where is this drive mounted?\n");
    tempInput.mnt = getInput();

    gameNode* tempNode;
    gameNode* tempNodeOld;

    tempNode = receive->gameList;

    
    while(tempNode->next != NULL){
        //iterate to last entry in the node list
        tempNodeOld = tempNode;
        tempNode = tempNode->next;
        tempNodeOld->next = tempNode;
    }

    tempNode->entry =  buildGFile();

    return;
}

driveFile* buildDFile(enum dType d,int rwob, char* nm, char* mnt){
    driveFile* newD = malloc(sizeof(driveFile*));
    newD->driveT = d;

    if(d == WINDOWSDRIVE){
        printf("Is this the main C: drive of a Windows Install? Y or N \n");
        char YNin = 0;

        while(1){
            YNin = getInput();

            if( YNin == 'Y' || YNin == 'N'){
                newD->isWindowsCDrive = YNin;
                break;
            }else{
                printf("Invalid input, please try again.\n");
            }
        }
    }


   
    newD->isReadOnlyonBoot = rwob;

    newD->name = malloc(strlen(nm) * sizeof(char*));
    newD->mountPoint = malloc(strlen(mnt) * sizeof(char*));

    return newD;
}


gameFile* buildGFile(enum gType g, enum tType t, char* acf,  driveFile* linuxSource, driveFile* WindowsDest){
    gameFile* newG = malloc(sizeof(gameFile*));

    struct vdf_object* myVDF = malloc(sizeof(struct vdf_object));
    myVDF = vdf_parse_file(acf); //parse acf file

    newG->steamID = myVDF->data.data_array.data_value[0]->data.data_string.str;
    newG->name = myVDF->data.data_array.data_value[2]->data.data_string.str;
    newG->folderName = myVDF->data.data_array.data_value[4]->data.data_string.str;
    newG->state = myVDF->data.data_array.data_value[3]->data.data_int;
    newG->gameType = g;
    newG->trackingType = t;

    //check if there are workshop files


    //set parent
    newG->parentDrive = parent;

    if(g == WINDOWSGAME){
        if(WindowsDest == NULL){
            printf("\n ERROR: Destination Drive not set up.\n");
            return NULL;
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
    char* sourceACFa = strcat( gametoSync->parentDrive->steamAppsFolder, "appmanifest_");
    char* sourceACFb = strcat(sourceACFa, gametoSync->steamID);
    char* sourceACFfin = strcat(sourceACFb, ".acf");
    char* dest = strcat(gametoSync->WindowsDrive->steamAppsFolder,gametoSync->folderName);
    char* destACF = gametoSync->WindowsDrive->steamAppsFolder;

    printf("Syncing Game to Windows Partition\n");
    //sync folders
    //system("rsync -avu " source " " dest);
    //system("rsync -avu " sourceACFfin " " destACF);
    //sync acf files

    //system("rsync -avu " sourceACFfin " " destACF);
    printf("Sync Complete\n");

    return 0;
}