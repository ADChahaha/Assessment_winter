#include <iostream>

class Matrix
{
    friend std::istream& operator>>(std::istream& is,Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os,const Matrix& matrix);

private:
    int rows;
    int cols;
    int** matrix;
public:
    Matrix(int matrix_rows,int matrix_cols);
    ~Matrix();
    Matrix operator*(Matrix& other);
};

std::istream& operator>>(std::istream& is,Matrix& matrix);
std::ostream& operator<<(std::ostream& os,const Matrix& matrix);