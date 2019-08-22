# CSV-File-Parser
A simple way to parse a column from a CSV file and copy its content to a float array

ParseCSV2float(char *fileName, int column, float *outputArray, int *outputArraySize);

The parsing function ParseCSV2float() takes four arguments, two input and two output arguments as follows:
- filename: input string, name of the CSV file to be parsed.
- column: user input specifying the column of interest to be parsed from the CSV file.
- outputArray: output argument, this array holds the parsed float numbers.
- outputArraySize: output argument, holds the size of the output array (the number of elements parsed from the column).
