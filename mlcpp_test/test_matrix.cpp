/*****************************************************************************
 * Copyright (C) 2017 Lee Tomlinson
 *
 * This file is part of MLCPP.
 *
 * MLCPP is licensed under the terms of Attribution-NonCommercial 4.0
 * International (CC BY-NC 4.0).  For more information see
 * https://creativecommons.org/licenses/by-nc/4.0/
 *****************************************************************************/

#include <gtest/gtest.h>
#include "matrix.h"


TEST(test_matrix, test_num_rows_cols) {
    Matrix mat(3, 2);
    EXPECT_EQ(mat.NumRows(), 3);
    EXPECT_EQ(mat.NumCols(), 2);
}

TEST(test_matrix, test_assign_elem) {
    Matrix mat(3, 2);
    mat.at(0, 1) = 5.2;
    EXPECT_EQ(mat.at(0, 1), 5.2);
    EXPECT_EQ(mat.at(2, 0), 0.0);
}
