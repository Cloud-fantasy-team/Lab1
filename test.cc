#include <iostream>
#include "thread_pool.h"

int main()
{
    thread_pool pool(1);

    auto p = pool.add_task([](int a, int b){ return a + b; }, 1, 2);
    auto p2 = pool.add_task([](int a, int b){ return a * b; }, 1, 2);
    std::cout << p.get() << std::endl;
    std::cout << p2.get() << std::endl;
}