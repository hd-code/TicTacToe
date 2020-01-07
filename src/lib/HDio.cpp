#include "HDio.hpp"
#include <iostream>

/* ---------------------------- Print to screen ----------------------------- */

template <typename T>
void print(T msg) {
    std::cout << msg;
}

template <typename T, typename ...U>
void print(T msg, U... msgs) {
    print(msg);
    print(msgs...);
}

void println() {
    std::cout << std::endl;
}

template <typename ...T>
void println(T... msgs) {
    print(msgs...);
    println();
}

void clearScreen() {
    for (int i = 0; i < 50; i++) println();
}

/* ----------------------------- Get User Input ----------------------------- */

// helper function, not part of public library
void handleBadInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getUserInput() {
    T result;
    if (!(std::cin >> result)) handleBadInput();
    return result;
}

void getUserInput(char result[]) {
    if (!(std::cin >> result)) handleBadInput();
}

void getUserInput(char result[], size_t maxLen) {
    if(!(std::cin.getline(result, maxLen))) handleBadInput();
}

void getEnter() {
    while (std::cin.get() != "\n"[0]);
}

/* --------------------------- Ask for User Input --------------------------- */

template <typename T>
T askForInput(const char msg[]) {
    println(msg);
    return getUserInput<T>();
}

void askForInput(const char msg[], char result[]) {
    println(msg);
    getUserInput(result);
}

void askForInput(const char msg[], char result[], size_t maxLen) {
    println(msg);
    getUserInput(result, maxLen);
}

void askForEnter(const char msg[]) {
    println(msg);
    getEnter();
}

// -----------------------------------------------------------------------------
// define all templates
#include "HDio.tpp"