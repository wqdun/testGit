#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
    const size_t BUFFER_SIZE = 80;
    char *buf = new char[BUFFER_SIZE];
    // = NULL;
    cout << sizeof(buf) << "\n";
    (void)getcwd(buf, BUFFER_SIZE);
    printf("current working directory : %s\n", buf);
    delete[] buf;
    //free(buf);
}