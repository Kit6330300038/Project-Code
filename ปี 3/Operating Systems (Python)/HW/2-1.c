#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{   int x=100;
    int rc = fork();
    if(rc < 0)
    {   printf("fork failed");
        exit(1);
    }else if(rc == 0)
    {   printf("this is child\n");
        x/=4;
    }else
    {   printf("this is parent\n");
        x+=3;
    }
    printf("%d\n",x);
    x*=2;
    printf("%d\n",x);
    return 0;
}
