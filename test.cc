#include <iostream>
#include <map>

using namespace std;

void PrintIntIntMap(std::map<int,int>& m) {
    std::map<int,int>::iterator it;
    for ( it = m.begin(); it != m.end(); it++ )
        std::cout << "(" << it->first << "," << it->second << ") ";
    std::cout << std::endl;
}
void MapEndExample1() {
    std::multimap<int,int> foo1;

    // foo1[3] = 96;
    // foo1[3] = 100;
    // foo1[24] = 14;
    // foo1[35] = 37;
    foo1.insert(std::make_pair(22, 6));
    foo1.insert(std::make_pair(3, 1000));
    foo1.insert(std::make_pair(3, 96));
    foo1.insert(std::make_pair(3, 333));
    foo1.insert(std::make_pair(4, 96));
    cout << foo1.size() << endl;
    // cout << foo1[3] << endl;
    for(const auto &ele: foo1) {
      cout << ele.first << ele.second << endl;
    }
  }

    // cout << foo1.begin()->first << endl;
    // // cout << foo1.end()->first << endl;
    // cout << (int)(foo1.rbegin() == foo1.rend()) << endl;
    // cout << foo1.rbegin()->first << endl;
    // // cout << foo1.rend()->first << endl;
    // auto beginIter = foo1.lower_bound(0);
    // cout << (int)(beginIter == foo1.cend()) << endl;
    // cout << (int)(foo1.upper_bound(35) == foo1.cend()) << endl;

    // cout << foo1.upper_bound(.9)->second << endl;

    // auto tmp = foo1.end();
    // --tmp;
    // // foo1.erase(foo1.begin(), tmp);
    // foo1.erase(foo1.begin(), foo1.begin());
    // cout << foo1.size() << endl;
    // cout << foo1.begin()->first << endl;

    // PrintIntIntMap(foo1);
// }

int main ()
{
    MapEndExample1();
    return 0;
}