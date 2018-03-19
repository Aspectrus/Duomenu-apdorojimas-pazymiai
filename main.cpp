#include "struktura.h"
#include <windows.h>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

const int n=5; //failu skaicius



main()
{

    std::vector<mokinys> vvarg;
    std::list<mokinys> lvarg;
    std::deque<mokinys> dvarg;
    std::vector<mokinys> vkiet;
    std::list<mokinys> lkiet;
    std::deque<mokinys> dkiet;


    std::string pasirinkimas;
    cout<<"1-nuskaityti faila(-us)\n2-irasyti pazymius\n3-spausdinti irasytus\n4-sugeneruoti failus\n5-iseiti\n";

    while(std::getline(cin, pasirinkimas)&&pasirinkimas!="5")
{








        if (pasirinkimas=="1")
        {
            cout<<"Pasirinkite a,b ar c buda\n";
            while(std::getline(cin, pasirinkimas))
            {

            if(pasirinkimas=="c")
            {



                 cout<<"Vektrorius\n";
                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();

                checkfile(std::to_string(i)+"irasas.txt");
                read(vvarg, vkiet, std::to_string(i)+"irasas.txt");
                cout<<vvarg.size()+vkiet.size()<<" - ";
                vvarg.clear();
                vkiet.clear();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
             }
                    cout<<"Listas\n";
                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                read(lvarg, lkiet, std::to_string(i)+"irasas.txt");
                cout<<lvarg.size()+lkiet.size()<<" - ";
                lvarg.clear();
                lkiet.clear();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
             }
                    cout<<"Dekas\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                read(dvarg, dkiet, std::to_string(i)+"irasas.txt");
                cout<<dvarg.size()+dkiet.size()<<" - ";
                dvarg.clear();
                dkiet.clear();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
             }


cout<<"SUCCESS\n";    break;
            }

           else if(pasirinkimas=="b")
            {

                 cout<<"Vektrorius\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas2<std::vector<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }
                    cout<<"Listas\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas2<std::list<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }
                    cout<<"Dekas\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas2<std::deque<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }

            cout<<"SUCCESS\n";    break;
            }
             else if(pasirinkimas=="a")
            {

                    cout<<"Vektrorius\n";
                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas1<std::vector<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }
                    cout<<"Listas\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas1<std::list<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }
                    cout<<"Dekas\n";

                for(int i=1; i<=n; i++)
               {
                auto start = std::chrono::high_resolution_clock::now();
                checkfile(std::to_string(i)+"irasas.txt");
                readblogas1<std::deque<mokinys>>(std::to_string(i)+"irasas.txt");
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
               }


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
         irasyti(vvarg);
cout<<"SUCCESS\n";
        }
       else  if(pasirinkimas=="3")
        {
            sorting(vvarg);

    spausdinti(vvarg);


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



 cout<<"1-nuskaityti faila(-us)\n2-irasyti pazymius\n3-spausdinti irasytus\n4-sugeneruoti failus\n5-iseiti\n";


}
    return 0;
}

