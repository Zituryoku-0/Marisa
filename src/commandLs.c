#include <stdio.h>
#include <stdlib.h>
#define BUF 256

// これはネットで調べたものをまるパクリしたよ〜
// popenについては明日勉強して理解しよう〜
// もしこれよりも効率の良いものがあれば、それにするよ〜
int commandLs (int argc, char *argv[])
{
    FILE *fp;
    char *cmdline = "ls";
    if ((fp=popen(cmdline, "r")) == NULL) {
        perror ("popen failed");
        exit(EXIT_FAILURE);
    }

    char buf[BUF];
    while(fgets(buf, sizeof(buf), fp) != NULL) {
        printf("=> %s", buf);
    }

    pclose(fp);

    return 0;
}