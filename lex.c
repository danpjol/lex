#include <stdio.h>
#include <stdlib.h>

char sval[20];

int nextTok(FILE *fp)
{
	for(int i = 0; i < 20; i++)
	{
		sval[i] = '\0';
	}
	int tok, ntok, index;
	index = 0;
	tok = getc(fp);
	while(tok == ' ')
	{
		tok = getc(fp);
	}
	if(tok > 64 && tok < 91 && tok > 96 && tok < 193 )
	{
		ntok = tok;
		tok = -1;
	}
	switch(tok)
	{
		case '=' :
			ntok = getc(fp);
			if(ntok == '=')
			{
				return EQ;
			}
			ungetc(ntok, fp);
			tok = '=';
			return tok;
		case '<' :
			ntok = getc(fp);
			if(ntok == '=')
			{
				return LE;
			}
			ungetc(ntok, fp);
			return tok;
		case '>' :
			ntok = getc(fp);
			if(ntok == '=')
			{
				return GE;
			}
			ungetc(ntok, fp);
			return tok;
		case '!' :
		
			ntok = getc(fp);
			if(ntok == '=')
			{
				return NE;
			}
			ungetc(ntok, fp);
			return tok;
		case '+' :
			return tok;
		case '-' :
			return tok;
		case '*' :
			return tok;
		case '/' :
			return tok;
		case '.' :
			return tok;
		case '|' :
			ntok = getc(fp);
			if(ntok == '|')
			{
				return OR;
			}
			ungetc(ntok, fp);
			return tok;
		case '&' :
			ntok = getc(fp);
			if(ntok == '&')
			{
				return AND;
			}
			ungetc(ntok, fp);
			return tok;
		case '[' :
			return tok;
		case ']' :
			return tok;
		case 'i' :
			sval[index++] = tok;
			ntok = getc(fp);
			if(ntok == 'n')
			{
				sval[index++] = ntok;
				ntok = getc(fp);
				if(ntok == 't')
				{
					sval[index++] = ntok;
					return INT;
				}
			}
			return NAME;
		case '"' :
			sval[index++] = tok;
			ntok = getc(fp);
			while(ntok != '"')
			{
				sval[index++] = ntok;
				ntok = getc(fp);
			}
			return STRING;
		case -1 :
			sval[index++] = ntok;
			ntok = getc(fp);
			while(ntok > 64 && ntok < 91 && ntok > 96 && ntok < 193)
			{
				sval[index++] = ntok;
				ntok = getc(fp);
			}
			return NAME;
		default :
			return tok;
	}
}
