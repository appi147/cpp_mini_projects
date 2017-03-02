#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILENAME 40
#define KEYNAME 20
int main()
{
	FILE *fileread , *filewrite , *KEY;
	char name[FILENAME] , temp;
	printf ( "Enter name of file\n" );
	scanf ( "%s" , name );
	fileread = fopen ( name , "r" );
	if ( fileread == NULL )
	{
		puts ( "Error loading file" );
		exit ( 1 );
	}
	filewrite = fopen ( "encrypted.txt" , "w" );
	if ( filewrite == NULL )
	{
		puts ( "Error writing file" );
		exit ( 2 );
	}
	char key[KEYNAME];
	printf ( "Enter key to encrypt\n" );
	scanf ( "%s" , key );
	int length , i;
	length = strlen ( key );
	char keycopy[length];
	for ( i = 0 ; i < length ; i++ )
	{
		keycopy[i] = key[i];
		key[i] = toupper ( key[i] );
		key[i] -= 65;
	}
	keycopy[length] = key[length];
	int c = 0;
	while ( true )
	{
		c %= length;
		temp = fgetc ( fileread );
		if ( temp == EOF )
		break;
		else
		{
			if ( temp <= 90 && temp >= 65 )
			{
				temp -= 65;
				temp += key[c];
				c++;
				temp %= 26;
				temp += 65;
				fputc ( temp , filewrite );
			}
			else if ( temp >= 97 && temp <= 122 )
			{
				temp -= 97;
				temp += key[c];
				c++;
				temp %= 26;
				temp += 97;
				fputc ( temp , filewrite );
			}
			else
			{
				fputc ( temp , filewrite );
			}
		}
	}
	printf ( "File successfully encrypted\n" );
	fclose ( fileread );
	fclose ( filewrite );
	KEY = fopen ( "key.txt" , "w" );
	if ( KEY == NULL )
	{
		puts ( "Key could not be printed" );
	}
	for ( i = 0; i < length ; i++ )
	{
		temp = keycopy[i];
		fputc ( temp , KEY );
	}
	fclose ( KEY );
	return 0;
}