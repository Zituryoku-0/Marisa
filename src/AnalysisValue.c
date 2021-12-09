#include <stdio.h>
#include <time.h>

// これがmainになるのか知らんけどとりあえず
int main ()
{
    FILE *fp; // FILE型構造体
    // 目的ないから、ファイル名指定してるよ〜
	char fname[] = "test.txt";
	int chr;
    double cpuTime;
 
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	if(fp == NULL) {
		printf("%s file not open!\n", fname);
		return -1;
	}
 
	while((chr = fgetc(fp)) != EOF) {
		putchar(chr);
	}
 
    cpuTime = (double)clock();
    printf("テキストのアドレス：%d\n", chr);
    printf("CPU時間：%f\n", cpuTime);
	fclose(fp); // ファイルを閉じる
 
	return 0;
}