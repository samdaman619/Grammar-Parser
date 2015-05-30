
Copyright 2015 Sami Badra. All Rights Reserved.

Sami Badra: masc0673

CS 530, Spring 2015

Assignment #3, parser

FILE: README


##Description
This program will determine if a certain input is valid for the set of grammar rules found below. The program will output “Successful parse” if the input is correct. If not, it will identify where the error was encountered and identify what kind of error it was.


##grammer rules:
    <Z> ::= <S> {<S>}$
    <S> ::= char = <E>;
    <E> ::= <V> {( + | - ) <V>}
    <V> ::= <P> {( * | / ) <P>}
    <P> ::= <C> ^ <P> | <C>
    <C> ::= char | ( <E> ) | digit

NOTE: It is important to note that the operands MUST CONSIST OF SINGLE numeric digits, and SINGLE alphabetic characters, separated by an operator (i.e. = + - * / ^).

This is a grammar for a simple language consisting of a sequence of assignment statements, terminated by semicolons. The whole program is terminated by the symbol ‘$’.


##Sample input

`a = 6; e = m * c^2; c = h^ (t-5+ (g^n-9) +k^4 *u); $`


##Operating Instructions
1. Compile and run the program (with no arguments)
2. Program will ask for user to input a sentence to parse
3. Enter one or more expressions on one line, each followed by ';'
4. Put a '$' sign at the end of the last expression in the sentence, and click enter
4. Program outputs "Successful parse" if sentence is correct, ERROR otherwise
