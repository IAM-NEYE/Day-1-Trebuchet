#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isNumber(char c)
{
    return isdigit(c);
}
int charToDigit(char c) {
    if (c >= '0' && c <= '9') { 
        return c - '0'; 
    } else {
        return -1;
    }
}
#include <stdio.h>
#include <string.h>

void replace_substring(char *str, const char *old_str, const char *new_str) {
    char *pos;
    int index = 0;
    int old_len = strlen(old_str);
    int new_len = strlen(new_str);

    // Search for the substring
    while ((pos = strstr(str + index, old_str)) != NULL) {
        // Make space for the new string
        if (new_len > old_len) {
            memmove(pos + new_len, pos + old_len, strlen(pos + old_len) + 1);
        } else if (new_len < old_len) {
            // Remove extra characters
            memmove(pos + new_len, pos + old_len, strlen(pos + old_len) + 1);
        }

        // Copy the new string over the old one
        memcpy(pos, new_str, new_len);
        index = pos - str + new_len; // Move to the next potential match
    }
}

int main()
{
    char line[] = "";
    int first_num, last_num,sum=0;
    FILE *trebuchet;
    trebuchet = fopen("calibration_document.txt", "r");
    if (trebuchet == NULL)
    {
        printf("failed to open the file.");
    }
    else
    {
        printf("the file is opened.\n");
    }
    while (fgets(line, 100, trebuchet) != NULL)
    { // loooop
        first_num = -1;
        last_num = -1;
        for (int i = 0; line[i] != '\n'; i++){
        if (strncmp(line + i, "one", 3) == 0) replace_substring(line,"one","o1e");
                else if (strncmp(line + i, "two", 3) == 0) replace_substring(line,"two","t2o");
                else if (strncmp(line + i, "three", 5) == 0) replace_substring(line,"three","th3ee");
                else if (strncmp(line + i, "four", 4) == 0) replace_substring(line,"four","fo4r");
                else if (strncmp(line + i, "five", 4) == 0) replace_substring(line,"five","fi5e");
                else if (strncmp(line + i, "six", 3) == 0) replace_substring(line,"six","s6x");
                else if (strncmp(line + i, "seven", 5) == 0) replace_substring(line,"seven","se7en");
                else if (strncmp(line + i, "eight", 5) == 0) replace_substring(line,"eight","ei8ht");
                else if (strncmp(line + i, "nine", 4) == 0) replace_substring(line,"nine","ni9e");}
        for (int i = 0; line[i] != '\n'; i++)
        { // loooop
            if (isNumber(line[i]) )
            {
                while (first_num == -1) // loooop
                {
                    first_num = charToDigit(line[i]);
                    last_num = charToDigit(line[i]);
                }
                last_num = charToDigit(line[i]);
            }
        }
        int value = (first_num*10)+last_num;
        sum = sum + value;
    }
    fclose(trebuchet);
    printf("the sum is %d",sum);
    printf("\n");
    return 0;
}
