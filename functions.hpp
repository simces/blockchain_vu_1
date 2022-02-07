#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include <string>
#include <time.h>
#include <chrono>

#include "includes/md5.h"
#include "includes/sha1.h"
#include "includes/sha256.h"

using namespace std;

string hashing(string);

void consoleInput();

void gen_random_file(int, string);

string gen_random_str(int);

void fileInput();

void comparison();

void collisions();

string transform(char);

void difference();

void readFile(string);

int choiceCheck(int&, int);


#endif