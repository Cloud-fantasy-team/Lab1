#include <string>
#include <vector>
#include <iostream>

bool solve_sudoku_basic(std::vector<int> &board, int r, int c);

static std::vector<int> read_input(const std::string &str)
{
    std::vector<int> ret;
    ret.reserve(81);

    for (auto ch : str)
    {
        ret.push_back(ch - '0');
    }
    return ret;
}

int main()
{
    auto board = read_input("000000010400000000020000000000050407008000300001090000300400200050100000000806000");
    solve_sudoku_basic(board, 0, 0);
}