#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;//保存下一条交易记录的变量
    //读取第一条交易记录，并确保有数据处理
    if (std::cin >> total) {
        Sales_item trans;

        while (std::cin >> trans) {

            if (total.isbn == trans.isbn)
                total += trans;
            else {
                std::cout << total << std::endl;
                total = trans;
            }
            
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data??" << std::endl;
        return -1;
    }
    return 0;
}
