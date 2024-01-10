#include "icyDataTypes.h"
#include <stdio.h>>
#include <string.h>

//"contructors"

userFile* buildUser(){

    userFile newU = malloc(sizeof(userFile*));

    //get steam user ID from steam folder

    //set name from steam user


    //set head of list of files

    newU->listofDrives = malloc(sizeof(driveFile*));


    

    



    return newU;
}

driveFile* buildDFile(enum dType d, int cDrive, int rwob, char* nm, char* mnt, userFile* p){

    driveFile* newD = malloc(sizeof(driveFile*));
    newD->driveT = d;
    newD->isWindowsCDrive = cDrive;
    newD->isReadOnlyonBoot = rwob;
    newD->name = malloc(strlen(nm) * sizeof(char*));
    newD->mountPoint = malloc(strlen(mnt) * sizeof(char*));

    /*
    //count games
    int count = 0;


    newD->gamesInDrive  = malloc(sizeof(gameFile*) * count);

    //pass list of games found to GfileBuilder

    for(int = 0; i < count; i++){





    }
    */

    //link to parent user
    newD->parent = p;

    return newD;
}


gameFile* buildGFile(char* id,char* nm, char* rootPath, char* vfn, char* WINEpath, enum gType g, enum tType t){
    gameFile* newG = malloc(sizeof(gameFile*));
    newG



    //check if there are workshop files
    if(){

    }



}

