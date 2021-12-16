#include <stdio.h>
#include <stdlib.h>
#include "timerCounter.c"
#include "execCommand/commandLs.c"
#define BUF 256

// これはネットで調べたものをまるパクリしたよ〜
// popenについては明日勉強して理解しよう〜
// もしこれよりも効率の良いものがあれば、それにするよ〜
double arbitaryCommand (char *testMessage)
{
    double cpuTime;
    FILE *fp;
    char *cmdline = testMessage;
    if ((fp=popen(cmdline, "r")) == NULL) {
        perror ("popen failed");
        exit(EXIT_FAILURE);
    }

    // 計測開始
    countStart();
    commandLs(fp, BUF);
    /*char buf[BUF];
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        printf("=> %s", buf);
    }*/

    // 計測終了
    countEnd();

    // pclose(fp);

    return lapTime();
}