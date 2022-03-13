#include <windows.h>
#include <iostream>

int main() {
    //code that just returns 5+5 (10)
    static const int code_lenght = 44;
    unsigned char opcodes[code_lenght] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\xcc";

    HANDLE mem_handle = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_EXECUTE_READWRITE, 0, code_lenght, NULL);

    void* mem_map = MapViewOfFile(mem_handle, FILE_MAP_ALL_ACCESS | FILE_MAP_EXECUTE, 0x0, 0x0, code_lenght);

    memcpy(mem_map, opcodes, sizeof(opcodes));

    std::cout << ((int(*)())mem_map)() << std::endl;

    return 0;
}