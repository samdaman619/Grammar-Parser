/*
 Sami Badra: masc0673
 
 CS 530, Spring 2015
 Assignment #3, parser
 FILE: parser.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_INPUT 256

char sentence[MAX_INPUT];
int position;
char next;
void Z();
void S();
void E();
void V();
void P();
void C();
void scan();
void error(char n);

/*checks for proper grammer within 'Z' clause*/
void Z() {
    S();
    while (isalpha(next))  //cycle through multiple statements within sentence
        S();
}

/*checks for proper grammer within 'S' clause*/
void S() {
    if (isalpha(next)) {  //check if next char is in alphabet
        scan();
        if (next == '=') {  //check for equals sign
            scan();
            E();
            if (next == ';') scan();  //check for semi-colon
            else error(';');
        }
        else error('=');
    }
    else error(3);
}

/*checks for proper grammer within 'E' clause*/
void E() {
    V();
    while (next == '+' || next == '-') {  //cycle through as as long as next char is '+' or '-'
        scan();
        V();
    }
}

/*checks for proper grammer within 'V' clause*/
void V() {
    P();
    while (next == '*' || next == '/') {  //cycle through as as long as next char is '*' or '/'
        scan();
        P();
    }
}

/*checks for proper grammer within 'P' clause*/
void P() {
    C();
    if (next == '^') {  //check for a power operator
        scan();
        P();
    }
}

/*checks for proper grammer within 'C' clause*/
void C() {
    if (isalpha(next) || isdigit(next))
        scan();
    else if (next == '(') {
        scan();
        E();
        if (next == ')') scan();
        else error(')');
    }
    else error(4);
}

/*scans for the next non-whitespace character*/
void scan() {
    while (isspace(next = sentence[position++]))
        ;
}

/*prints error, with a brief description*/
void error(char n) {
    if (n == 1) {
        printf("*** ERROR: Too many )'s\n");
        exit(1);
    }
    else if (n == 2) {
        printf("*** ERROR: Too many ('s\n");
        exit(1);
    }
    int i;
    for (i=0; i<position-1; i++) {  //put spaces up to position where error occured
        printf(" ");
    }
    printf("^error here\n");	//the '^' symbol will point to where error occured
    if (n == 3) {
        printf("*** ERROR: '%c' is not assignable\n", next);
        exit(1);
    }
    else if (n == 4) {
        printf("*** ERROR: Invalid expression\n");
        exit(1);
    }
    else {
        printf("*** ERROR: '%c' Expected before '%c'\n", n, next);
        exit(1);
    }
}

/*checks for matching left/right parenthesis*/
void checkParenthesis() {
    int i=0, left=0, right=0;
    for (i; i < MAX_INPUT; i++) {
        if (sentence[i] == '(') left++;
        else if (sentence[i] == ')') right++;
        else if (sentence[i] == (char)NULL) break;
    }
    if (left < right) error(1);
    else if (left > right) error(2);
}

int main() {
    position = 0;
    printf("Please enter a sentence to parse:\n");
    scanf("%[^\n]s", sentence);
    checkParenthesis();
    scan();
    Z();
    if (next != '$') error('$');
    else printf("Successful parse\n");
    return 0;
}
