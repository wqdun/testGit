#include <iostream>
#include <sstream>
#include <cmath>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

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

void func(void *p) {
    ++(*((size_t *)p));
    // ++(size_t)(*p);

}


int main() {
    vector<int> mTileList = {20596447, 20596446};
    string sql("");
    for(auto tile: mTileList) {
        sql += " or MESH = " + std::to_string(tile);
    }

    sql = "SELECT GEOM FROM ROAD WHERE " + sql.substr(4);
    cout << sql << "\n";

    string str2parse = "LINESTRING (116.35233 39.9779)";
    std::istringstream input("(116.35233 39.9779");
    string line;
    double lat;
    input >> lat;
    input >> lat;
    // input >> lat;
    // input >> lat;
    // input >> lat;
    cout << "lat:" << lat << endl;
    // getline(input, line, ',');
    // line = "(116.35233";
    // cout << stod(line) << endl;
    // // stoi(line);
    // cout << line << endl;
    // str2parse = "LINESTRING";
    vector<string> parsed_data;
    boost::split(parsed_data, str2parse, boost::is_any_of( ",)(" ), boost::token_compress_on);
    cout << parsed_data.size() << endl;
    // for(int i = 1; i < parsed_data.size() - 1; ++i) {
    //     cout << parsed_data[i] << endl;
    //     std::istringstream iss(parsed_data[i]);
    //     double lat;
    //     double lon;
    //     iss >> lat >> lon;
    //     cout << lon << " : " << lat << endl;
    //     cout << fixed << lon << " : " << lat << endl;
    // }

    // size_t i = 0;
    // for(int ii = 0; ii < 10; ++ii)
    //     func(&i);
    // cout << i << endl;


    return 0;
}


