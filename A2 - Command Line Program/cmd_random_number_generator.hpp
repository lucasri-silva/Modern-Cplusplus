#ifndef CMD_RANDOM_NUMBER_GENERATOR_HPP
#define CMD_RANDOM_NUMBER_GENERATOR_HPP

using namespace std;

#include <iostream>
#include <random>
#include <cstring>
#include <iomanip>
#include <chrono>

void readArgs(int argc, char *argv[]);
void generateRandomNumbers(bool naturalNum, int qtdNum, int LI, int LS, int decimalPlaces, int64_t seed);

#endif