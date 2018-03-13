#ifndef STRUKTURA_HPP
#define STRUKTURA_HPP

template<typename Container>
void read(Container& varg, Container& kiet, std::string name)
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
sorting(varg);
sorting(kiet);

}


template <typename T> void spausdinti( T duom)
{

cout<<std::left<<std::setw(15)<<"Pavarde"<<std::left<<std::setw(15) <<"Vardas"<<std::left<<std::setw(20) <<"Galutinis-Vidurkis"<<std::left<<std::setw(15) <<"Galutine-Mediana\n";
   for(std::size_t i=0; i<duom.size(); i++)
    {

        cout<<std::setw(15)<<duom[i].pavarde<<std::left<<std::setw(15)<<duom[i].vardas<<std::left<<std::setw(20);
        cout<<std::setprecision(3)<<duom[i].galvid<<std::left<<std::setw(15);
        cout<<std::setprecision(3)<<duom[i].galmed<<"\n";


    }

}
#endif
