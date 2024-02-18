//type of tracking to do,
//copy as system shuts down'
//copy asynchronously, when file isn't being changed, etc


enum tType{ONSHUTDOWN,ASYNC};

enum dType{LINUXDRIVE,WINDOWSDRIVE}; //what type of drive to treat it as (what should be the only OS to touch this drive)

enum gType{LINUXGAME,PROTONGAME,WINDOWSGAME}; //what OS type to treat the game, native linux, proton, or WindowsOnlyGame


typedef struct driveFile{
    enum dType driveT;
    int isWindowsCDrive;
    int isReadOnlyonBoot;
    char* name;
    char* mountPoint;
    char* steamAppsFolder; //folder location can differ
} driveFile;


typedef struct gameFile{
    char* steamID;
    char* name;
    char* folderName;
    int state;
    enum gType gameType;
    enum tType trackingType;

    //if the game has worksshopcontent
    char* workshopPath;

    //if this is a game to be synced
    driveFile* WindowsDrive;

    //parent
    driveFile* parentDrive;
} gameFile;



typedef struct userFile{
    char* steamUserID;
    char* name;
    driveFile** drivesTracked;
    gameFile** gamesTracked; //list of games
} userFile;
