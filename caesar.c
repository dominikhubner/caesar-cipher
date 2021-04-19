#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        int r = 0;
        for (int i = 0; i < len; i++)
        {
            int character = argv[1][i];
            if (character <= 57 && character >= 48)
            {
                r++;
            }
        }
        if (r == len)
        {
            int number = atoi(argv[1]);
            char *text;
            printf("plaintext: ");
            text = inputString(stdin, 10);
            int length = strlen(text);
            printf("ciphertext: ");
            for (int i = 0; i < length; i++)
            {
                int c = text[i];
                for (int in = 0; in < number; in++)
                {
                    if (c >= 65 && c <= 90)
                    {
                        if (c == 90)
                        {
                            c = 65;
                        }
                        else
                        {
                            c++;
                        }
                    }
                    else if (c >= 97 && c <= 122)
                    {
                        if (c == 122)
                        {
                            c = 97;
                        }
                        else
                        {
                            c++;
                        }
                    }
                }
                printf("%c", c);
            }
            printf("\n");
            free(text);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}

char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}