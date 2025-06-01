#include <stdio.h>
#include <string.h>
#include "parser.h"

Scanner scanner;

static char *read_file(const char *path)
{
	FILE *file = fopen(path, "rb");
	size_t file_size, bytes_read;
	char *buffer;

	if (file == NULL) {
		fprintf(stderr, "Could not open file \"%s\".\n", path);
		exit(74);
	}

	fseek(file, 0L, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	buffer = malloc(file_size + 1);
	if (buffer == NULL) {
		fprintf(stderr, "Not enough memory to read \"%s\".", path);
		exit(74);
	}
	bytes_read = fread(buffer, sizeof(char), file_size, file);
	if (bytes_read < file_size) {
		fprintf(stderr, "Could not read file \"%s\".", path);
		exit(74);
	}
	buffer[bytes_read] = '\0';

	fclose(file);
	return buffer;
}

void init_scanner(char* str){
    scanner.start = str;
    scanner.end = str;
}

static char advance(void) {
    scanner.end++;
    return scanner.end[-1];
}

static char peek(void) {
    return scanner.start[0];
}

static void skip_ws(void) {
    char c = peek();
    while (c == ' ' || c == '\t' || c == '\r' || c == '\n')
        c = advance();
}

static Token make_token(TokenType type) {
    Token token;
    token.type = type;
    token.start = scanner.start;
    token.len = scanner.end - scanner.start;
    return token;
}

static Token number(void) {
    /* advance while current char is digit */
    /* error if unexpected character */
    return make_token(TOKEN_INT);
}

Token scan_token(void) {
    char c;

    skip_ws();
    scanner.start = scanner.end;

    c = advance();
    if (isdigit(c) || c == '-') {
        return number();
    }

    if (isalpha(c)) {
        return string();
    }

    switch (c) {
        case '(': return make_token(TOKEN_LPAREN);
        case ')': return make_token(TOKEN_RPAREN);
        default: return error_token("Unexpected character.");
    }
}


int str_to_int(char *str){
    char *current=str;
    int result =0;
    int sign =1;
    if(*current== '-')
    {
        sign = -1;
        str++;
    }
    while (*current>= '0' && *current<= '9'){

        result = result * 10 + (*current- '0');
        current++;
    }
    
    return result* sign;
}
    










