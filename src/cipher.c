//
//  Cipher_file library for C
//  Created by TinoXMR
//  18/06/2020
//

#include "cipher.h"

void cipher(char* in, char* out){
    int k = 0;
    while(*(in+k) != '\0' && *(in+k+1) != '\0'){
        *(out+k) = *(in+k+1);
        *(out+k+1) = *(in+k);
        k += 2;
    }
    if(*(in+k) == '\0'){ *(out+k)='\0';}
    if(*(in+k+1) == '\0'){
        *(out+k) = *(in+k);
        *(out+k+1) = '\0'; 
    }
    k = 0;
    while(*(out+k) != '\0'){
        *(out+k) = *(out+k) + CIPHER_KEY;
        k++;
    }
}

void decipher(char* in, char* out){
    int k = 0;
    while(*(in+k) != '\0' && *(in+k+1) != '\0'){
        *(out+k+1) = *(in+k);
        *(out+k) = *(in+k+1);
        k += 2;
    }
    if(*(in+k) == '\0'){ *(out+k)='\0';}
    if(*(in+k+1) == '\0'){
        *(out+k) = *(in+k);
        *(out+k+1) = '\0'; 
    }
    k = 0;
    while(*(out+k) != '\0'){
        *(out+k) = *(out+k) - CIPHER_KEY;
        k++;
    }
}

void fileToString(FILE* f, char* str){
    char c;
    int k = 0;
    while((c = fgetc(f)) != EOF){
        *(str+k) = c;
        k++;
    }
    *(str+k) = '\0';
}

void stringToFile(char* str, FILE* f){
    int k = 0;
    char c;
    while((c=*(str+k)) != '\0'){
        fputc(c,f);
        k++;
    }
}
