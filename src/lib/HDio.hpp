#pragma once

#ifndef HDio_hpp
#define HDio_hpp

#include <stdlib.h>

/* ---------------------------- Print to screen ----------------------------- */

// Prints any number of values of any kind to the screen.
template <typename T>
void print(T msg);

template <typename T, typename ...U>
void print(T msg, U... msgs);

// Prints any number of values of any kind to the screen. At the end a new line
// char is appended.
void println();

template <typename ...T>
void println(T... msgs);

// Clears the console
void clearScreen();

/* ----------------------------- Get User Input ----------------------------- */

// Waits for the user to enter a value. The entered value is then returned by
// this function. If the user enters anything, that can't be interpreted, the
// function returns the default value of the given datatype.
//
// usage:
//      int   number  = getUserInput<int>();
//      float decimal = getUserInput<float>();
//      char  sign    = getUserInput<char>();
template <typename T>
T getUserInput();

// Waits for the user to enter any number of characters. The user input is then
// saved into 'result'.
//
// Attention: this method is unsafe as the user can input as many characters as
// he/she likes. This may cause a buffer overflow.
//
// usage:
//      char input[20];
//      getUserInput(input);
void getUserInput(char result[]);

// Waits for the user to enter any number of characters. The user input is then
// saved into 'result'. 'maxLen' specifies the maximum length of the user input
// (including the NULL-terminating character). The user may enter a longer
// message. However, the input is then clipped accordingly. This method is safe
// to use.
//
// usage:
//      int maxInputSize = 20
//      char input[maxInputSize];
//      getUserInput(input, maxInputSize);
void getUserInput(char result[], size_t maxLen);

// Waits for the user to hit ENTER.
void getEnter();

/* --------------------------- Ask for User Input --------------------------- */

// Displays the given message and waits for the user to enter a value. The
// entered value is then returned by this function. If the user enters anything,
// that can't be interpreted, the function returns the default value of the
// given datatype.
//
// usage:
//      int   number  = askForInput<int>("Please enter a number");
//      float decimal = askForInput<float>("Please enter a number with decimals");
//      char  sign    = askForInput<char>("Please enter any character");
template <typename T>
T askForInput(const char msg[]);

// Displays the given message and waits for the user to enter any number of
// characters. The user input is then saved into 'result'.
//
// Attention: This method is unsafe as the user can input as many characters as
// he/she likes. This may cause a buffer overflow.
//
// usage:
//      char input[20];
//      askForInput("Enter your name", input);
void askForInput(const char msg[], char result[]);

// Displays the given message and waits for the user to enter any number of
// characters. The user input is then saved into 'result'. 'maxLen' specifies
// the maximum length of the user input (including the NULL-terminating
// character). The user may enter a longer message. However, the input is then
// clipped accordingly. This method is safe to use.
//
// usage:
//      int maxInputSize = 20
//      char input[maxInputSize];
//      askForInput("Enter your name", input, maxInputSize);
void askForInput(const char msg[], char result[], size_t maxLen);

// Displays the given message and waits for the user to hit ENTER.
void askForEnter(const char msg[]);

/* -------------------------------------------------------------------------- */

#endif