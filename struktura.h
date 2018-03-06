#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include <vector>
#include <string>

 struct mokinys
{
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
};
 extern std::vector<mokinys> duom;
   extern std::vector<mokinys> varg;
    extern std::vector<mokinys> kiet;

float vidurkis(std::vector<int>);
float mediana (std::vector<int>);
void spausdinti();
int randomnumber(int, int);

void studentudalijimas();




#endif // STRUKTURA_H_INCLUDED
