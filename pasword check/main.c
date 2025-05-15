#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_CYAN    "\x1b[36m"




int isStrongPassword(const char *password) {
    int length = 0;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    while (password[length] != '\0') {
        char ch = password[length];

        if (ch >= 'A' && ch <= 'Z')
            hasUpper = 1;
        else if (ch >= 'a' && ch <= 'z')
            hasLower = 1;
        else if (ch >= '0' && ch <= '9')
            hasDigit = 1;
        else if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) ||
                 (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126))
            hasSpecial = 1;

        length++;
    }

    if (length < 8)
        return 0;

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int containsSpace(const char *password) {
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}

int main() {





    printf(ANSI_COLOR_CYAN"##      ##  ######  ##     ######   ######    #       #  ######\n");
    printf("##      ##  ##      ##     #       #       #  ##     ##  ##\n");
    printf("##  ##  ##  ####    ##     #       #       #  #  #  # #  ####\n");
    printf("##  ##  ##  ##      ##     #       #       #  #   #   #  ##\n");
    printf(" ###  ###   ######  ###### ######   ######    #       #  ######\n"ANSI_COLOR_RESET);



    printf("\n\n");

    printf("##############################\n");
    printf("##   PASSWORD   CHECKER    ##\n");
    printf("##############################\n");
    printf("\n\n\n");


        FILE *file = fopen("passwords.txt", "r");

    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }




    char password[100];

    printf("\t\t#############################\n");
    printf("\t\t##  ENTER YOUR PASSWORD   ##\n");
    printf("\t\t#############################\n\n");

    fgets(password, sizeof(password), stdin);

    // Remove newline character
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] == '\n')
            password[i] = '\0';
        i++;
    }

    if (containsSpace(password)) {

    printf(ANSI_COLOR_GREEN"\t\t########################################\n");
    printf("\t\t## " ANSI_COLOR_RED "Invalid password (contains spaces)" ANSI_COLOR_GREEN " ##\n");
    printf(ANSI_COLOR_GREEN"\t\t########################################\n\n"ANSI_COLOR_RESET);


    } else if (isStrongPassword(password)) {
    printf(ANSI_COLOR_GREEN"\t\t#############################\n");
    printf("\t\t## YOUR PASSWORD IS STRONG ##\n");
    printf("\t\t#############################\n\n"ANSI_COLOR_RESET);


    } else {
    printf(ANSI_COLOR_RED"\t\t#############################\n");
    printf("\t\t## YOUR PASSWORD IS WEAK   ##\n");
    printf("\t\t#############################\n\n"ANSI_COLOR_RESET);
    }

    return 0;
}


