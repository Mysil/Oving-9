#pragma once
#include <iostream> 


using namespace std; 


class Matrix 
{
private: 

    int *rows;
    int *cols; 
    double **matrix;

public:

    Matrix();                               //Ugylding konstruktør 
    Matrix(int, int, double val = 0);       //Standard konstruktør
    explicit Matrix(int nRows);             //Konstruktør for identitetsmatriser
    ~Matrix();                              //Destruktør
    Matrix(const Matrix& rhs);              //Kopikonstruktør  
    Matrix& operator=(Matrix rhs);          //Tilordningsoperator
    Matrix& operator+=(Matrix rhs);
    Matrix operator+(Matrix rhs);                                                
    double get(int row, int col) const {return matrix[row][col];};
    void set(int row, int col, double val) {matrix[row][col] = val;};
    int getRows() const {return *rows;};
    int getColumns() const {return *cols;};
    bool isValid() const {return matrix != nullptr;};
    void printMemLoc() const;

};


ostream& operator<<(ostream& os, Matrix& A);





