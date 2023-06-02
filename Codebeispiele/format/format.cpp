//https://www.boost.org/doc/libs/1_75_0/libs/format/doc/format.html
#include <iostream>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

int main() {
    cout << format("%-20s %s") % "Hello" % "World"  << endl;
    return 0;
}

