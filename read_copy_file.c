/*
 * rw -- a program to read from stdio or a file and write it to stdout or a file
 * by red-rackham, 2019
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *prog;

int copy(FILE *input, FILE *output);
FILE* check_and_open(char arg[], char mode[]);

int main(int argc, char *argv[]) 
{
    FILE *input = stdin;
    FILE *output = stdout;
    prog = argv[0];
    int option;
    char *in_filename = NULL;
    char *out_filename = NULL;

    while((option = getopt(argc, argv, "i:o:h")) >= 0)
	switch (option)
            {
	    case 'h' : printf("Usage: rw [OPTION] ... [FILE] ...\n\nOptions:\n  -h:\t\tShow this helptext\n  -i <file>:\tSpecify input file\n  -i <file>:\tSpecify output file\n");
		       return (0);
	    case 'i' : in_filename = optarg;
		       break;
	    case 'o' : out_filename = optarg;
		       break;
	    case '?' : return (1);
	    }

    if(in_filename)
        input = (FILE*) check_and_open(in_filename, "r");
    if(out_filename)
        output = (FILE*) check_and_open(out_filename, "w");

    copy(input, output);
    fclose(input);
    fclose(output);
    return (0);
}

int copy(FILE *input, FILE *output) 
{
    int c;
    while ((c = getc(input)) != EOF)
        putc(c, output);
	return (0);
}

FILE* check_and_open(char arg[], char mode[])
{
    FILE *fp = NULL;
    if((fp = fopen(arg, mode)) == NULL)
    {
        fprintf(stderr, "%s: can't open %s", prog, arg);
	exit(1);
    }
    return fp;
}
