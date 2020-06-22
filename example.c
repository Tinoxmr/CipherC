#include "src\cipher.h"


int main(){

    FILE* f_in = fopen(IN_FILE,"r");
    if(f_in == NULL){
        printf("Error. Couldn't open specified input file\n");
        return -1;
    }
    FILE* f_out = fopen(OUT_FILE,"w");
    if(f_out == NULL){
        printf("Error. Couldn't open specified output file\n");
        return -1;
    }

    char* txtbody = malloc(1000*sizeof(char));
    fileToString(f_in,txtbody);

    printf("\n%s",txtbody);

    char* ciphred_message = malloc(1000*sizeof(char));
    cipher(txtbody,ciphred_message);

    printf("\n\n%s",ciphred_message);

    char* deciphred_message = malloc(1000*sizeof(char));
    decipher(ciphred_message,deciphred_message);

    printf("\n\n%s\n",deciphred_message);

    stringToFile(ciphred_message,f_out);

    fclose(f_in); 
    fclose(f_out);

    system("PAUSE");
    return 0;

}
