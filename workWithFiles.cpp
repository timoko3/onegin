#include "workWithFiles.h"

#include <sys/stat.h>

static int countStrings(char* buf, int fileSize, char endStr);

static size_t getFileSize();
static FILE* openInputFile();
static char* getTextToBuffer(FILE* inputFile, int fileSize, int* nStrings);
static string* divideBufferToStruct(char* buffer, int nStrings);

static FILE* openOutputFile();
static bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t fileSize);

FILE* openLogFile(){
    FILE* logFile = NULL;

    if(!(logFile = fopen(LOG_FILE_NAME, "w+b"))){
        fprintf(stderr, ALERT_RUNNING_LOGGING_SYSTEM_FAILURE);
        perror(FAILURE_OPEN_LOG_FILE);
        return NULL;
    }

    return logFile;
}

int stringsFromFileToStructure(DataFromInputFIle* DataFromInputFIle){
    assert(DataFromInputFIle);

    if((DataFromInputFIle->fileSize = getFileSize()) == EXIT_FAILURE) return EXIT_FAILURE;

    DataFromInputFIle->inputFile = openInputFile();
    if(!DataFromInputFIle->inputFile) return EXIT_FAILURE;
    assert(DataFromInputFIle->inputFile);

    
    DataFromInputFIle->buffer = getTextToBuffer(DataFromInputFIle->inputFile, DataFromInputFIle->fileSize, &DataFromInputFIle->nStrings);
    assert(DataFromInputFIle->buffer);
    
    fclose(DataFromInputFIle->inputFile);
    
    DataFromInputFIle->bufferSize = DataFromInputFIle->fileSize + SIZE_OF_END_STR;
    
    DataFromInputFIle->strings = divideBufferToStruct(DataFromInputFIle->buffer, DataFromInputFIle->nStrings);
    assert(DataFromInputFIle->strings);
    return 0;
}

int printResultInFile(DataFromInputFIle* DataFromInputFIle){
    assert(DataFromInputFIle);

    FILE* outputFile = openOutputFile();
    if(!outputFile) return EXIT_FAILURE;
    assert(outputFile);

    const char divider[] = "\r\n";

    setvbuf(outputFile, NULL, _IOFBF, 3 * sizeof(char) * (DataFromInputFIle->bufferSize + SIZE_OF_END_STR));

    DataFromInputFIle->strings = sortStrings(DataFromInputFIle->strings, DataFromInputFIle->nStrings, myStrCmpFromBegin);
    if(!(writeSortedToFIle(outputFile, DataFromInputFIle->strings, DataFromInputFIle->nStrings, DataFromInputFIle->bufferSize))) return EXIT_FAILURE;
 
    DataFromInputFIle->strings = sortStrings(DataFromInputFIle->strings, DataFromInputFIle->nStrings, myStrCmpFromEnd);
    FILE_DIVIDER
    if(!(writeSortedToFIle(outputFile, DataFromInputFIle->strings, DataFromInputFIle->nStrings, DataFromInputFIle->bufferSize))) return EXIT_FAILURE;

    FILE_DIVIDER
    fwrite(DataFromInputFIle->buffer, sizeof(char), DataFromInputFIle->bufferSize, outputFile);

    fclose(outputFile);

    return 0;
}

static size_t getFileSize(){
    struct stat file_info = {}  ;

    if(stat(INPUT_FILE_NAME, &file_info) != 0){
        fprintf(stderr, ALERT_GET_INFO_FAILURE);
        perror(GET_FILE_SIZE_ERROR_DESCRIPTION);
        return EXIT_FAILURE;
    }

    return file_info.st_size;
}

static FILE* openInputFile(){
    FILE* inputFile = NULL;

    if(!(inputFile = fopen(INPUT_FILE_NAME, "rb"))){
        fprintf(stderr, ALERT_FILE_OPEN_FAILURE, INPUT_FILE_NAME);
        perror(OPEN_INPUT_FILE_ERROR_DESCRIPTION);
        return NULL;
    }

    return inputFile;
}

static char* getTextToBuffer(FILE* inputFIle, int fileSize, int* nStrings){
    assert(inputFIle);
    assert(nStrings);

    char* buffer = (char*) calloc(fileSize + SIZE_OF_END_STR, sizeof(char)); 
    assert(buffer);
    buffer[fileSize] = '\r';
    buffer[fileSize + 1] = '\n';

    fread(buffer, sizeof(char), fileSize, inputFIle);
    
    *nStrings = countStrings(buffer, fileSize, END_STR);

    return buffer;
}

static string* divideBufferToStruct(char* buffer, int nStrings){
    assert(buffer);

    string* strings = (string*) calloc(nStrings, sizeof(string));
    assert(strings);

    strings[0].stringPtr = buffer;

    int curStr = 1;
    int curSym = 0;
    for(curSym = 0; buffer[curSym] != '\0'; curSym++){
        if((buffer[curSym] == END_STR) && (buffer[curSym + 1] != '\0')){
            strings[curStr].stringPtr = buffer + curSym + 1;
            strings[curStr - 1].len = strings[curStr].stringPtr - 
                                      strings[curStr - 1].stringPtr;
            curStr++;
        }
    }

    strings[curStr - 1].len = (buffer + curSym) - strings[curStr - 1].stringPtr;

    return strings;
}

static FILE* openOutputFile(){
    FILE* outputFile = NULL;

    if(!(outputFile = fopen(OUTPUT_FILE_NAME, "w+b"))){
        fprintf(stderr, ALERT_FILE_OPEN_FAILURE, OUTPUT_FILE_NAME);
        perror(OPEN_OUTPUT_FILE_ERROR_DESCRIPTION);
        return NULL;
    }

    return outputFile;
}

static bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t bufferSize){
    assert(outputFile);
    assert(strings);
    
    bool result = true;

    char* outputBuffer = (char*) calloc(bufferSize, sizeof(char));
    assert(outputBuffer);
    
    int curBufInd = 0;
    for(size_t curStrInd = 0; curStrInd < nStrings; curStrInd++){
        size_t curSymInd = 0;
        while(curSymInd < strings[curStrInd].len){
            
            outputBuffer[curBufInd] = strings[curStrInd].stringPtr[curSymInd];
            curSymInd++;
            curBufInd++;
        }
        
    }
    
    if(fwrite(outputBuffer, sizeof(char), bufferSize, outputFile) != bufferSize) result = false;
    free(outputBuffer);

    return result;
}

static int countStrings(char* buf, int fileSize, char endStr){
    assert(buf);

    int nStrings = 1;

    int curSym = 0;
    while(curSym < fileSize){
        if(buf[curSym] == endStr){
            nStrings++;
        }
        curSym++;
    }

    return nStrings;
}
