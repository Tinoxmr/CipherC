//
//  Cipher_file library for C
//  Created by TinoXMR
//  18/06/2020
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IN_FILE "message.txt"
#define OUT_FILE "ciphered.txt"

#define CIPHER_KEY 2

//Cipher an input string
//pass to 'in' the string you want to cipher and to 'out' 
//the address where the ciphered string will be located
void cipher(char* in, char* out);

//Decipher an input string
void decipher(char* in, char* out);

//Utility functions to copy an entire file to a large single string and vice-versa
void fileToString(FILE* f, char* str);
void stringToFile(char* str, FILE* f);
