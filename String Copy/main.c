
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

void strcpy_array(char t[], const char s[]) {
    for (int i = 0; (t[i] = s[i]) != '\0'; i++);
}

void strcpy_pointer(char *t, const char *s) {
    while ((*t++ = *s++) != '\0');
}

unsigned long strlen(const char *s) {
    unsigned long len = 0;
    while (s[len++] != '\0');
    return len;
}

int main(void) {
    const char *s = "Hello World";
    char *t = (char *)malloc(strlen(s) + 1);

    strcpy_pointer(t, s);
    printf("%s\n", t);

    strcpy_pointer(t, s);
    printf("%s\n", t);

    free(t);
    return 0;
}