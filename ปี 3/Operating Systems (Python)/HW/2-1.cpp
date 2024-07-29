#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc,char *argv[])
{   int rc = fork();
    if(rc < 0)
    {   fprintf(stderr,"sdadsa");
        exit(1);
    }else if(rc == 0)
    {   printf("1");
    }else
    {   printf("2");
    }
    return 0;
}

