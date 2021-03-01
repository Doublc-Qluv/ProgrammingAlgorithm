#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int year;
    //year = 2021;
    scanf("%d",&year);
    if (year <= 0)
        printf("Illegal year!");
    else
    {
        printf("Legal year!\n");
        if (year > 1949 && (year-1949) % 10 == 0)
            printf("Correct year!\n");
        else if (year > 1921 && !((year - 1921) % 10))
            printf("correct Year!");
        else if (year % 4 == 0 && year % 100 || year % 400 == 0)
            printf("Leap year!\n");
        else
            printf("Common year!\n");
    }
    
    return 0;
}