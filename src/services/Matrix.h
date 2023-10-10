//
// Created by eramoss on 10/10/23.
//

#ifndef BOMBEDCORE_MATRIX_H
#define BOMBEDCORE_MATRIX_H


#include <iostream>

template<class T> class Matrix {
private:
    int rows;
    int cols;
    T** data;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void set(int row, int col, double value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            throw std::runtime_error("Index out of range");
        }
    }

    double get(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            throw std::runtime_error("Index out of range");
        }
    }

    int numRows() const {
        return rows;
    }

    int numCols() const {
        return cols;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};


#endif //BOMBEDCORE_MATRIX_H
