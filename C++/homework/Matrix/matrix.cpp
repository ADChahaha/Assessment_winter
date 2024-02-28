#include "matrix.h"

Matrix::Matrix(int matrix_rows,int matrix_cols)
{
    rows = matrix_rows;
    cols = matrix_cols;
    matrix = new int*[rows];
    for(int i = 0;i < cols;++i)
    {
        matrix[i] = new int[cols];
    }
}

Matrix::~Matrix()
{
    for(int i = 0;i < cols;++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix Matrix::operator*(Matrix& other)
{
    Matrix new_matrix(rows,other.cols);
    for(int row = 0;row < new_matrix.rows;++row)
    {
        for(int col = 0;col < new_matrix.cols;++col)
        {
            new_matrix.matrix[row][col] = 0;
            for(int i = 0;i < new_matrix.cols;++i)
            {
                new_matrix.matrix[row][col] += matrix[row][i]*other.matrix[i][col];
            }
        }
    }
    return new_matrix;
}

std::ostream& operator<<(std::ostream& os,const Matrix& matrix)
{
    for(int i = 0;i < matrix.rows;++i)
    {
        for(int j = 0;j < matrix.cols;++j)
        {
            std::cout << matrix.matrix[i][j] << ' ';
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is,Matrix& matrix)
{
    for(int i = 0;i < matrix.rows;++i)
    {
        for(int j = 0;j < matrix.cols;++j)
        {
            is >> matrix.matrix[i][j];
        }
    }
    return is;
}