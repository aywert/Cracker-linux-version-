#include "../INCLUDE/GeneralLib.h"
#include "../INCLUDE/Constants.h"

const char* FileName = "..\\..\\..\\..\\DOSBox\\TOHACK\\HK.COM";
int ByteToChange = 20;

CrackStatus CrackCode(void)
{
    FILE* FileToHack = fopen(FileName, "rb");
    if (FileToHack == NULL) // returns zero if file is succesfully opened
        return FailCrack;
    else
    {
        // struct stat file_inf = {};
        // stat(file_name, &file_inf);
        struct stat file_inf = {};
        stat(FileName, &file_inf);

        unsigned char* buffer = (unsigned char*)calloc((size_t)file_inf.st_size + 1, sizeof(unsigned char));

        if (!buffer)
            return FailCrack;

        size_t read = fread(buffer, sizeof(unsigned char), (size_t)file_inf.st_size, FileToHack);
        printf("read = %zu\n", read);
        if (read != 0)
            buffer[ByteToChange] = 0;

        fclose(FileToHack); FileToHack = NULL;

        FILE* FileToHack = fopen(FileName, "wb");
        if (FileToHack) // returns zero if couldn`t open file
        {
            printf("broke here\n");
            return FailCrack;
        }

        size_t written = fwrite(buffer, sizeof(unsigned char), (size_t)file_inf.st_size, FileToHack);
        printf("written = %zu\n", written);

        free(buffer);
        fclose(FileToHack);
        return SuccCrack;
    }
}