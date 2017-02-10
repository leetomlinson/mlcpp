/*****************************************************************************
 * Copyright (C) 2017 Lee Tomlinson
 *
 * This file is part of MLCPP.
 *
 * MLCPP is licensed under the terms of Attribution-NonCommercial 4.0
 * International (CC BY-NC 4.0).  For more information see
 * https://creativecommons.org/licenses/by-nc/4.0/
 *****************************************************************************/

#ifndef MLCPP_MAIN_MATRIX_H
#define MLCPP_MAIN_MATRIX_H

#include <cstdlib>


class Matrix {
private:
    size_t n_rows_;
    size_t n_cols_;
    double *elem_arr_;

public:
    /**
     * Constructs a new n_rows-by-n_cols matrix and initializes all elements to zero.
     *
     * @param n_rows
     * @param n_cols
     */
    Matrix(size_t n_rows, size_t n_cols) : n_rows_(n_rows), n_cols_(n_cols), elem_arr_(new double[n_rows * n_cols]) {
        for (size_t i = 0; i < n_rows * n_cols; ++i) {
            elem_arr_[i] = 0.0;
        }
    }

    ~Matrix() {
        delete[] elem_arr_;
    }

    double &at(size_t row, size_t col) {
        if (row >= n_rows_ || col >= n_cols_) {
            throw std::out_of_range("Index out of range");
        }
        return elem_arr_[row * n_cols_ + col];
    }

    size_t NumRows() const {
        return n_rows_;
    }

    size_t NumCols() const {
        return n_cols_;
    }
};


#endif //MLCPP_MAIN_MATRIX_H
