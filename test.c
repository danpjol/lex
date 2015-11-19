#include <stdio.h>
#include "lex.h"
#include "lex.c"

int main(int argc, char *argv[]) 
{
	int tok;
	FILE *fp;
	fp = fopen(argv[1], "r");
	while ((tok = nextTok(fp)) != EOF) 
	{
		printf("%d %s\n", tok, sval);
	}
}
