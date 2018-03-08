#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "struktura.h"
#include <chrono>
#include <list>

using std::endl;
using std::cout;
using std::cin;


std::vector<mokinys> duom;
std::vector<mokinys> varg;
std::vector<mokinys> kiet;




main()
{




    std::string pasirinkimas;
    std::chrono::high_resolution_clock::time_point   start;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::getline(cin, pasirinkimas))
{


        if (pasirinkimas=="1")
        {


            int n=6;
            filegen(n);
            for(int i=1; i<=n; i++)
            {
                start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                read(std::to_string(i)+"irasas.txt");
                cout<<duom.size()<<" - ";
                studentudalijimas();
                duom.clear();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";

            }
 break;

        }
        else  if(pasirinkimas=="2")
        {
            irasyti();
            break;
        }

       else if(pasirinkimas=="3")
        {
            start = std::chrono::high_resolution_clock::now();
            checkfile("kursiokai.txt");
            read("kursiokai.txt");
            std::sort(duom.begin(), duom.end(), [](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });


            spausdinti();
            break;
        }


    else

    {
		cout << "Invalid input. Try again. " << endl;

    }
}








    return 0;
}

