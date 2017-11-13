#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cerrno>
#include <iostream>
using namespace std;

string mRecordPath = "/home/dun/";

int saveFile(const char *pTimeStamp) {
    // about 600 packets/second
    static const size_t MAX_PKT_CNT = 100;
    static size_t pktCnt = 0;
    static char fileName[50];
    static FILE *pOutFile;
    // get unix time stamp as file name
    if(0 == pktCnt) {
        time_t tt = time(NULL);
        tm *t= localtime(&tt);
        (void)sprintf(fileName, "%02d_%02d_%02d.lidar", t->tm_hour, t->tm_min, t->tm_sec);

        const string fileNameStr("fileName");
        const string recordFile(mRecordPath + fileNameStr);

        if( !(pOutFile = fopen(recordFile.c_str(), "wb")) ) {
            cout << "Create file:" << fileName << " failed, errno:" << errno;
        }
        cout << "Create file:" << fileName << " successfully.\n";
    }

    static const size_t timeSize = sizeof(*pTimeStamp);
    if(1 != fwrite(pTimeStamp, timeSize, 1, pOutFile)) {
      cout << "Write time stamp error.";
    }

    ++pktCnt;
    cout << "pktCnt:" << pktCnt << "\n";
    if(11 == pktCnt) {
      pktCnt = 0;
      fclose(pOutFile);
    }
    // fclose(pOutFile);
    return 0;
}

int saveTxtFile() {

    string strT("/home/dun/fileName");
    ifstream in;
    cout << "in.good():" << in.good() << endl;
    static int times = 0;
    ++times;
    cout << times << "\n";
    // if(1 == times)
        in.open(strT.c_str());
    if(!in) {cout << "Error\n";}

    const size_t BUFFER_SIZE = 100;
    char *pLine = new char[BUFFER_SIZE];
    in.getline(pLine, BUFFER_SIZE);

    cout << pLine << endl;
    delete[] pLine;
    // string str;
    // in >> str;
    // cout << str << endl;;
    // in >> str;
    // cout << str << endl;
    in.close();
    cout << "in.good():" << in.good() << endl;

    return 0;
}

int openBinFile() {

    FILE *pOutFile = fopen("test_bin_file", "ab");
    cout << "pOutFile:" << pOutFile << endl;
    char c = 'a';
    char *pChar = &c;
    fwrite(pChar, 1, 1, pOutFile);
    // fclose(pOutFile);

    // FILE *pOutFile2 = fopen("test_bin_file", "wb");
    // cout << "pOutFile2:" << pOutFile2 << endl;
    // fwrite(pChar, 1, 1, pOutFile);
    // fclose(pOutFile2);
}

int openTxtFile() {
    string strT("/home/dun/projects/testGit/test_bin_file");
    ifstream in;
    cout << "in.good():" << in.good() << endl;

    in.open(strT.c_str());
    cout << "in:" << in << "\n";
    if(!in) {cout << "Error\n";}

    const size_t BUFFER_SIZE = 100;
    char *pLine = new char[BUFFER_SIZE];
    in.getline(pLine, BUFFER_SIZE);
    cout << pLine << endl;
    delete[] pLine;

    // in.close();
    cout << "in.good():" << in.good() << endl;

    ifstream in2;

    in2.open(strT.c_str());
    cout << "in2:" << in2 << "\n";
    if(!in2) {cout << "Error\n";}

    char *pLine2 = new char[BUFFER_SIZE];
    in2.getline(pLine2, BUFFER_SIZE);
    cout << "pLine2:" << pLine2 << endl;
    delete[] pLine2;

    return 0;
}



int main() {
    // char c = 'p';
    // const char *pC = &c;
    // for(int i = 0; i < 10; ++i) {
    //     saveFile(pC);
    // }
    // c = 'd';
    // saveFile(pC);
    // openTxtFile();
    // openTxtFile();

    openBinFile();
    openBinFile();

    // saveTxtFile();

    // saveTxtFile();
}

