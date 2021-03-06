#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <chrono>
#include <iostream>

struct mokinys
{
    std::string vardas, pavarde;
    float galmed, galvid;
    std::vector<int> pazymiai;
    int egzaminas;
};
const int n=6; //failu skaicius

float vidurkis(std::vector<int>);
float mediana (std::vector<int>);
int randomnumber(int, int);
void checkfile(std::string);
void filegen(int);
void irasyti(std::vector<mokinys>&);
void sorting(std::deque<mokinys> & );
void sorting(std::list<mokinys> & );
void sorting(std::vector<mokinys> & );
bool isnumber(const std::string&);
void s();
void e();

#include "struktura.hpp"

#endif // STRUKTURA_H_INCLUDED
