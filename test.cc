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
#include <sqlite3.h>
using namespace std;


static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   printf("Hello\n");
   return 0;
}
// {
//     static int column_names_printed = 0;
// int i;
// if (!column_names_printed) {
// print_row(n_columns, column_names);
// column_names_printed = 1;
// }
// print_row(n_columns, column_values);
// return 0;
// }

// void print_row(int n_values, char** values)
// {
// int i;
// for (i = 0; i < n_values; ++i) {
// if (i > 0) {
// printf("\t");
// }
// printf("%s", values[i]);
// }
// printf("\n");
// }


int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    if( sqlite3_open("test.db", &db) ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
   }

    fprintf(stderr, "Opened database successfully\n");


    /* Create SQL statement */
    string sql;
    sql = "CREATE TABLE COMPANY("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "AGE            INT     NOT NULL," \
        "ADDRESS        CHAR(50)," \
        "SALARY         REAL );";

    const char *sql_cstr = sql.c_str();

    /* Execute SQL statement */
    // rc = sqlite3_exec(db, sql_cstr, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Table created successfully\n");
    }

    const int id_beg = 10;
    int id = id_beg;
    while(id < id_beg + 5) {
        sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (" + std::to_string(++id) + ", 'Paul', 32, 'California', 20000.00 ); ";
         rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Records created successfully\n");
        }
    }

    const char* data = "Callback function called";
    sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1;";\
           //SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }

    sqlite3_close(db);
}
