#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "struktura.h"
#include <chrono>

using std::endl;
using std::cout;


std::vector<mokinys> duom;
std::vector<mokinys> varg;
std::vector<mokinys> kiet;




main()
{




    int pasirinkimas;
    std::chrono::high_resolution_clock::time_point   start;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)
        {

        filegen(5);

            break;
        }

        if(pasirinkimas==2)
        {
           irasyti();
            break;
        }

        if(pasirinkimas==3)
        {
            start = std::chrono::system_clock::now();
            checkfile("kursiokai.txt");
            read("kursiokai.txt");
            spausdinti();
            break;
        }
    }
    std::sort(duom.begin(), duom.end(), [](const mokinys& lhs, const mokinys& rhs)
    {
        return lhs.pavarde < rhs.pavarde;
    });

    studentudalijimas();


    return 0;
}

