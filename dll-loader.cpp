#include <Windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if arguments are provided
    if (argc < 2) {
        printf("Usage: dll-loader.exe <file.dll>\n");
        return EXIT_FAILURE;
    }

    // Get DLL file path
    const char* dll_file = argv[1];
    printf("Loading %s...\n", dll_file);

    // Load DLL
    HINSTANCE hDLL = LoadLibraryA(dll_file);  // Use LoadLibraryA for ANSI

    // Error handling
    if (!hDLL) {
        printf("Failed to load DLL. Error code: %lu\n", GetLastError());
        return EXIT_FAILURE;
    }

    printf("DLL successfully loaded!\n");

    // Free the DLL after use
    FreeLibrary(hDLL);
    
    return EXIT_SUCCESS;
}

