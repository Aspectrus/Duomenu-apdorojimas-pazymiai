#ifndef STRUKTURA_HPP
#define STRUKTURA_HPP
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;



template <typename T> void spausdinti(const T duom)
{

cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15) <<"Vardas"<<std::left<<std::setw(20) <<"Galutinis-Vidurkis"<<std::left<<std::setw(15) <<"Galutine-Mediana\n";
   for(std::size_t i=0; i<duom.size(); i++)
    {

        cout<<std::setw(15)<<duom[i].pavarde<<std::left<<std::setw(15)<<duom[i].vardas<<std::left<<std::setw(20);
        cout<<std::setprecision(3)<<duom[i].galvid<<std::left<<std::setw(15);
        cout<<std::setprecision(3)<<duom[i].galmed<<"\n";


    }

}
template <typename T> void spausdintifaila(const T kiet, const T varg, int i)
{



std::ofstream out("output"+std::to_string(i)+".txt");
out<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15) <<"Vardas"<<std::left<<std::setw(20) <<"Galutinis-Vidurkis"<<std::left<<std::setw(15) <<"Galutine-Mediana\n";
if(kiet.size()!=0)
{out<<"Kieti\n";
 for(auto i:kiet)
    {


        out<<std::setw(15)<<i.pavarde<<std::left<<std::setw(15)<<i.vardas<<std::left<<std::setw(20);
        out<<std::setprecision(3)<<i.galvid<<std::left<<std::setw(15);
        out<<std::setprecision(3)<<i.galmed<<"\n";


    }

}
if(varg.size()!=0)
{out<<"Vargsai\n";
 for(auto i:varg)
    {

        out<<std::setw(15)<<i.pavarde<<std::left<<std::setw(15)<<i.vardas<<std::left<<std::setw(20);
        out<<std::setprecision(3)<<i.galvid<<std::left<<std::setw(15);
        out<<std::setprecision(3)<<i.galmed<<"\n";


    }

}
out.close();


}

template<typename Container>
 void budas1read(std::string name)
{
    Container z, a, b;

    std::ifstream in (name);
    std::string eil;
    mokinys temp;
    while(std::getline(in, eil))
    {
        std::istringstream ss(eil);
        ss>>temp.vardas;
        ss>>temp.pavarde;
        int num;
        while(ss>>num) temp.pazymiai.push_back(num);
        int egzaminas=temp.pazymiai[temp.pazymiai.size()-1];
        temp.pazymiai.pop_back();
        temp.galmed=0.6*egzaminas+mediana(temp.pazymiai)*0.4;
        temp.galvid=0.6*egzaminas+vidurkis(temp.pazymiai)*0.4;
        z.push_back(mokinys(temp));
        temp.pazymiai.clear();

    }
    in.close();
    float galBalas;
     int g=0;
    for(auto i:z)
   {
        galBalas=vidurkis(i.pazymiai);
        if(galBalas>=6) a.push_back(i);
        else b.push_back(i);
   }


 cout<<z.size()<<" - ";
   z.clear();
   a.clear();
   b.clear();
//sorting(a);
//sorting(b);

}
template<typename Container>
 void budas2read(std::string name)
{
    int g=0;
    Container z, a;
    std::ifstream in (name);
    std::string eil;
      mokinys temp;
    while(std::getline(in, eil))
    {
        std::istringstream ss(eil);
        ss>>temp.vardas;
        ss>>temp.pavarde;
        int num;
        while(ss>>num)
        temp.pazymiai.push_back(num);
        temp.egzaminas=temp.pazymiai[temp.pazymiai.size()-1];
        temp.pazymiai.pop_back();
                        temp.galmed=vidurkis(temp.pazymiai);
        z.push_back(mokinys(temp));
                temp.pazymiai.clear();

    }
    in.close();
                        std::partition(z.begin(), z.end(), [](const mokinys& g)
                       {
                        float galBalas=vidurkis(g.pazymiai);
                         return(galBalas>=6);
                       });
                        auto it=std::partition_point(z.begin(), z.end(), [](const mokinys& g)
                       {
                        float galBalas=vidurkis(g.pazymiai);
                         return(galBalas>=6);
                       });
auto e=z.end();
e--;
for(e; e!=it; e--)
{
    a.push_back(*e);
    z.pop_back();

}
a.push_back(*it);
z.pop_back();
     /*  for(auto i=z.begin(); i!=z.end();)
   {
        galBalas=vidurkis((*i).pazymiai);
        if(galBalas>=6){ a.push_back(mokinys(*i)); z.erase(i);     }
        else i++;
   }
*/
 cout<<z.size()+a.size()<<" - ";
   z.clear();
   a.clear();

//sorting(z);
//sorting(a);

}

template<typename Container>
 void budas1 (std::string name)
 {
                cout<<name<<'\n';
          for(int i=1; i<=n; i++)
               {
                s();
                checkfile(std::to_string(i)+"irasas.txt");
                budas1read<Container>(std::to_string(i)+"irasas.txt");
                e();
             }

 }

template<typename Container>
 void budas2(std::string name)
 {
                cout<<name<<'\n';
          for(int i=1; i<=n; i++)
               {
                s();
                checkfile(std::to_string(i)+"irasas.txt");
                budas2read<Container>(std::to_string(i)+"irasas.txt");
               e();
             }

 }
 template<typename Container>
void budas3read(Container& varg, Container& kiet, std::string name)
{
    std::ifstream in (name);
    std::string eil;
    mokinys temp;
    while(std::getline(in, eil))
    {
        std::istringstream ss(eil);
        ss>>temp.vardas;
        ss>>temp.pavarde;
        int num;
        std::vector<int> vtemp;
        while(ss>>num)
            vtemp.push_back(num);
    int egzaminas=vtemp[vtemp.size()-1];
    vtemp.pop_back();
    temp.galmed=0.6*egzaminas+mediana(vtemp)*0.4;
    temp.galvid=0.6*egzaminas+vidurkis(vtemp)*0.4;
       if(vidurkis(vtemp)>=6)
            kiet.push_back(mokinys(temp));
        else
            varg.push_back(mokinys(temp));
    }
        in.close();

//sorting(varg);
//sorting(kiet);

}
template <typename Container>
void budas3(Container& varg, Container& kiet, std::string name)
{                        cout<<name<<'\n';

         for(int i=1; i<=n; i++)
               {s();
                checkfile(std::to_string(i)+"irasas.txt");
                budas3read(varg, kiet, std::to_string(i)+"irasas.txt");
                cout<<varg.size()+kiet.size()<<" - ";
                varg.clear();
                kiet.clear();
                e();
               }
}


#endif
