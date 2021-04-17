#include<stdio.h>
 
typedef enum {
    S0, S1, S2
} State;
 
int is_separator(char c)
{
    if (c == ' ' || c == ',' || c == '\n' || c == 9) {
        return 1;
    }
    return 0;
}
int is_small(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}
 
 
int main(void)
{
    int vowelLetters = 1065233;
    char c;
    int prew = 0;
    int first = 0;
    int last = 0;
    int sep = 0;
    State state = S0;
    unsigned int set = 0;
 
    while ((c = getchar()) != EOF) {
        if (!is_separator(c)) {
            if (is_small(c)) {
                set = 1u << (c - 'a');
            } else {
                set = 1u << (c - 'A');
            }
        }
        switch (state) {
            case S0:
                if (sep) {
                    if (last && first) {
                        printf("Yes\n");
                        return 0;
                    } else {
                        last = 0;
                        first = 0;
                        sep = 0;
                        prew = 0;
                    }
                }
                if (vowelLetters & set) {
                    first = 1;
                }
                state = S1;
                break;
            case S1:
                if (is_separator(c)) {
                    if (vowelLetters & prew) {
                        last = 1;
                    }
                    sep = 1;
                    state = S2;
                } else {
                    state = S1;
                }
                break;
            case S2:
                if (is_separator(c)) {
                    state = S2;
                } else {
                    if (last && first) {
                        printf("Yes\n");
                        return 0;
                    } else {
                        last = 0;
                        first = 0;
                        sep = 0;
                        prew = 0;
                    }
                    if (vowelLetters & set) {
                        first = 1;
                    }
                    state = S1;
                }
 
        }
        prew = set;
        if (last && first) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
