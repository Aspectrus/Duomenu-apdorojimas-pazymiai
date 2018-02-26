#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>

using std::endl;
using std::cout;
float vidurkis(std::vector<int>);
float mediana (std::vector<int>);
void spausdinti();


struct mokinys
{
    std::string vardas{}, pavarde{};
    std::vector<int> pazymiai{};
    int egzaminas{};
};

std::vector<mokinys> duom;

main()
{

    int pasirinkimas, k;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)
        {
            unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
            std::mt19937 generator(seed);
            std::uniform_int_distribution<int> distribution(1, 10);
            int  n=distribution(generator);
            duom.push_back(mokinys());
            cout<<"Vardas:\n";
            std::cin>>duom[0].vardas;
            cout<<"Pavarde:\n";
            std::cin>>duom[0].pavarde;
            for(int i=0; i<n; i++)
            {
                k=distribution(generator);
                duom[0].pazymiai.push_back(k);
            }
            duom[0].egzaminas=distribution(generator);
            break;
        }
        if(pasirinkimas==2)
        {
            duom.push_back(mokinys());
            cout<<"Vardas:\n";
            std::cin>>duom[0].vardas;
            cout<<"Pavarde:\n";
            std::cin>>duom[0].pavarde;
            cout<<"Pazymiai:(baigti rasykite -1)\n";
            while(true)
            {
                std::cin>>k;
                if(k==-1) break;
                duom[0].pazymiai.push_back(k);

            }
            cout<<"Iveskite egzamino rezultata"<<endl;
            std::cin>>k;
            duom[0].egzaminas=k;
            break;
        }

        if(pasirinkimas==3)
        {
            std::ifstream in ("kursiokai.txt");
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
            break;
        }
    }

    spausdinti();


    return 0;
}
float mediana (std::vector<int> pazymiai)
{
    std::sort (pazymiai.begin(), pazymiai.end());
    if(pazymiai.size()%2==0) return (pazymiai[pazymiai.size()/2]+pazymiai[pazymiai.size()/2-1])/float(2);
    else return pazymiai[pazymiai.size()/2];
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
