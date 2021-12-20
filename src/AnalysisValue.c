#include <stdio.h>
#include <time.h>
#include "arbitaryCommand.c"
#define STR(var) #var   //引数にした変数を変数名を示す文字列リテラルとして返すマクロ関数

// これがmainになるのか知らんけどとりあえず
int main ()
{
    /* 定数一覧（Linuxのコマンド） 
    　　とりあえずこのくらい　　　 */
    char commandLs[] = {"ls"}; // listコマンド
    char commandCd[] = {"cd"}; // change directoryコマンド
    char commandMv[] = {"mv"}; // moveコマンド
    char commandCp[] = {"cp"}; // copyコマンド

    enum command
    {
        ls,
        cd,
    };

    enum command *com;

    FILE *fp; // FILE型構造体
    // 目的ないから、ファイル名指定してるよ〜
	char fname[] = "test.txt";
	int chr;
    double cpuTime;
    printf("列挙体の値：%s\n", STR(ls));

    // コマンドのパターン（色々と追加していくよ〜）
    switch (*com)
    {
    case(ls):
        // arbitaryCommand.cのメソッドを呼び出ししているよ〜
        printf("lsの呼び出し時間：%f\n", arbitaryCommand(&commandLs[0]));
        break;
    
    case(cd):
        printf("cdの呼び出し時間：%f\n", arbitaryCommand(&commandCd[0]));
    ;
    default:
        printf("defaultを通っているよ〜\n");
        break;
    }

	return 0;
}