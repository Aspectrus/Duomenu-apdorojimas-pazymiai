#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using std::endl;
using std::cout;
float vidurkis(int *, int );
float mediana (int *, int );
main()
{
    std::string vardas, pavarde;
    std::cin>>vardas>>pavarde;
    int pasirinkimas, k, egzaminas;
    int *a = new int;
    int *pazymiai=new int;
    int ilgis=0;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n";
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)
        {
            unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
            std::mt19937 generator(seed);
            std::uniform_int_distribution<int> distribution(1, 10);
            ilgis=distribution(generator);
            delete[] pazymiai;
            pazymiai=new int[ilgis];
            for(int i=0; i<ilgis; i++)
            {
                *(pazymiai+i)=distribution(generator);
            }
            egzaminas=distribution(generator);
            break;
        }
        if(pasirinkimas==2)
        {
            cout<<"Iveskite pazymius\nNorint baigti iveskite -1"<<endl;
            delete[] pazymiai;
            while(true)
            {
                std::cin>>k;
                if(k==-1) break;
                if(ilgis==0)  *a=k;
                else
                {
                    pazymiai=new int[ilgis+1];
                    std::copy(a, a+ilgis, pazymiai);
                    *(pazymiai+ilgis)=k;
                    delete[] a;
                    a=pazymiai;
                }
                ilgis++;
            }
            cout<<"Iveskite egzamino rezultata"<<endl;
            std::cin>>egzaminas;
            break;
        }
    }
    cout<<"1-mediana\n2-vidurkis\n";
    float galBalas;
    while(std::cin>>pasirinkimas)
    {
        if(pasirinkimas==1)
        {
            galBalas=mediana(pazymiai, ilgis)*0.4+0.6*egzaminas;
            break;
        }
        if(pasirinkimas==2)
        {
            galBalas=vidurkis(pazymiai, ilgis)*0.4+0.6*egzaminas;
            break;
        }
    }
    cout<<vardas<<"\t"<<pavarde<<"\t";
    for(int  i=0; i<ilgis; i++)
    {
        cout<<pazymiai[i]<<"\t";
    }
    cout<<egzaminas<<"\t"<<galBalas;
    return 0;
}
float vidurkis(int *pazymiai, int ilgis)
{
    float sum=0;
    for( int i=0; i<ilgis; i++ )
    {
        sum+=pazymiai[i];
    }
    return sum/ilgis;
}
float mediana (int *pazymiai, int ilgis)
{
    std::sort (pazymiai, pazymiai+ilgis);
    if(ilgis%2==0) return (pazymiai[ilgis/2]+pazymiai[ilgis/2-1])/float(2);
    else return pazymiai[ilgis/2];
}
