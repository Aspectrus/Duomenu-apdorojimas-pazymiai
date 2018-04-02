#include "struktura.h"
#include <windows.h>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;



template <typename container>
container b()
{
  cout<<"b";
}
template<typename T>
void a(void (*f)())
{

    f<int>();

    cout<<"a";

}
template<typename C>
C ccc(C a)
{

    cout<<"c";

}


main()
{
    a<int>(ccc);

    return 0;
}

