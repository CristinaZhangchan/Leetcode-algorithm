#include <stdio.h>

int climbStairs(int n ) {
    int tab[n+1];
    if (n >= 0) tab[0] = 1;
    if (n >= 1) tab[1] = 1;
    for (int i =2; i <= n; i++) 
        tab[i] = tab[i - 1]+ tab[i-2];
    
    return tab[n];
}

int main() {
    int n;
    printf("Enter number of stairs: ");
    scanf("%d", &n);

    int res = climbStairs(n);
    printf("Number of ways to climb %d stairs: %d\n", n, res);

    return 0;
}