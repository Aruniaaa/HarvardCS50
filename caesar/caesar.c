#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_key(string key);


int main(int argc, string argv[]){


    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else{
        int key = atoi(argv[1]);
        string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lower = "abcdefghijklmnopqrstuvwxyz";
        string plaintext = get_string("Enter the plaintext: ");
        int size = strlen(plaintext);
        char cipher[size + 1];
        for(int i = 0; i< size; i++){

            char c = plaintext[i];

            if(isupper(c)){
                cipher[i] = 'A' + (c - 'A' + key) % 26;
            }
            else if(islower(c)){
                cipher[i] = 'a' + (c - 'a' + key) % 26;
            }
            else if(ispunct(c) || isdigit(c)){
                cipher[i] = c;
            }
        


        }
        cipher[size + 1] = '\0';
        printf("ciphertext: %s\n", cipher);


    }
}


bool check_key(string key){
    int n = strlen(key);

    for(int i= 0; i< n; i++){
        if(isdigit(key[i]) == 0){
            return false;
        }
    }
    return true;
}
