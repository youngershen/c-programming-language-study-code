#include "touch.h"

void touch(const char* filename, bool safe)
{
    if(safe)
    {
        int file = open(filename, O_RDONLY);

        if(file != -1)
        {
            int ret = utime(filename, NULL);
            if(ret == -1)
            {
                printf("update file access time failed \r\n");
                exit(-1);
            }
        }
    }
    else
    {
        int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 777);

        if(file != -1)
        {
            int ret = utime(filename, NULL);
            if(ret == -1)
            {
                printf("update file access time failed \r\n");
                exit(-1);
            }
        }
        else
        {
            printf("create file failed");
            exit(0);
        }
    }
}

int main(int argc, char ** argv)
{
    char * filename = argv[1];
    touch(filename, false);
    return 0;
}
