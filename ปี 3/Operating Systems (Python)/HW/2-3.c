#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

int main (void)
{   int rc = fork();
    int fd = open("/tmp/file",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    if(rc < 0)
    {   printf("fork failed");
        exit(1);
    }else if(rc == 0)
    {   write(fd,"child\n",16);
    }else
    {   write(fd,"parent\n",7);
    }
    close(fd);
    return 0;
}


