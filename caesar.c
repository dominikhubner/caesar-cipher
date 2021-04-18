#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
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
            string text = get_string("plaintext: ");
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