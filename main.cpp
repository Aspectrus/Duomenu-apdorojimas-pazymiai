#include "struktura.h"




main()
{
    std::vector<mokinys> vvarg;
    std::list<mokinys> lvarg;
    std::deque<mokinys> dvarg;
    std::vector<mokinys> vkiet;
    std::list<mokinys> lkiet;
    std::deque<mokinys> dkiet;





    std::string pasirinkimas;
    cout<<"1-atsitiktiniai pazymiai\n2-irasyti pazymius\n3-nuskaityti faila\n";
    while(std::getline(cin, pasirinkimas))
{


        if (pasirinkimas=="1")
        {
          int n=6;
       filegen(n);
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
                     for(auto i:dvarg)
    cout<<i.vardas<<endl;
                dvarg.clear();
                dkiet.clear();
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = (std::chrono::duration<double>( end - start ).count());
                std::cout << elapsed<< "s \n";
             }

     break;
}
        else  if(pasirinkimas=="2")
        {
         irasyti(vvarg);
            break;
        }

       else if(pasirinkimas=="3")
        {
            checkfile("kursiokai.txt");
            read2(vvarg,"kursiokai.txt");
            sorting(vvarg);
            spausdinti(vvarg);

            break;
        }

    else

    {
		cout << "Invalid input. Try again. " << endl;

    }
}
    return 0;
}

