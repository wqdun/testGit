#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <iterator>
using namespace std;

#define SIZE 0

typedef struct student_type {
    char name[20];
    int num;
    int age;
    char addr[15];
} stud_t;

stud_t stud[SIZE];

void save(const stud_t &in_stu) {
    FILE * fp;
    int i;
    if((fp = fopen("stu_list.txt", "wb")) == NULL) {
        printf("cannot open file\n");
        exit(1);
    }
    for (i = 0; i < SIZE; i++) {
        if(fwrite(&in_stu, sizeof(struct student_type), 1, fp) != 1)
            printf("file write error.\n");
    }
    fclose(fp);
}

template <typename T>
int saveFile(const T &data2write) {
    static const size_t MAX_PKT_CNT = 10000000;
    cout << sizeof(T) << endl;
}


int main() {
    printf("sizeof(struct stud) = %ld\n", sizeof(stud_t));
    printf("Please input the 4 student information,including name,num,age,address\n");
    int i;
    for(i = 0; i < SIZE; i++)
        scanf("%s%d%d%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);


    save(stud[1]);
    printf("\nThe information of the 4 students is:\n");

    FILE* fp;
    fp = fopen("stu_list.txt", "rb");
    fseek(fp, 0, 2);
    long int pos = ftell(fp);
    cout << pos << endl;
    // while() {

    // }

    for (i = 0; i < SIZE + 1; i++) {
        fread(&stud[i], sizeof(struct student_type), 1, fp);
        printf("%-10s %4d %4d %-15s\n", stud[i].name, stud[i].num, stud[i].age, stud[i].addr);
    }
    fclose(fp);

    // cout << sizeof(double) << sizeof(float) << endl;

    // int a[3] = {5, 7};
    // // vector<int> a;
    // // a.clear();
    // a.push_back(5);
    // cout << a.size() << endl;

    double f64 = -22345.15412453;
    float f32 = static_cast<float>(f64);
    cout << fixed << setprecision(6) << f64 << "\n" << setprecision(6)<< f32 << endl;
    cout << fabs(f64) << endl;


    float *pF64 = &f32;
    saveFile(f64);
    saveFile(pF64);
    cout << sizeof(double) << endl;
    cout << sizeof(*pF64) << endl;

{
  std::string s;
  // assign(size_type count, CharT ch)
  s.assign(4, '=');
  std::cout << s << '\n'; // "===="

  std::string const c("Exemplary");
  // assign(basic_string const& str)
  s.assign(c);
  std::cout << c << "==" << s <<'\n'; // "Exemplary == Exemplary"

  // assign(basic_string const& str, size_type pos, size_type count)
  s.assign(c, 0, c.length()-1);
  std::cout << s << '\n'; // "Exemplar";

  // assign(basic_string&& str)
  s.assign(std::string("C++ by ") + "example");
  std::cout << s << '\n'; // "C++ by example"

  // assign(charT const* s, size_type count)
  s.assign("C-style string", 7);
  std::cout << s << '\n'; // "C-style"

  // assign(charT const* s)
  s.assign("C-style\0string");
  std::cout << s << '\n'; // "C-style"

  char mutable_c_str[] = "C-style string";
  // assign(InputIt first, InputIt last)
  s.assign(std::begin(mutable_c_str), std::end(mutable_c_str)-1);
  std::cout << s << '\n'; // "C-style string"

  // assign(std::initializer_list<charT> ilist)
  s.assign({ 'C', '-', 's', 't', 'y', 'l', 'e' });
  std::cout << s << '\n'; // "C-style"

  string p;
  string path("Helo");
  p.assign(path).append("\\*").append("endl");
  cout << p << "\n";

}
    return 0;
}