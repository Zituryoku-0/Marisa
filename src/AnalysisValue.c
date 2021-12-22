#include <stdio.h>
#include <time.h>
#include "ExecCommand/commandLs.c"
#define BUF 256

// これがmainになるのか知らんけどとりあえず
int main()
{
    /* 定数一覧（Linuxのコマンド）
    　　とりあえずこのくらい　　　 */
    char Ls[] = {"ls"}; // listコマンド
    char Cd[] = {"cd"}; // change directoryコマンド
    char Mv[] = {"mv"}; // moveコマンド
    char Cp[] = {"cp"}; // copyコマンド

    enum command
    {
        ls,
    };

    enum command com;
    com = ls;

    FILE *fp; // FILE型構造体
    int chr;
    double cpuTime;
    char *cmdline = Ls;
    if ((fp = popen(cmdline, "r")) == NULL)
    {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    // コマンドのパターン（色々と追加していくよ〜）
    switch (com)
    {
    case (ls):
        // arbitaryCommand.cのメソッドを呼び出ししているよ〜
        // printf("lsの呼び出し時間：%f\n", arbitaryCommand(&commandLs[0]));
        printf("lsの呼び出し時間：%d\n", commandLs(fp, BUF));
        // commandLs(fp, BUF);
        break;

    default:
        break;
    }
    return 0;
}