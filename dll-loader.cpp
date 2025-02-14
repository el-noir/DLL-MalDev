#include <Windows.h>
#include <stdio.h>
#include <string>
using namespace std;

 int main(int argc, char *argv[]){
    // Check if arguments are provided
    if (argc < 2) {
       // printf("Usage: %s <file_path>\n", argv[0]);
        printf("Run : dll-loader.exe <file.dll>\n");
        return EXIT_FAILURE;
    }

   // get parsed file
    LPCTSTR dll_file = argv[1];
    std:: string file_name = argv[1];
    printf("Loading %s...\n", file_name);

    //load dll
    HINSTANCE hDLL = LoadLibrary(TEXT(dll_file));
    
    return EXIT_SUCCESS;

 }
