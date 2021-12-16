﻿#include <stdio.h>
#include <time.h>
#include <sys/time.h>

double timeStart = 0;
double *timerStart = &timeStart;
double timeEnd = 0;
double *timerEnd = &timeEnd;

// タイマー開始時の時刻を記録 
void countStart() 
{
    timeStart = time(NULL);
    printf("timeStartの時間：%f\n", timeStart);
}

// タイマー終了時の時刻を記録
void countEnd()
{
    timeEnd = time(NULL);
    printf("timeEndの時間：%f\n", timeEnd);
}

// 経過時間を測定する
double lapTime()
{
    // double lapTime = *timerEnd - *timerStart / CLOCKS_PER_SEC;
    return *timerEnd - *timerStart;
}
