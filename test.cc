#include <iostream>
#include <dirent.h>
#include <unistd.h>

using namespace std;

// struct dirent
// {
//    long d_ino; /* inode number 索引节点号 */
//    off_t d_off; /* offset to this dirent 在目录文件中的偏移 */
//    unsigned short d_reclen;  length of this d_name 文件名长
//    unsigned char d_type; /* the type of d_name 文件类型 */
//    char d_name [NAME_MAX+1]; /* file name (null-terminated) 文件名，最长255字符 */
// }其中d_type表明该文件的类型：文件(8)、目录(4)、链接文件(10)等。


int readFileList(const string &basePath) {
    DIR *dir;
    dirent *ptr;

    // if dir == NULL
    if( !(dir = opendir(basePath.c_str())) ) {
        perror("Open dir error...");
        exit(1);
    }

    // while ptr != NULL
    while(ptr = readdir(dir)) {
        // ignore . and ..
        if( !(strcmp(ptr->d_name, ".")) ||
            !(strcmp(ptr->d_name, "..")) ) {
            continue;
        }

        // regular file
        if(8 == ptr->d_type) {
            cout << basePath << "/" << ptr->d_name << "\n";
        }
        // directory
        else
        if(4 == ptr->d_type) {
            string subDir(basePath + "/" + ptr->d_name);
            readFileList(subDir);
        }
        // else {
        //     // ignore links(10) & others
        // }
    }

    closedir(dir);
    return 0;
}

int main(void)
{
    // get the current absolute path
    const size_t BUFFER_SIZE = 80;
    char *buf = new char[BUFFER_SIZE];
    (void)getcwd(buf, BUFFER_SIZE);
    string basePath(buf);
    delete[] buf;
    cout << "current working directory:" << basePath << "\n";

    ///get the file list
    (void)readFileList(basePath);
    return 0;
}
