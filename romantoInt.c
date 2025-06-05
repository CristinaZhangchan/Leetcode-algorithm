#include <stdio.h>
int getInt(char s);
int main(void) {
    char s[]= "MCMXCIV";
    int result= 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(getInt(s[i]) < getInt(s[i+1])){
            result -= getInt(s[i]);

        }else{
        result +=  getInt(s[i]);
        }
    }
    printf("%i\n",result);
}


int getInt(char s){
    switch(s) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default :return 0;
    }
}