#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {    
    srand(time(NULL));
    int target = rand() % 100 + 1;
    int myNum = 0;

    for (; myNum != target;) {
        printf("Guess number is: ");
        int success = scanf("%d", &myNum); 
        
        if (success != 1 || myNum > 100 || myNum < 0) {
            printf("myNum is not an integer or bigger than 100 or smaller than 0");
            return 0;
        }
            
        if (myNum > target) {      
            printf("Your guess is bigger than the target!\n");
        } else if (myNum < target) {
            printf("Your guess is small than the target!\n");
        } else {
            printf("Guess right!\n");
            printf("The target number is: %i\n", target);
        }
    }
        
}
    
