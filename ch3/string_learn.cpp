#include <string>
#include <iostream>
using std::string;

int main() {
    string s1 = "吴家仔";
    string s2 = "吴";
    string s3 = "wujiazai";
    std::cout << "s1.size(): " << s1.size() << std::endl;
    std::cout << "s2.size(): " << s2.size() << std::endl;
    std::cout << "s3.size(): " << s3.size() << std::endl;
    return 0;
}
