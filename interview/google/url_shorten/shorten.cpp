// inspired by 
// http://www.glassdoor.com/Interview/Google-Interview-RVW3059942.htm
// http://stackoverflow.com/questions/742013/how-to-code-a-url-shortener
// 
// sqlite tutorial:
// http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm

// we assume the database and table is ready
// we do not sanitize the url

#include <cstdio>
#include <string>
#include <algorithm>
#include <sqlite3.h>
using std::string;

const char *usage = "usage: ./shorten url";
const char *db_name = "urls.db";
const char *table_name = "mapping";
const string alphabet = 
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";
const char *basename = "http://short.en";

string encode(unsigned int id) {
  if (id == 0) return alphabet.substr(0, 1);

  const unsigned int base = alphabet.size();
  string shorten;
  while(id > 0) {
    int c = id % base;
    id /= base;
    shorten += alphabet[c];
  }

  std::reverse(shorten.begin(), shorten.end());
  return shorten;
}


static int insert_url(void *key, int argc, char **argv, char **azColName) {
  *(unsigned int *) key = std::stoi(argv[0]) + 1;
  return 0;
}

static int find_url(void *found, int argc, char **argv, char **azColName) {
  * (bool*) found = true;
  printf("%s/%s\n", basename, argv[0]);
  // for(int i=0; i<argc; i++){
  //     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  // }
  return 0;
}

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s\n", usage);
    return 1;
  }
  sqlite3 *db;

  // open data base
  char *zErrMsg = NULL;
  int rc;
  rc = sqlite3_open(db_name, &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return 1;
  }

  // find the url string in db
  // Create SQL statement 
  string url = argv[1];
  string query = "SELECT short_string FROM map WHERE url_string = '" +
                 url + "';";

  // Execute SQL statement 
  bool found = false;
  rc = sqlite3_exec(db, query.c_str(), find_url, (void *) &found, &zErrMsg);
  if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    return 2;
  }

  // insert a new entry in not found
  if (!found) {
    string get_key = "SELECT seq FROM sqlite_sequence where name = 'map';";
    unsigned int key = 0;
    rc = sqlite3_exec(db, get_key.c_str(), insert_url, &key, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return 3;
    }    

    string shorten = encode(key);
    printf("%s/%s\n", basename, shorten.c_str());
    string insert = "INSERT INTO map VALUES (NULL, ";
    insert += "'" + url + "',";
    insert += "'" + shorten + "')";
    rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return 3;
    } 
  }

  sqlite3_close(db);
  return 0;
}