#include <iostream>
#include <fstream>
using namespace std;

#include <boost/archive/text_iarchive.hpp>

#include "BKtree.h"
#include "levenshtein_distance.h"

int main(int argc, char const *argv[])
{
  if (argc <= 1) {
    cerr << "Usage: " << argv[0] << " <serialized_dict> <query> <tolerance>\n";
    return 1;
  }
  ifstream ifs(argv[1]);
  if (!ifs) {
    cerr << "File '" << argv[1] << "' not exist!\n";
    return 2;
  }

  BKTree tree;
  {
    // create and open an archive for input
    boost::archive::text_iarchive ia(ifs);
    // read class state from archive
    ia >> tree;
    // archive and stream closed when destructors are called
  }

  auto result = tree.search(argv[2], atoi(argv[3]));
  copy(result.begin(), result.end(), 
    ostream_iterator<decltype(result)::value_type>(cout, " "));
  cout << "\n";

  return 0;
}