#include <stdio.h>
#include <sys\stat.h>

#include "workWithFiles.h"
#include "strFunc.h"
#include "UI.h"
#include "logs.h"


int main(void){
    INFO("Start Program");
    
    DataFromInputFIle DataFromInputFIle = {0};
    if(stringsFromFileToStructure(&DataFromInputFIle) == EXIT_FAILURE){
        fprintf(stderr, ALERT_STR_FROM_FILE_TO_STRUCT_FAILURE);
        perror(FAILURE_STRINGS_FROM_FILE_TO_STRUCT);
        ERROR("FAILURE OPEN SOURCE FILE");
        return EXIT_FAILURE;
    }   
    INFO("SUCCESS OPEN SOURCE FILE");
    
    printf(LOADING_IN_FILE);

    if(printResultInFile(&DataFromInputFIle) == EXIT_FAILURE){
        fprintf(stderr, ALERT_STR_FROM_FILE_TO_STRUCT_FAILURE);
        perror(FAILURE_PRINT_RESULT_INF_FILE);
        return EXIT_FAILURE;
        ERROR("FAILURE PRINTING RESULT IN FILE");
    }

    free(DataFromInputFIle.buffer);
    free(DataFromInputFIle.strings);

    printf(SUCCESS_DO_PROGRAMM);
}