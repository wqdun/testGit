#include <iostream>
#include <map>

namespace ClassFoo {

using namespace std;

void PrintIntIntMap(std::map<int,int>& m) {
    std::map<int,int>::iterator it;
    for ( it = m.begin(); it != m.end(); it++ )
        std::cout << "(" << it->first << "," << it->second << ") ";
    std::cout << std::endl;
}
void MapEndExample1() {
    std::map<int,int> foo1;

    foo1[3] = 96;
    foo1[24] = 14;
    foo1[35] = 37;
    // cout << foo1.size() << endl;
    cout << foo1.begin()->first << endl;
    // cout << foo1.end()->first << endl;
    cout << (int)(foo1.rbegin() == foo1.rend()) << endl;
    cout << foo1.rbegin()->first << endl;
    // cout << foo1.rend()->first << endl;
    auto beginIter = foo1.lower_bound(0);
    cout << (int)(beginIter == foo1.cend()) << endl;
    cout << (int)(foo1.upper_bound(35) == foo1.cend()) << endl;

    cout << foo1.upper_bound(.9)->second << endl;
    // PrintIntIntMap(foo1);
}


}
int main ()
{
    ClassFoo::MapEndExample1();
    return 0;
}