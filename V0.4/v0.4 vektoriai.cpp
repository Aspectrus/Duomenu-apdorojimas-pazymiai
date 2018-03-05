#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "struktura.h"

using std::endl;
using std::cout;


std::vector<mokinys> duom;
std::vector<mokinys> varg;
std::vector<mokinys> kiet;




main()
{




    int pasirinkimas;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)
        {

            int n=1;
            for (int i=1; i<=5; i++)
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
            break;
        }

        if(pasirinkimas==3)
        {
            checkfile("kursiokai.txt");
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
    std::sort(duom.begin(), duom.end(), [](const mokinys& lhs, const mokinys& rhs)
    {
        return lhs.pavarde < rhs.pavarde;
    });

    spausdinti();
    studentudalijimas();


    return 0;
}

