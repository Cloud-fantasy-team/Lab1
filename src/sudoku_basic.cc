#include <cassert>
#include <vector>
#include "common.h"

#define INDEX(r, c) ((r) * kCol + (c))

/// Ensure board[r][c] can be filled with [v].
static bool ok(std::vector<int> &board, int r, int l, int v)
{
    int begin_row = r / kGrid * kGrid;
    int begin_col = l / kGrid * kGrid;

    // Ensure no dup in current row.
    for (int i = 0; i < l; i++)
    {
        if (board[INDEX(r, i)] == v)
            return false;
    }

    // Ensure no dup in current column.
    for (int i = 0; i < r; i++)
    {
        if (board[INDEX(i, l)] == v)
            return false;
    }

    // Ensure no dup in current grid.
    for (int i = begin_row; i <= r; i++)
    {
        for (int j = begin_col; j <= l; j++)
        {
            if (board[INDEX(i, j)] == v)    return false;
        }
    }

    return true;
}

/// Solve sudoku given from [board] in a DFS way.
bool solve_sudoku_basic(std::vector<int> &board, int r, int c)
{
    assert(board.size() == kCol * kRow);

    // Go to the next line if needed.
    if (c > kCol)
    {
        r = r + 1;
        c = 0;
    }

    // Check if we're done.
    if (INDEX(r, c) >= board.size())
        return true;

    // Try to find a value that fits in this cell.
    for (int v = 1; v <= kMax; v++)
    {
        if (ok(board, r, c, v))
        {
            board[INDEX(r, c)] = v;

            if (solve_sudoku_basic(board, r, c + 1))
                return true;

            // NOTE: reset is needed.
            board[INDEX(r, c)] = 0;
        }
    }
}