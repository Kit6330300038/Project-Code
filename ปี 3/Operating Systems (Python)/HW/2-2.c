#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{   int rc = fork();
    if(rc < 0)
    {   printf("fork failed");
        exit(1);
    }else if(rc == 0)
    {   printf("this is child\n");
        int a = wait(NULL);
        printf("%d\n",a);
    }else
    {   wait(NULL);
        printf("this is parent\n");
    }

    return 0;
}
