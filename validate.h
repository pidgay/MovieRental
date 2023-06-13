#ifndef MOVIERENTAL_VALIDATE_H
#define MOVIERENTAL_VALIDATE_H
#include <string>
#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

bool validate_text(string* str);
bool validate_float(string *str);
bool validate_int(string *str);

bool  validate_movie(string *str, int type);
bool validate_client(string str);
#endif //MOVIERENTAL_VALIDATE_H
