#include <stdio.h>
#include <time.h>
#include "arbitaryCommand.c"

// これがmainになるのか知らんけどとりあえず
int main ()
{
    /* 定数一覧（Linuxのコマンド） 
    　　とりあえずこのくらい　　　 */
    char commandLs[] = {"ls"}; // listコマンド
    const char commandCd[] = {"cd"}; // change directoryコマンド
    const char commandMv[] = {"mv"}; // moveコマンド
    const char commandCp[] = {"cp"}; // copyコマンド

    enum command
    {
        ls,
    };

    enum command com;

    FILE *fp; // FILE型構造体
    // 目的ないから、ファイル名指定してるよ〜
	char fname[] = "test.txt";
	int chr;
    double cpuTime;

    // コマンドのパターン（色々と追加していくよ〜）
    switch (com)
    {
    case(ls):
        // arbitaryCommand.cのメソッドを呼び出ししているよ〜
        printf("lsの呼び出し時間：%f\n", arbitaryCommand(&commandLs[0]));
        break;
    
    default:
        break;
    }

	return 0;
}