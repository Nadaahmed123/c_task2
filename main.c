#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct User {
    char name[50];
    int password;
    int confirm_password;
};

union UserInfo {
    struct {
        struct User user;
        bool active_flag;
    } data;
    int flag;
};


void strToLower(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool isBoolean(const char* str) {

    char lowerStr[10];
    strcpy(lowerStr, str);
    strToLower(lowerStr);

    return strcmp(lowerStr, "true") == 0 || strcmp(lowerStr, "false") == 0;
}


bool parseBoolean(const char* str) {

    char lowerStr[10];
    strcpy(lowerStr, str);
    strToLower(lowerStr);

    return strcmp(lowerStr, "true") == 0;
}

int main() {
    union UserInfo info;
    printf("Registration!\n");
    printf("Enter user_name: ");
    scanf("%s", info.data.user.name);

    if (!((info.data.user.name[0] >= 'a' && info.data.user.name[0] <= 'z') || (info.data.user.name[0] >= 'A' && info.data.user.name[0] <= 'Z'))) {
        printf("First letter shouldn't be a number\n");
        return 0;
    }

    printf("Enter password: ");
    scanf("%d", &(info.data.user.password));

    printf("Confirm your password: ");
    scanf("%d", &(info.data.user.confirm_password));

    if (info.data.user.confirm_password != info.data.user.password) {
        printf("Passwords do not match\n");
        return 0;
    }
    else {
        printf("Registration successful\n");
    }

    char flagInput[10];
    printf("Enter user flag (0, 1, true, or false): ");
    scanf("%s", flagInput);

    if (!isBoolean(flagInput)) {
        printf("Invalid flag value\n");
        return 0;
    }

    info.data.active_flag = parseBoolean(flagInput);

    system("cls");

    printf("LOG IN!\n");

    char n[50];
    int p;
    printf("Enter your name: ");
    scanf("%s", n);

    printf("Enter password: ");
    scanf("%d", &p);

    if (strcmp(n, info.data.user.name) == 0) {
        if (info.data.user.password == p) {
            if (info.data.active_flag) {
                printf("Login successful\n");
            }
            else {
                printf("User is not active\n");
            }
        }
        else {
            printf("Password is not correct\n");
        }
    }
    else {
        printf("Username and/or password are not correct\n");
    }

    return 0;
}
