//https://theboostcpplibraries.com/boost.lexical_cast
#include<iostream>
#include <boost/lexical_cast.hpp>
#include<string>

using namespace std;
using namespace boost;

const string s = {"123"};

int main() {
    try
    {
        const int i = boost::lexical_cast<int>(s);
        cout << i << endl;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

