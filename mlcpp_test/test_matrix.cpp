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

TEST(test_matrix, test_matrix_equality) {
    Matrix mat1(2, 3);
    Matrix mat2(2, 3);
    mat1.at(0, 0) = mat2.at(0, 0) = 3.1;
    mat1.at(0, 1) = mat2.at(0, 1) = 4.1;
    mat1.at(0, 2) = mat2.at(0, 2) = 5.9;
    mat1.at(1, 0) = mat2.at(1, 0) = 2.6;
    mat1.at(1, 1) = mat2.at(1, 1) = 5.3;
    mat1.at(1, 2) = mat2.at(1, 2) = 5.8;
    EXPECT_EQ(mat1, mat2);
}

TEST(test_matrix, test_matrix_unequal_sizes) {
    Matrix mat1(2, 3);
    Matrix mat2(3, 2);
    EXPECT_EQ(mat1 != mat2, true);
}
