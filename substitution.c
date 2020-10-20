#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Declare Functions
int dupl(string n_key, int length);
bool alpha_check(string n_key);

//Main funcrion with var for command line arguments
int main(int argc, string argv[])
{
    //Check the Keys Validity
    if (argc != 2)
    {
        printf("Invalid Entry. You entered %i keys. Enter 1 Key only!\n", (argc - 1));

        return 1;
    }

    int key_len = strlen(argv[1]);

    if (key_len != 26)
    {
        printf("Invalid Entry. You entered %lu characters. Key must be 26 Characters!\n", (strlen(argv[1])));

        return 1;
    }

    int count = dupl(argv[1], key_len);

    if (count > 0)
    {
        printf("Invalid Entry. You entered duplicate characters. Key must contain 26 unique alpha characters\n");

        return 1;
    }
    else if (!alpha_check(argv[1]))
    {
        printf("Invalid Entry. You have entered non alpha charcters. Key must only contain letters!\n");

        return 1;

    }

    //Take User input
    string plain_s = get_string("plaintext: ");
    string prime = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int plain_len = strlen(plain_s);
    char output[plain_len];
    char k[26];
    int diffs[26];

    //Convert Plain to Cipher
    for (int i = 0; i < 26; i++)
    {
        k[i] = toupper(argv[1][i]);

        diffs[i] = prime[i] - k[i];
    }

    //Ouput Ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < plain_len; i++)
    {
        if (isalpha(plain_s[i]))
        {
            if (isupper(plain_s[i]))
            {
                int ind = (plain_s[i] - 'A');
                output[i] = plain_s[i] - diffs[ind];
            }
            else if (islower(plain_s[i]))
            {
                int ind = (plain_s[i] - 'a');
                output[i] = plain_s[i] - diffs[ind];
            }
        }
        else
        {
            output[i] = plain_s[i];
        }

        printf("%c", output[i]);
    }

    printf("\n");



}

//Functions
int dupl(string n_key, int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (n_key[i] == n_key[j])
            {
                count++;
            }
        }
    }

    return count;
}

bool alpha_check(string n_key)
{
    for (int i = 0; i < strlen(n_key); i++)
    {
        if (!isalpha(n_key[i]))
        {
            return false;
        }
    }
    return true;
}
