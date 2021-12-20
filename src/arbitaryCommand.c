#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "timerCounter.c"
#include "execCommand/commandLs.c"
#define BUF 256

// これはネットで調べたものをまるパクリしたよ〜
// popenについては明日勉強して理解しよう〜
// もしこれよりも効率の良いものがあれば、それにするよ〜
double arbitaryCommand (char *testMessage)
{
    time_t cpuTime = 0;
    time_t startTime = 0;
    double endTime = 0;

    FILE *fp;
    char *cmdline = testMessage;
    if ((fp=popen(cmdline, "r")) == NULL) {
        perror ("popen failed");
        exit(EXIT_FAILURE);
    }

    // 計測開始
    time_t start = countStart();
    printf("startTimeの時間：%ld\n", start);
    commandLs(fp, BUF);
    /*char buf[BUF];
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        printf("=> %s", buf);
    }*/

    // 計測終了
    time_t end = countEnd();
    printf("endTimeの時間：%ld\n", end);

    // pclose(fp);

    return lapTime(&start, &end);
}