#include <iostream>
#include <sstream>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

int getDimensionCode(double x, double width, int nBlockNum) {
    return (x < 0)? (nBlockNum - 1) + (int) (x / width): (int)(x / width);
}

string toBinaryString(int inNum) {
    const int BIT = (sizeof(inNum) << 3);
    bitset<BIT> bst(inNum);

    ostringstream oss;
    oss << bst;
    string binaryStringWith0Ahead(oss.str());
    return binaryStringWith0Ahead.substr(binaryStringWith0Ahead.find("1"));
}

int main() {
    int a = 3;
    cout << pow(2, 3) << endl;

    const int bit = sizeof(a) << 3;
    cout << "bit: " << bit << endl;
    bitset<bit> bst(15);
    std::ostringstream oss;
    oss << bst;
    string str2(oss.str());
    cout << str2 << endl;
    cout << str2.length() << endl;



    for(int i = bit - 1; i >= 0; --i) {
        cout << bst[i] << endl;
        if(1 == bst[i]) {
            cout << i + 1 << "\n";
            break;
        }
    }


    // cout << binary << bit << endl;
    int bb = 12456;
    for(int i = 0; i < 32; ++i) {
        if(!(bb >> i)) {
            cout << i << endl;

            break;
        }
    }

    cout << getDimensionCode(11, 2, 3) << endl;

    string str="00000112003";
    cout << str.substr(2)<<endl;
    cout << str.substr(str.find("1"))<<endl;
    string binaryStr("");
    cout << (binaryStr = toBinaryString(17)) << endl;
    // binaryStr = "0" + binaryStr;
    binaryStr += "0";
    cout << binaryStr << endl;


    string str_dec = "2048,hello world";
    string str_hex = "403";
    string str_bin = "-10010110001";
    string str_auto = "0x7f";

    size_t sz;   // alias of size_t
    int i_dec = std::stoi(str_dec, &sz);
    int i_hex = std::stoi(str_hex, nullptr, 16);
    int i_bin = std::stoi(str_bin, nullptr, 2);
    int i_auto = std::stoi(str_auto, nullptr, 0);

    std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
    std::cout << str_hex << ": " << i_hex << '\n';
    std::cout << str_bin << ": " << i_bin << '\n';
    std::cout << str_auto << ": " << i_auto << '\n';

    string s = "010101111122";
    reverse(s.begin(), s.end());
    cout << s << endl;

    string binaryStr2("01100100011011100100011011"), binaryXStr(""), binaryYStr("");
    cout << binaryStr2.substr(2, 0 + 5) << endl;
    for (int i = 0; i < binaryStr2.length(); i = i + 2) {
        binaryYStr.append(binaryStr2.substr(i, 1));
        cout << i << " : " << binaryYStr << endl;

        if (binaryStr2.length() > i + 1) {
            binaryXStr.append(binaryStr2.substr(i + 1, 1));
        }
    }

    cout << binaryXStr << endl;
    cout << binaryYStr << endl;

    return 0;
}


