#include<iostream>
#include "matrix.h"

int main() {
    int rows, cols;

    std::cin >> rows >> cols;
    Matrix A(rows, cols);
    std::cin >> A;

    std::cin >> rows >> cols;
    Matrix B(rows, cols);
    std::cin >> B;
    
    std::cout << A * B << std::endl;

    int matrix[2][2] = {1,2,3,4};
    int** num = new int*[2];
    num[0] = new int[2];
    num[1] = new int[2];
    for(int i = 0;i < 2;++i)
    {
        for(int j = 0;j < 2;++j)
        {
            num[i][j] = i + j + 1;
        }
    }
    Matrix G(2,2,num); //Matrix(int row,int col,int** matrix)
    Matrix C(matrix); //template<int rows,int cols>Matrix(int (&matrix)[rows][cols])
    Matrix D(C); //Matrix(const Matrix& other)
    Matrix E(A * B); //Matrix(Matrix&& other)
 
    std::cout << A + B << std::endl; //A + B
    std::cout << A - B << std::endl; //A - B

    
    E = A;  // Matrix operator=(const Matrix& other)
    std::cout << E << std::endl; 
    Matrix F; 
    F = Matrix(); // Matrix operator=(Matrix&& other)
    std::cout << (A == B) << std::endl;  //bool operator==(const Matrix& other)



    return 0;
}