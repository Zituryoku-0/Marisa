﻿#include <stdio.h>
#include <stdlib.h>

void commandLs(FILE *fp, int BUF)
{
    // const int BUF = 256;
    // FILE *fp;
    char buf[BUF];
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        printf("=> %s", buf);
    }
    pclose(fp);
}