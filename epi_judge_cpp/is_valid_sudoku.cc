#include <vector>
#include <cmath>

#include "test_framework/generic_test.h"

using std::vector;

bool HasDuplicate(const vector<vector<int> >&, int, int, int, int);

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int> > &partial_assignment)
{
  // Columns
  for (int i = 0; i < size(partial_assignment); i++)
  {
    if (HasDuplicate(partial_assignment, 0, size(partial_assignment), i, i+1))
      return false;
  }

  // Rows
  for (int i = 0; i < size(partial_assignment); i++)
  {
    if (HasDuplicate(partial_assignment, i, i+1, 0, size(partial_assignment)))
      return false;
  }

  // Sub grids
  int sub_grid_side = sqrt(size(partial_assignment));
  for (int I = 0; I < sub_grid_side; I++)
  {
    for (int J = 0; J < sub_grid_side; J++)
    {
      if (HasDuplicate(partial_assignment,
                      I * sub_grid_side,
                      (I + 1) * sub_grid_side,
                      J * sub_grid_side,
                      (J + 1) * sub_grid_side))
        return false;
    }
  }

  return true;
}

bool HasDuplicate(const vector<vector<int> > &A, int row_start, int row_end, int col_start, int col_end) {
  vector<bool> is_present;
  is_present.assign(size(A) + 1, 0);

  for (int i = row_start; i < row_end; i++) {
    for ( int j = col_start; j < col_end; j++) {
      int el = A[i][j];
      if(el !=0 && is_present[el]) return true;
      is_present[el] = 1;
    }
  }

  return false;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
