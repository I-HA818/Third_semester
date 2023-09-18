#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *file = fopen("test_code.c", "r"); 
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    char c, prev = ' ';
    int line_num = 1;
    bool in_single_line_cmnt = false;
    bool in_multi_line_cmnt = false;
    bool print_line_number = false; 

    printf("Line number : Comments \n");

    while ((c = fgetc(file)) != EOF) {
        if (print_line_number) {
          
            print_line_number = false;
        }

        if (c == '\n') {
            line_num++;
            print_line_number = true;
        }

        if (in_single_line_cmnt) {
            if (c == '\n') {
                in_single_line_cmnt = false;
                putchar(c);
                print_line_number = true;
            } else {
                putchar(c);
            }
        } else if (in_multi_line_cmnt) {
            putchar(c);
            if (prev == '*' && c == '/') {
                in_multi_line_cmnt = false;
                putchar('\n');
                print_line_number = true;
            }
        } else if (prev == '/' && c == '/') {
            in_single_line_cmnt = true;
            printf("%d:",line_num);
            putchar('/');
            putchar(c);
        } else if (prev == '/' && c == '*') {
            in_multi_line_cmnt = true;
             printf("%d:",line_num);
            putchar('/');
            putchar(c);
        }

        prev = c;
    }

    fclose(file);

    return 0;
}
