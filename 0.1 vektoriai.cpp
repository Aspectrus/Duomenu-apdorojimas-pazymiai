#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using std::endl;
using std::cout;
float vidurkis(std::vector<int> );
float vidurkis(std::vector<int> pazymiai)
{
    float sum=0;
    for( std::size_t i=0; i<pazymiai.size(); i++ )
    {
        sum+=pazymiai[i];
    }
    return sum/pazymiai.size();
}
float mediana (std::vector<int> );

float mediana (std::vector<int> pazymiai)
{    std::sort (pazymiai.begin(), pazymiai.end());
    if(pazymiai.size()%2==0) return (pazymiai[pazymiai.size()/2]+pazymiai[pazymiai.size()/2-1])/float(2);
    else return pazymiai[pazymiai.size()/2];
}
main()
{
    std::string vardas, pavarde;
    std::cin>>vardas>>pavarde;
    int pasirinkimas, k, egzaminas;
    std::vector<int> pazymiai;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n";

    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)   {  unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
   std::mt19937 generator(seed);
   std::uniform_int_distribution<int> distribution(1, 10);
 int  n=distribution(generator);
        for(int i=0; i<n; i++)
            {
                k=distribution(generator);
                pazymiai.push_back(k);
            }
            egzaminas=distribution(generator);
break;
        }
        if(pasirinkimas==2)   {  cout<<"Iveskite pazymius\nNorint baigti iveskite -1"<<endl;
    while(true)
    {
        std::cin>>k;
        if(k==-1) break;
        pazymiai.push_back(k);

    }   cout<<"Iveskite egzamino rezultata"<<endl;
    std::cin>>egzaminas;break;}

    }


    cout<<"1-mediana\n2-vidurkis\n";
    float galBalas;
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)   {galBalas=mediana(pazymiai)*0.4+0.6*egzaminas;break;}
        if(pasirinkimas==2)   {galBalas=vidurkis(pazymiai)*0.4+0.6*egzaminas;break;}

    }

   cout<<vardas<<"\t"<<pavarde<<"\t";
   for(std::size_t  i=0; i<pazymiai.size(); i++)
   {
       cout<<pazymiai[i]<<"\t";
   }
   cout<<egzaminas<<"\t"<<galBalas;

    return 0;
}
