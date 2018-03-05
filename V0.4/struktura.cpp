#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include "struktura.h"
#include <fstream>

using std::endl;
using std::cout;

float mediana (std::vector<int> pazymiai)
{
    std::sort (pazymiai.begin(), pazymiai.end());

    if(pazymiai.size()%2==0)
        return (pazymiai[pazymiai.size()/2]+pazymiai[pazymiai.size()/2-1])/float(2);
    else
        return pazymiai[pazymiai.size()/2];
}
float vidurkis(std::vector<int> pazymiai)
{
    float sum=0;
    for( std::size_t i=0; i<pazymiai.size(); i++ )
    {
        sum+=pazymiai[i];
    }
    return sum/pazymiai.size();
}


unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

int randomnumber (int a, int b)
{
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);


}
void spausdinti()
{

    cout<<"Pavarde\t"<<"Vardas\tGalutinis-Vidurkis\tGalutine-mediana\n";
    float galBalas;
    for(std::size_t i=0; i<duom.size(); i++)
    {

        cout<<duom[i].pavarde<<"\t"<<duom[i].vardas<<"\t";
        galBalas=0.6*duom[i].egzaminas+vidurkis(duom[i].pazymiai)*0.4;

        cout<<std::setprecision(3)<<galBalas<<"\t\t\t";
        galBalas=0.6*duom[i].egzaminas+mediana(duom[i].pazymiai)*0.4;

        cout<<std::setprecision(3)<<galBalas<<"\n";


    }

}
void studentudalijimas()
{

    float galBalas;

    for(std::size_t i=0; i<duom.size(); i++)
    {

        galBalas=vidurkis(duom[i].pazymiai);
        if(galBalas>=6)
            kiet.push_back(duom[i]);
        else
            varg.push_back(duom[i]);




    }

}
void checkfile(std::string a)
{
    std::ifstream in;
    in.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try
    {
        in.open (a);
    }
    catch (std::ios_base::failure &fail)
    {
        cout << "Exception opening/reading file";
    }

    in.close();
}
