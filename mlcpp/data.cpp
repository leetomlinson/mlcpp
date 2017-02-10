/*****************************************************************************
 * Copyright (C) 2017 Lee Tomlinson
 *
 * This file is part of MLCPP.
 *
 * MLCPP is licensed under the terms of Attribution-NonCommercial 4.0
 * International (CC BY-NC 4.0).  For more information see
 * https://creativecommons.org/licenses/by-nc/4.0/
 *****************************************************************************/

#include "data.h"
#include <fstream>


/**
 * Defines equality between two data sets.
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool operator==(DataSet const &lhs, DataSet const &rhs) {
    return lhs.X == rhs.X && lhs.y == rhs.y;
}

/**
 * Loads attribute and class data from a csv file, interpreting the last column as class data.
 *
 * @param path
 * @return
 */
DataSet LoadCsvData(std::string const &path) {
    std::vector<std::vector<std::string>> token_mat;

    std::ifstream in_file;
    in_file.open(path, std::ios::in);

    if (in_file.is_open()) {
        std::string line;

        while (in_file.good()) {
            std::getline(in_file, line, '\n');
            token_mat.push_back(Tokenize(line, ','));
        }

        in_file.close();
    } else {
        throw std::runtime_error("Unable to open file: " + path);
    }

    return TokenMatrixToDataSet(token_mat);
}

/**
 * Splits a string into tokens according to a delimiter.
 *
 * @param str
 * @return
 */
std::vector<std::string> Tokenize(std::string const &str, char delim) {
    std::vector<std::string> token_arr;
    size_t start_pos = 0;
    size_t end_pos = 0;

    while (end_pos != std::string::npos) {
        end_pos = str.find(delim, start_pos);
        std::string token = str.substr(start_pos, end_pos - start_pos);
        token_arr.push_back(token);
        start_pos = end_pos + 1;
    }

    return token_arr;
}

/**
 * Converts a matrix of string tokens to a matrix of attributes and a vector of classes.
 *
 * @param token_mat
 * @return
 */
DataSet TokenMatrixToDataSet(std::vector<std::vector<std::string>> token_mat) {
    // token_mat[0].size() < 2 is tested only if token_mat.size() >= 1, avoiding an out-of-range error
    if (token_mat.size() < 1 || token_mat[0].size() < 2) {
        throw std::length_error("Too few rows or columns");
    }

    size_t n_rows = token_mat.size();
    size_t row_length = token_mat[0].size();

    // Initialize attribute matrix and class vector
    Matrix X(n_rows, row_length - 1);
    std::vector<int> y;

    for (size_t row = 0; row < n_rows; ++row) {
        if (token_mat[row].size() != row_length) {
            throw std::length_error("Inconsistent row length");
        }

        for (size_t col = 0; col < X.NumCols(); ++col) {
            X.at(row, col) = std::stod(token_mat[row][col]);
        }

        y.push_back(std::stoi(token_mat[row][row_length]));
    }

    return DataSet{X, y};
}
