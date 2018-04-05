#include "struktura.h"
#include <chrono>

using std::cout;
using std::cin;
using std::endl;




main()
{
    std::vector<mokinys> vvarg;
    std::list<mokinys> lvarg;
    std::deque<mokinys> dvarg;
    std::vector<mokinys> vkiet;
    std::list<mokinys> lkiet;
    std::deque<mokinys> dkiet;
    std::string pasirinkimas;
    cout<<"1-nuskaityti faila(-us)\n2-irasyti pazymius\n3-spausdinti irasytus i konsole\n4-sugeneruoti failus\n5-iseiti\n";
 std::vector<mokinys> bs;
    while(std::getline(cin, pasirinkimas)&&pasirinkimas!="6")
{
        if (pasirinkimas=="1")
        {
            cout<<"Pasirinkite 1, 2 ar 3 buda\n";
            while(std::getline(cin, pasirinkimas))
            {
            if(pasirinkimas=="3")
            {
                budas3(vvarg, vkiet, "Vektroius");
                budas3(lvarg, lkiet, "Listas");
                budas3(dvarg, dkiet, "Dekas");

cout<<"SUCCESS\n";    break;
            }

           else if(pasirinkimas=="1")
            {
                budas1<std::vector<mokinys>>("Vektorius");
                budas1<std::list<mokinys>>("Listas");
                budas1<std::deque<mokinys>>("Dekas");
            cout<<"SUCCESS\n";    break;
            }
             else if(pasirinkimas=="2")
            {
                budas2<std::vector<mokinys>>("Vektorius");
                budas2<std::list<mokinys>>("Listas");
                budas2<std::deque<mokinys>>("Dekas");

            cout<<"SUCCESS\n";
            break;
            }
    else
    {
		cout << "Invalid input. Try again. " << endl;
    }
              }
        }
        else  if(pasirinkimas=="2")
        {


         irasyti(bs);
cout<<"SUCCESS\n";
        }
       else  if(pasirinkimas=="3")
        {
            sorting(bs);
    spausdinti(bs);
    cout<<"SUCCESS\n";
        }
        else if(pasirinkimas=="4")
        {
            filegen(n);
cout<<"SUCCESS\n";
        }
    else
    {
		cout << "Invalid input. Try again. " << endl;
    }
  cout<<"1-nuskaityti faila(-us)\n2-irasyti pazymius\n3-spausdinti irasytus i konsole\n4-sugeneruoti failus\n5-iseiti\n";
  }


    return 0;
}

