#include <stdio.h>
#include <cs50.h>

int main(void){

    int number = get_int("Enter the height of the pyramid ");
    int i = 1;
    while(i <= number){
        for(int j = 1; j<=i; j++){
            printf("#");
        }printf("\n");
        i++;
    }
}
