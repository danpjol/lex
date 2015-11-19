#ifndef LEX_H_
#define LEX_H_

#define EQ 130
#define NE 131
#define LE 132
#define GE 133
#define AND 134
#define OR 135
#define INTEGER 150
#define DECIMAL 151
#define STRING 152
#define BOOL 153
#define NUL 154
#define NAME 160
#define INT 181
#define DOUBLE 182
#define BOOLEAN 183
#define VOID 184
#define IF 190
#define ELSE 191
#define WHILE 192
#define DO 193
#define FOR 194
#define RETURN 195

int nextTok(FILE *fp);
extern char sval[];

#endif
