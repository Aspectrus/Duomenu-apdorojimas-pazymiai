#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include <list>
#include <deque>
#include <sstream>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using std::endl;
using std::cout;
using std::cin;
struct mokinys
{
    std::string vardas, pavarde;
    float galmed, galvid;
};



float vidurkis(std::vector<int>);
float mediana (std::vector<int>);
int randomnumber(int, int);
//template <typename T>void studentudalijimas(T , T , std::vector<int> , mokinys );
void checkfile(std::string);
void filegen(int);
void irasyti(std::vector<mokinys>);
void read2(std::vector<mokinys>&, std::string);
void sorting(std::deque<mokinys> & duom);
void sorting(std::list<mokinys> & listduom);
void sorting(std::vector<mokinys> & deqduom);
#include "struktura.hpp"




#endif // STRUKTURA_H_INCLUDED
