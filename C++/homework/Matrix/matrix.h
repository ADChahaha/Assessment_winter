#include <iostream>

class Matrix
{
    friend std::istream& operator>>(std::istream& is,Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os,const Matrix& matrix);

private:
    int rows;
    int cols;
    int** matrix;
    void deleteData();
public:
    Matrix(int matrix_rows,int matrix_cols);
    Matrix(int rows, int cols, int** matrix);
    Matrix();
    template<int rows,int cols>
    Matrix(int (&matrix)[rows][cols])
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
    Matrix(Matrix&& other);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix operator*(Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix &&other);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator/(const Matrix& other);
    bool operator==(const Matrix& other);
};

std::istream& operator>>(std::istream& is,Matrix& matrix);
std::ostream& operator<<(std::ostream& os,const Matrix& matrix);


