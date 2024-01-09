//type of tracking to do,
//copy as system shuts down'
//copy asynchronously, when file isn't being changed, etc
enum trackingType{ONSHUTDOWN,ASYNC};

enum driveType{LINUX,WINDOWS};

typedef struct userFile{
    char* steamUserID;
    char* name;
    driveFile* listofDrives;

} userFile;

typedef struct driveFile{
    enum driveType driveT;
    int isWindowsCDrive;
    int isReadOnlyonBoot;
    char* name;
    char* mountPoint;
    winGame* gamesInDrive; //list of games in the drive
    
} driveFile;


typedef struct winGame{
    char* steamID;
    char* name;
    char* pathToRootFolder;
    char* vdfFileName;
    enum trackingType NTFSsyncWhen;

} winGame;