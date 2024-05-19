#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//������ 
int countCharacters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("δ�ҵ���Ӧ�ļ�");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}
//������ 
int countWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("���ļ�����");
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    int state = 0; // 0 - outside word, 1 - inside word
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',') {
            if (state == 1) {
                state = 0;
                count++;
            }
        } else {
            if (state == 0) {
                state = 1;
            }
        }
    }
    if (state == 1) {
        count++;
    }
    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    if (strcmp(parameter, "-c") == 0) {
        int charCount = countCharacters(filename);
        printf("�ַ�����%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        int wordCount = countWords(filename);
        printf("��������%d\n", wordCount);
    } else {
        printf("�������\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
