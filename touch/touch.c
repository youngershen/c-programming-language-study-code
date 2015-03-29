#include "touch.h"

void touch(const char* filename, bool safe)
{
    if(safe)
    {
        int file = open(filename, O_RDONLY);

        if(file != -1)
        {
            
            struct stat buf;

            int stat_ret = fstat(file, &buf);
        
            if(stat_ret != -1)
            {

                //printf("access time : %s\r\n", buf.st_atime);
                //printf("modify time : %s\r\n", buf.st_mtime);
                //printf("change time : %s\r\n", buf.st_ctime);

            }
        }


    }
    else
    {
        int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 777);

        if(file != -1)
        {
            printf("file does not exists but created now");
        }
        else
        {
            printf("fiel does not exists and file created failed");
        }
    }
}


int main(int argc, char ** argv)
{
    char * filename = argv[1];

    printf("%s\r\n", filename);
    
    touch(filename, true);
    
    return 0;
}
