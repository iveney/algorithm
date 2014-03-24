#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range.hpp>

template <typename... T>
auto zip(const T&... containers) -> boost::iterator_range<boost::zip_iterator<decltype(boost::make_tuple(std::begin(containers)...))>>
{
    auto zip_begin = boost::make_zip_iterator(boost::make_tuple(std::begin(containers)...));
    auto zip_end = boost::make_zip_iterator(boost::make_tuple(std::end(containers)...));
    return boost::make_iterator_range(zip_begin, zip_end);
}

int main(int argc, char const *argv[])
{
  std::vector<int> a {4, 5, 6};
  double b[] = {7, 8, 9};
  std::list<std::string> c {"a", "b", "c"};
  for (auto tup : zip(a, b, c, a))
  {
    int x, w;
    double y;
    std::string z;
    boost::tie(x, y, z, w) = tup;
    printf("%d %g %s %d\n", x, y, z.c_str(), w);
  }
  return 0;
}