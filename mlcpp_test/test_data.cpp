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
#include "data.h"


TEST(test_data, test_Tokenize) {
    std::string input = "Asking,only,workman's,wages,I,come,looking,for,a,job";
    std::vector<std::string> expected_output = {
            "Asking", "only", "workman's", "wages", "I", "come", "looking", "for", "a", "job"};
    std::vector<std::string> actual_output = Tokenize(input, ',');
    EXPECT_EQ(expected_output, actual_output);
}

TEST(test_data, test_Tokenize_no_delimiters) {
    std::string input = "Asking";
    std::vector<std::string> expected_output = {"Asking"};
    std::vector<std::string> actual_output = Tokenize(input, ',');
    EXPECT_EQ(expected_output, actual_output);
}

TEST(test_data, test_Tokenize_missing_values) {
    std::string input = ",only,,wages,";
    std::vector<std::string> expected_output = {"", "only", "", "wages", ""};
    std::vector<std::string> actual_output = Tokenize(input, ',');
    EXPECT_EQ(expected_output, actual_output);
}

TEST(test_data, test_TokenMatrixToDataSet) {
    std::vector<std::vector<std::string>> token_mat = {{"3.1", "4.1", "5.9", "2"},
                                                       {"6.5", "3.5", "8.9", "7"},
                                                       {"9.3", "2.3", "8.4", "6"}};
    Matrix X(3, 3);
    X.at(0, 0) = 3.1;
    X.at(0, 1) = 4.1;
    X.at(0, 2) = 5.9;
    X.at(1, 0) = 6.5;
    X.at(1, 1) = 3.5;
    X.at(1, 2) = 8.9;
    X.at(2, 0) = 9.3;
    X.at(2, 1) = 2.3;
    X.at(2, 2) = 8.4;
    std::vector<int> y = {2, 7, 6};
    DataSet expected_output{X, y};
    DataSet actual_output = TokenMatrixToDataSet(token_mat);
    EXPECT_EQ(expected_output, actual_output);
}
