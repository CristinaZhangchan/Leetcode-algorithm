#include <stdio.h>
#include <stdlib.h>


int main(void){
    int randomNum;
    scanf("%d", &randomNum);

    printf("your provided number is: %d \n", randomNum);

    int copy = randomNum;
    int modvalue = 0;
    int  res = 0;
    while(copy > 0){
        modvalue = copy % 10;
        res = res * 10 + modvalue;
        copy /= 10; 
    }
    if (res == randomNum) {
        printf("Your palindrome of the number is same as the number you provided :)\n");
    }
    else{
        printf("Your palindrome of the number is not same as the number you provided :(\n");
    }

    
}

// char c[30];
//     char ch[30];
//     int size = sprintf(c,"%d",x);
//     printf("%s\n",c);
//     printf("%i\n",size);
//     int j = 0;
//     for(int i = size - 1 ; i != -1;i--){
//         ch[j] = c[i];
//         printf("%c\n",ch[j]);
//         j ++; 
//     }
//     ch[j] = '\0';
//     int conversion = atoi(ch);
//     printf("%i\n",conversion);
//     if(conversion == x) {
//         printf("true");}else{
//     printf("false");}