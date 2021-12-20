#include <stdio.h>
#include <time.h>
#include <sys/time.h>


// double timeStart = 0;
// double *timerStart = &timeStart;
// double timeEnd = 0;
// double *timerEnd = &timeEnd;
// 各コマンドの実行時間を計測するための変数
// typedef struct timeval {
// long tv_sec;
// long tv_usec;
// } calcTime;
// struct calcTime calc;


// タイマー開始時の時刻を記録 
time_t countStart() 
{
    struct timeval startTime;
    return gettimeofday(&startTime, NULL);
}

// タイマー終了時の時刻を記録
time_t countEnd()
{
    struct timeval endTime;
    struct tm *timeEn;
    return gettimeofday(&endTime, NULL);
}

// 経過時間を測定する
double lapTime(time_t *startTime, time_t *endTime)
{
    // double lapTime = *timerEnd - *timerStart / CLOCKS_PER_SEC;
    return *endTime - *startTime;
}
