#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILENAME 40
#define KEYNAME 20
//a=97 z=122 A=65 Z=90
int main()
{
	FILE *ncrypt , *KEY , *dcrypt;
	char name[FILENAME] , temp;
	ncrypt = fopen("encrypted.txt","r");
	if (ncrypt==NULL)
	{
		puts("Error loading encrypted file");
		exit(1);
	}
	dcrypt = fopen("decrypted.txt","w");
	char key[KEYNAME];
	printf ("Enter key to decrypt\n");
	scanf ("%s",key);
	int length,i;
	length = strlen(key);
	char keycopy[length];
	for (i = 0; i < length; i++)
	{
		key[i] = toupper(key[i]);
		key[i] -= 65;
	}
	int c = 0;
	while (true)
	{
		c %= length;
		temp = fgetc(ncrypt);
		if (temp == EOF)
		break;
		else
		{
			if (temp <= 90 && temp >= 65)
			{
				temp -= 65;
				temp += 26;
				temp -= key[c];
				c++;
				temp %= 26;
				temp += 65;
				fputc(temp , dcrypt);
			}
			else if (temp >= 97 && temp <= 122)
			{
				temp -= 97;
				temp += 26;
				temp -= key[c];
				c++;
				temp %= 26;
				temp += 97;
				fputc(temp , dcrypt);
			}
			else
			{
				fputc(temp , dcrypt);
			}
		}
	}
	printf ("File successfully decrypted\n");
	fclose (ncrypt);
	fclose (dcrypt);
	return 0;
}

