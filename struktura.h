#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include <list>
#include <deque>

struct mokinys
{
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
};


float vidurkis(std::vector<int>);
float mediana (std::vector<int>);
void spausdinti();
int randomnumber(int, int);
void studentudalijimas();
void checkfile(std::string);
void read(std::string);
void filegen(int);
void irasyti(std::vector<mokinys>);
template <typename T>void spausdinti(T duom);

#endif // STRUKTURA_H_INCLUDED
