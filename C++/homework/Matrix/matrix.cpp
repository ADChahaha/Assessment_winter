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
    if(matrix == NULL)
        return;
    for(int i = 0;i < cols;++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix Matrix::operator*(Matrix& other)
{
    if((rows != other.rows) || (cols != other.cols))
        return Matrix();
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

Matrix::Matrix(int rows, int cols, int** matrix)   
{
    this->rows = rows;
    this->cols = cols;
    this->matrix = new int*[rows];
    for(int i = 0;i < cols;++i)
    {
        this->matrix[i] = new int[cols];
    }
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& other)
{
    rows = other.rows;
    cols = other.cols;
    this->matrix = new int*[rows];
    for(int i = 0;i < cols;++i)
    {
        this->matrix[i] = new int[cols];
    }
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other)
{
    rows = other.rows;
    cols = other.cols;
    this->matrix = std::move(other.matrix);
    other.matrix = NULL;
}

Matrix::Matrix()
{
    rows = cols = 0;
    matrix = NULL;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if(matrix != NULL)
    {
        deleteData();
    }
    rows = other.rows;
    cols = other.cols;
    this->matrix = new int*[rows];
    for(int i = 0;i < cols;++i)
    {
        this->matrix[i] = new int[cols];
    }
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix &&other)
{
    if(matrix != NULL)
    {
        deleteData();
    }
    rows = other.rows;
    cols = other.cols;
    this->matrix = other.matrix;
    other.matrix = NULL;
    return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
    if((rows != other.rows) || (cols != other.cols))
        return Matrix();
    Matrix result(*this);
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            result.matrix[i][j] += other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other)
{
    if((rows != other.rows) || (cols != other.cols))
        return Matrix();
    Matrix result(*this);
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            result.matrix[i][j] -= other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator/(const Matrix& other)
{
    //inverse matrix

}

bool Matrix::operator==(const Matrix& other) 
{
    if(rows != other.rows || cols != other.cols)
        return false;
    for(int i = 0;i < rows;++i)
    {
        for(int j = 0;j < cols;++j)
        {
            if(matrix[i][j] != other.matrix[i][j])
                return false;
        }
    }
    return true;
}

void Matrix::deleteData()
{
    for(int i = 0;i < cols;++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}