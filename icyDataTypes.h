//type of tracking to do,
//copy as system shuts down'
//copy asynchronously, when file isn't being changed, etc
enum tType{ONSHUTDOWN,ASYNC};

enum dType{LINUX,WINDOWS}; //what type of drive to treat it as

enum gType{LINUX,PROTON,WINDOWS}; //what OS type to treat the game, native linux,
                                //proton, or windows game that needs reboot

typedef struct userFile{
    char* steamUserID;
    char* name;
    driveFile* listofDrives;

    gameFile* ntfsGames; //shorthand for windows games to track and sync



} userFile;

typedef struct driveFile{
    enum dType driveT;
    int isWindowsCDrive;
    int isReadOnlyonBoot;
    char* name;
    char* mountPoint;
    gameFile* gamesInDrive; //list of games in the drive

    //parent
    userFile* parent;
} driveFile;


typedef struct gameFile{
    char* steamID;
    char* name;
    char* pathToRootFolder;
    char* vdfFileName;
    char* pathToWINEprefix;
    enum gType gameType;
    enum tType trackingType;

    //if the game has worksshopcontent
    char* workshopPath;

    //parent
    driveFile* parent;
} gameFile;


userFile* buildUser(){

}

driveFile* buildDFile(){

}


gameFile* buildGFile(){



}
