/*
 * Copyright 2018, 2019 Karim El-Rayes. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY HONG XU ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL HONG XU OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of Hong Xu.
 *
 *
 *
 *
 * Author: Karim El-Rayes
 *
*/

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
