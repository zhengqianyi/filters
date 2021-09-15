#include <iostream>
#include <string>
#include <vector>

#include "../ft/bloom_filter.hpp"
#include "../ft/cuckoo_filter.hpp"
#include "../ft/Rand_int.hpp"

using namespace ft;
using std::cout;
using std::endl;
using std::string;

int main()
{
    //随机生成1000个字符串
    Rand_int rnd{0, 2147483647};

    std::vector<string> ss;

    for (int i = 1000; i > 0; i--)
    {
        int k = rnd() % 100 + 1; //随机生成一个字符串的长度
        string s = "";
        for (int i = 0; i < k; i++)
        {
            int r;
            char x;
            r = rnd() % 2;
            if (r == 1)
                x = rnd() % ('Z' - 'A' + 1) + 'A';
            else
                x = rnd() % ('z' - 'a' + 1) + 'a';
            s.push_back(x);
        }
        ss.push_back(s);
    }

    cout << ss.size() << endl;


    
}