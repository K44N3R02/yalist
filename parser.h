#ifndef parser_h
#define parser_h

typedef enum {
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_INT,
    TOKEN_STR
} TokenType;

typedef struct {
    TokenType type;
    char* start;
    int len;
} Token;

typedef struct {
    char* start;
    char* end;
} Scanner;

Scanner scanner;
/*
(1 (  2 3)   )
lparen
num 1
lparen
num 2
num 3
rparen
rparen 
*/

Token scan_token(void);

#endif