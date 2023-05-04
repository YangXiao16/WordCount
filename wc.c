#include <stdio.h>
#include <string.h>

int count_chars(char *filename); 
int count_words(char *filename);

int main(int argc, char *argv[]) {
    char *filename;
    int count;

    // 获取参数和文件名
    if (argc == 3) {
        if (strcmp(argv[1], "-c") == 0) {
            count = count_chars(argv[2]);
            printf("Number of characters:%d\n", count); 
        } else if (strcmp(argv[1], "-w") == 0) {
            count = count_words(argv[2]);
            printf("Number of words:%d\n", count);
        } 
    } else {
        printf("Usage: %s [-c/-w] [filename]\n", argv[0]);
        return 1;
    }

    return 0;
}

// 统计字符数
int count_chars(char *filename) {
    FILE *fp = fopen(filename, "r");
    int count = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }

    fclose(fp);
    return count; 
}

// 统计单词数 
int count_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    int count = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == ',' || ch == '\n') {
            count++;
        }
    } 
    count++; // 最后一个单词后没有分隔符,需要加1
    fclose(fp);
    return count;
}