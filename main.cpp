#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "struktura.h"
#include <chrono>
#include <list>
#include <deque>
#include <sstream>

using std::endl;
using std::cout;
using std::cin;




std::vector<mokinys> varg;
std::vector<mokinys> kiet;

  std::vector<mokinys> duom;
  std::list<mokinys> listduom;
  std::deque<mokinys> deqduom;


void sorting(  std::deque<mokinys> duom)
{

}
void sorting(  std::list<mokinys> listduom)
{

}
void sorting(  std::vector<mokinys> deqduom)
{
     std::sort(deqduom.begin(), deqduom.end(), [](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });

}
bool a (const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            }
template<typename Container>
inline void read(Container& z, std::string name)
{
    std::ifstream in (name);
    std::string eil;
    double b=0;

    while(std::getline(in, eil))
    {
               z.push_back(mokinys());
               auto it=z.end();
       it--;

        std::istringstream ss(eil);
        ss>>(*it).vardas;
        ss>>(*it).pavarde;
        int num;
        while(ss>>num)
        {


            (*it).pazymiai.push_back(num);
            b++;
        }
        b=0;//
         (*it).egzaminas=(*it).pazymiai[(*it).pazymiai.size()-1];
        (*it).pazymiai.pop_back();



    }
     //z.sort(a);
std::ofstream out("a.txt");

for (auto i: z)
  out << i.pavarde << '\n';




}




main()
{


  std::vector<mokinys> duom;
  std::list<mokinys> listduom;
  std::deque<mokinys> deqduom;



    std::string pasirinkimas;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::getline(cin, pasirinkimas))
{


        if (pasirinkimas=="1")
        {





           int n=6;
          filegen(n);


                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                read(duom, std::to_string(i)+"irasas.txt");
                cout<<duom.size()<<" - ";
                duom.clear();
                //studentudalijimas();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";

             }

     break;
}




        else  if(pasirinkimas=="2")
        {
         irasyti(duom);
            break;
        }

       else if(pasirinkimas=="3")
        {

            checkfile("kursiokai.txt");
            read(duom,"kursiokai.txt");
            std::sort(duom.begin(), duom.end(), [](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });


           spausdinti(duom);
            break;
        }


    else

    { break;
		cout << "Invalid input. Try again. " << endl;

    }
}








    return 0;
}

