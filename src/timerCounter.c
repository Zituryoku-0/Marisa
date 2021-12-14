#include <stdio.h>
#include <time.h>

double timeStart = 0;
double *timerStart = &timeStart;
double timeEnd = 0;
double *timerEnd = &timeEnd;

// タイマー開始時の時刻を記録 
void countStart() 
{
    timeStart = clock();
}

// タイマー終了時の時刻を記録
void countEnd()
{
    timeEnd = clock();
}

// 経過時間を測定する
double lapTime()
{
    double lapTime = *timerEnd - *timerStart;
    return lapTime;
}
