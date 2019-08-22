#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void ParseCSV2float(char *fileName, int column, float *outputArray, int *outputArraySize)
{
	char *pch = NULL;
	int i = 0;
	int DelimCount = 0;
	char Buffer[512];
	FILE * file;

	file = fopen(fileName, "r+");
	rewind(file);
	while (!feof(file))
	{
		fgets(Buffer, sizeof(Buffer), file);   //Reads the file line-by-line
		pch = strtok(Buffer, ",");
		while (pch != NULL)
		{
			DelimCount++;
			if (DelimCount == column)
			{
				outputArray[i] = atof(pch);
				//printf("float number is %f\n", outputArray[i]);	//for debugging purposes
				i++;
				DelimCount = 0;
				break;
			}
			pch = strtok(NULL, ",");
			
		}	
	}
	*outputArraySize = i;
	//printf("outputArraySize is: %d\n", outputArraySize);	//for debugging purposes
	fclose(file);
}

void main()
{
	int i = 0;
	float fNumBuffer[315];
	
	ParseCSV2float("TestData1.csv", 2, fNumBuffer, &ArraySize);
	printf("ArraySize is %d\n", ArraySize);
	for (i = 0; i < ArraySize; i++)
	{
		printf("Float number is %f\n", fNumBuffer[i]);
	}

	_getch();
}