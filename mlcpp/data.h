/*****************************************************************************
 * Copyright (C) 2017 Lee Tomlinson
 *
 * This file is part of MLCPP.
 *
 * MLCPP is licensed under the terms of Attribution-NonCommercial 4.0
 * International (CC BY-NC 4.0).  For more information see
 * https://creativecommons.org/licenses/by-nc/4.0/
 *****************************************************************************/

#ifndef MLCPP_MAIN_DATA_H
#define MLCPP_MAIN_DATA_H

#include <string>
#include <vector>
#include "matrix.h"


struct DataSet {
    Matrix X;
    std::vector<int> y;
};


bool operator==(DataSet const &lhs, DataSet const &rhs);

DataSet LoadCsvData(std::string const &path);

std::vector<std::string> Tokenize(std::string const &str, char delim);

DataSet TokenMatrixToDataSet(std::vector<std::vector<std::string>> token_mat);


#endif //MLCPP_MAIN_DATA_H
