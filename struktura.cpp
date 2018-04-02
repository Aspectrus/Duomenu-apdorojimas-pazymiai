#include "struktura.h"
#include <sstream>
#include <chrono>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;

float mediana (std::vector<int> pazymiai)
{
    std::sort (pazymiai.begin(), pazymiai.end());

    if(pazymiai.size()%2==0)
        return (pazymiai[pazymiai.size()/2]+pazymiai[pazymiai.size()/2-1])/float(2);
    else
        return pazymiai[pazymiai.size()/2];
}
float vidurkis(std::vector<int> pazymiai){
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


void read2(std::vector<mokinys> & temp, std::string name)
{

    std::ifstream in (name);
    std::string eil;
    int a=0;
    while(std::getline(in, eil))
    {
        temp.push_back(mokinys());


        std::istringstream ss(eil);
        ss>>temp[a].vardas;
        ss>>temp[a].pavarde;
        int num;
        std::vector<int> vtemp;
        while(ss>>num)
        vtemp.push_back(num);



    int egzaminas=vtemp[vtemp.size()-1];
    vtemp.pop_back();
    temp[a].galmed=0.6*egzaminas+mediana(vtemp)*0.4;
    temp[a].galvid=0.6*egzaminas+vidurkis(vtemp)*0.4;
    a++;
    }

}

void filegen(int a)
{

    int n=1;
    for (int i=1; i<=a; i++)
    {
        cout<<i<<" file gen - ";
       auto  start = std::chrono::high_resolution_clock::now();
        n*=10;
        std::ofstream out(std::to_string(i)+"irasas.txt");
        for(int j=1; j<=n; j++)
        {
            out<<"Vardas"+std::to_string(j)+" ";
            out<<"Pavarde"+std::to_string(j);
            int c=randomnumber(2,15);

            for(int k=0; k<c; k++)
            {
                out<<" "<<randomnumber(1, 10);;
            }
            out<<"\n";
        }
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
    }
}

void irasyti(std::vector<mokinys> duom)
{
    duom.push_back(mokinys());
    cout<<"Vardas:\n";
    std::getline(std::cin, duom[0].vardas);
    cout<<"Pavarde:\n";
        std::getline(std::cin, duom[0].pavarde);
    cout<<"Pazymiai:(baigti rasykite -1)\n";
    int a;
    std::vector<int> vtemp;
    std::string line;
    bool atleastone=false;
    while(1)
    {
        while(1)
        {
            std::getline(std::cin, line);
            cin.clear();

            if(isnumber(line))
            {
                std::stringstream ss(line);
                if(ss>>a&&(a >= 1 && a <= 10))
                {
                    atleastone=true;
                    break;
                }

            }
            else if(atleastone&&line=="-1")
            {
                break;
            }
            /*

            std::stringstream ss(line);
               if (atleastone)
            {
                if(ss >> a && ss.eof() && (a >= 1 && a <= 10)||line=="-1")
                break;
            }

            if(ss >> a && ss.eof() && (a >= 1 && a <= 10))
            {

                atleastone=true;
                break;
            }
            */
     cout<<"WRONG\n";
        }
        if(line=="-1")
            break;
        else
            vtemp.push_back(a);
    }
    cout<<"Iveskite egzamino rezultata"<<endl;
    while(1)
    {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream s(line);
        if(s >> a && s.eof() && (a >= 1 && a <= 10))
        {
            break;
        }
        cout<<"WRONG\n";
    }
    int egzaminas=a;
    duom[0].galmed=0.6*egzaminas+mediana(vtemp)*0.4;
    duom[0].galvid=0.6*egzaminas+vidurkis(vtemp)*0.4;
    spausdinti(duom);

}
bool isnumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void sorting(std::deque<mokinys> & duom)
{  std::sort(duom.begin(), duom.end(), [](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });

}
void sorting(std::list<mokinys> & listduom)
{
    listduom.sort([](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });

}
void sorting(std::vector<mokinys> & deqduom)
{
     std::sort(deqduom.begin(), deqduom.end(), [](const mokinys& a, const mokinys& rhs)
            {
                return a.pavarde < rhs.pavarde;
            });

}

