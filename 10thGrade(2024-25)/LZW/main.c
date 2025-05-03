#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int size = 0;
char keys[MAX_SIZE][100];
int values[MAX_SIZE];

int getIndex(char key[])
{
    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(char key[], int value)
{
    int index = getIndex(key);
    if (index == -1) {
        strcpy(keys[size], key);
        values[size] = value;
        size++;
    }
    else {
        values[index] = value;
    }
}

int get(char key[])
{
    int index = getIndex(key);
    if (index == -1) {
        return -1;
    }
    else {
        return values[index];
    }
}

void printMap()
{
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}

void aToZ()
{
    for (char c = 'a'; c <= 'z'; c++) {
        char str[2] = {c, '\0'};
        insert(str, c - 'a');
    }
}

void lzwComp(char input[])
{
    int nextCode = size;
    int len = strlen(input);
    char ch1[200] = "";
    char ch12[200] = "";
    ch1[0] = input[0];
    ch1[1] = '\0';

    for (int i = 1; i < len; i++) {
        char c = input[i];
        strcpy(ch12, ch1);
        int curr_len = strlen(ch12);
        ch12[curr_len] = c;
        ch12[curr_len+1] = '\0';

        if (getIndex(ch12) != -1) {
            strcpy(ch1, ch12);
        } else {
            printf("%d ", get(ch1));
            //problemec + 1 next s
            insert(ch12, nextCode);
            ch1[0] = c;
            ch1[1] = '\0';
        }
    }
    printf("\n");
    printMap();
}

int main(void){
    aToZ();
    char input[] = "abcabcabcabc";
    printf("compressed:");
    lzwComp(input);
    return 0;
}