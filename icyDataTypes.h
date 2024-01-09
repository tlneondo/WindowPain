//type of tracking to do,
//copy as system shuts down'
//copy asynchronously, when file isn't being changed, etc
enum trackType{ONSHUTDOWN,ASYNC};

enum dType{LINUX,WINDOWS};

enum gType{LINUX,PROTON,WINDOWS};

typedef struct userFile{
    char* steamUserID;
    char* name;
    driveFile* listofDrives;

    Game* ntfsGames; //shorthand for windows games to track and sync



} userFile;

typedef struct driveFile{
    enum driveType driveT;
    int isWindowsCDrive;
    int isReadOnlyonBoot;
    char* name;
    char* mountPoint;
    winGame* gamesInDrive; //list of games in the drive

    //parent
    userFile* parent;
} driveFile;


typedef struct Game{
    char* steamID;
    char* name;
    char* pathToRootFolder;
    char* vdfFileName;
    char* pathToWINEprefix;
    enum 
    enum tType trackingType;

    //parent
    driveFile* parent;
} winGame;

