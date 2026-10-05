#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    if (len % 2 != 0) {
        return false;
    }

    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(') {
            stack[++top] = ')';
        } else if (c == '{') {
            stack[++top] = '}';
        } else if (c == '[') {
            stack[++top] = ']';
        } else {
            if (top == -1 || stack[top] != c) {
                return false;
            }
            top--;
        }
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a bracket string: ");
    scanf("%s", str);

    if (isValid(str)) {
        printf("Output: Valid (True)\n");
    } else {
        printf("Output: Invalid (False)\n");
    }

    return 0;
}