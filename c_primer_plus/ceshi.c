#include <stdio.h>
#include <locale.h>

int main() {
    // 设置本地化环境为中文系统
    setlocale(LC_ALL, "zh_CN.utf8");

    // 打开一个 UTF-8 编码的文件
    FILE *fp = fopen("test.txt", "w+");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }
    char yu[10];
    // 写入一个汉字到文件中
    scanf("%s",&yu);
    fprintf(fp, "%s", yu);

    // 关闭文件
    fclose(fp);

    // 打开一个 UTF-8 编码的文件
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }

    // 读取文件内容并输出到控制台
    char buf[1024];
    fscanf(fp,"%s",buf);
    printf("%s", buf);

    // 关闭文件
    fclose(fp);

    return 0;
}
