#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
bool isValid(char* s) {
    int n=strlen(s);
    char str[n];
    int j = -1;
    for (int i = 0; s[i] != '\0'; i++) 
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            str[++j]=s[i];
        else{
            if ( j == -1 || (s[i] == ')' && str[j] != '(') || (  s[i] == ']' && str[j] != '[' ) || (s[i] == '}' && str[j] != '{'))
                return false;
            j--;
        }
    return j == -1;
}
*/
bool isValid(char* s) {
    char *q = s;
    for(char *p = s; *p; p++) 
        switch(*p) {
            case '(': *q++ = ')'; continue;
            case '{': *q++ = '}'; continue;
            case '[': *q++ = ']'; continue;
            default : if (q == s || *p != * --q) return false;       
    }
    return q == s;    
}
int main(void) {
    bool result = true;
    char *cha = "}{";
    result = isValid(cha);
    printf("%s\n",result ? "true" : "false");
}