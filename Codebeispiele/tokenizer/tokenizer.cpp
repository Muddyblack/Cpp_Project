// https://www.boost.org/doc/libs/1_79_0/libs/tokenizer/doc/char_separator.htm
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>

using namespace std;
using namespace boost;

const string s = {"1,3,5,7,8,9"};

int main()
{
    char_separator<char> sep(",");
    tokenizer<boost::char_separator<char>> tok(s, sep);
    for (auto it = tok.begin(); it != tok.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
