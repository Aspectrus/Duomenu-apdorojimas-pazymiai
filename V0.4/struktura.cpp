#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include "struktura.h"
#include <fstream>
#include <sstream>

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

void read (std::string name)
{
        std::ifstream in (name);
            std::string eil;
            int a=0;
            while(std::getline(in, eil))
            {
                duom.push_back(mokinys());
                std::istringstream ss(eil);
                std::string temp;
                ss>>duom[a].vardas;
                ss>>duom[a].pavarde;
                int num;
                while(ss>>num)
                {
                    duom[a].pazymiai.push_back(num);
                }
                duom[a].egzaminas=duom[a].pazymiai[duom[a].pazymiai.size()-1];
                duom[a].pazymiai.pop_back();
                a++;
            }

}


void filegen(int a)
{

            int n=1;
            for (int i=1; i<=a; i++)
            {
                n*=10;
                std::ofstream out(std::to_string(i)+"irasas.txt");
                for(int j=1; j<=n; j++)
                {
                    out<<"Vardas"+std::to_string(j)+" ";
                    out<<"Pavarde"+std::to_string(j);
                    int c=randomnumber(1,15);

                for(int k=0; k<c; k++)
                    {

                       out<<" "<<randomnumber(1, 10);;

                    }
                    out<<"\n";


                }
            }
}


 void bench(void(*f)())
 {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    std::cout << elapsed<< '\n';

 }



 void irasyti()
 {
      duom.push_back(mokinys());
            cout<<"Vardas:\n";
            std::cin>>duom[0].vardas;
            cout<<"Pavarde:\n";
            std::cin>>duom[0].pavarde;
            cout<<"Pazymiai:(baigti rasykite -1)\n";
            int k;
            while(true)
            {
                std::cin>>k;
                if(k==-1)
                    break;
                duom[0].pazymiai.push_back(k);

            }
            cout<<"Iveskite egzamino rezultata"<<endl;
            std::cin>>k;
            duom[0].egzaminas=k;
            spausdinti();
 }
