//
// Created by eramoss on 10/10/23.
//

#ifndef BOMBEDCORE_MATRIX_H
#define BOMBEDCORE_MATRIX_H
#include <type_traits>
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
    static Matrix<T>* zero(int numRows, int numCols) {
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");

        auto matrix = new Matrix<T>(numRows, numCols);
        matrix->map([](T &elem){
            elem = 0;
        });

        return matrix;
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

    void map(std::function<void(T & elem)> fn){
        for (int i = 0; i< rows; i++){
            for (int j = 0; j < cols; j++) {
                fn(data[i][j]);
            }
        }
    }

    void for_each(std::function<void(T elem)> fn){
        for (int i = 0; i< rows; i++){
            for (int j = 0; j < cols; j++) {
                fn(data[i][j]);
            }
        }
    }
};


#endif //BOMBEDCORE_MATRIX_H
