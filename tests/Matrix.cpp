//
// Created by eramoss on 10/10/23.
//
#include <gtest/gtest.h>
#include "../src/services/Matrix.h"

TEST(MatrixTest, Constructor) {
Matrix<double> mat(3, 4);
ASSERT_EQ(mat.numRows(), 3);
ASSERT_EQ(mat.numCols(), 4);
}

TEST(MatrixTest, SetAndGet) {
Matrix<double> mat(2, 2);
mat.set(0, 0, 1.0);
mat.set(0, 1, 2.0);
mat.set(1, 0, 3.0);
mat.set(1, 1, 4.0);

ASSERT_DOUBLE_EQ(mat.get(0, 0), 1.0);
ASSERT_DOUBLE_EQ(mat.get(0, 1), 2.0);
ASSERT_DOUBLE_EQ(mat.get(1, 0), 3.0);
ASSERT_DOUBLE_EQ(mat.get(1, 1), 4.0);
}

TEST(MatrixTest, OutOfRange) {
Matrix<double> mat(3, 3);
ASSERT_NO_THROW(mat.set(2, 2, 1.0));  // Should not throw
ASSERT_NO_THROW(mat.get(2, 2));        // Should not throw
ASSERT_THROW(mat.set(3, 0, 1.0), std::runtime_error);
ASSERT_THROW(mat.get(0, 3), std::runtime_error);
}

TEST(MatrixTest, Print) {
testing::internal::CaptureStdout();
Matrix<double> mat(2, 2);
mat.set(0, 0, 1.0);
mat.set(0, 1, 2.0);
mat.set(1, 0, 3.0);
mat.set(1, 1, 4.0);
mat.print();
std::string output = testing::internal::GetCapturedStdout();
ASSERT_EQ(output, "1 2 \n3 4 \n");
}

TEST(MatrixTest, ForEach) {
    Matrix<double> mat(3,3);
    int control_var = 0;
    mat.for_each([&control_var](double elem){
        control_var++;
    });

    ASSERT_EQ(control_var, 9);
}

TEST(MatrixTest, ForEachAttemptChangeElem) {
    auto matrix = Matrix<double>::zero(3,3);
    matrix->for_each([](double elem){
        elem = 1;
    });
    matrix->for_each([](double elem){
        ASSERT_EQ(elem, 0);
    });
}

TEST(MatrixTest, MapChangingElements) {
    auto matrix = Matrix<double>::zero(3,3);
    matrix->map([](double &elem){
        elem = 1;
    });
    matrix->map([](double &elem){
        ASSERT_EQ(elem, 1);
    });
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
