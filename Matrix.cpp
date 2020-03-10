#include "Matrix.h"
#include <iostream>
#include <utility>

using namespace std; 


//Konstruerer en rows x cols dim matrise
Matrix::Matrix(int row, int col, double val) : rows{row}, cols{col}
{
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];

        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = val; 
        }
    }
}

//Konstruerer en "ugyldig matrise"
Matrix::Matrix() : rows{0}, cols{0}, matrix{nullptr} {}

//Konstruerer en identitesmatrise
Matrix::Matrix(int nRows) : Matrix{nRows, nRows}
{
    for(int i = 0; i < nRows; i++)
    {
        matrix[i][i] = 1; 
    }
}


//Frigjør minne allokert i konstruktøren 
Matrix::~Matrix()
{
    if (this->isValid()==true)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix; 
        matrix = nullptr;
    }   
}

//Overlaster << operatøren for printing av matriser
ostream& operator<<(ostream& os, Matrix& A)
{
    if (A.isValid() == false)
    {
        os << "Ugyldig matrise";
        return os; 
    }
    else
    {   
        for (int i = 0; i<A.getRows(); i++)
        {
            for (int j=0; j<A.getColumns(); j++)
            {
                os << A.get(i,j) << "  " ; 
            }
        os << endl;
        }
    return os; 
    }
}

//Hjelpefunksjon som skriver ut minnelokasjonen til matrisen
void Matrix::printMemLoc() const 
{
    cout << matrix;
}

//Enkel test som tester at alle tre konstruktørene fungerer slik de skal
void testMatrixClass()
{
    Matrix A{8,7};
    Matrix B{5};
    Matrix C{};
    Matrix D{C};
    Matrix E{};
    E=B; 
    
    cout << E;
    
    E.printMemLoc();
    cout << endl; 
    B.printMemLoc();    
}


//Dyp kopiering av eksisterende matrise, allokerer nytt minne. 
Matrix::Matrix(const Matrix& rhs)
{  
    if (rhs.isValid() == true)
    {   
        rows = rhs.rows; 
        cols = rhs.cols;
        matrix = new double*[rows];

        for (int i = 0; i<rows; i++)
        {
            matrix[i] = new double[cols];
            for(int j = 0; j<cols; j++)
            {
                this->matrix[i][j] = rhs.matrix[i][j];
            }
        }
    }
    else
    {
        matrix = nullptr;
    }   
}

//Overlasting av tilordningsoperator, dyp kopiering
Matrix& Matrix::operator=(Matrix rhs)
{
    std::swap(rows, rhs.rows);
    std::swap(cols, rhs.cols);
    std::swap(matrix, rhs.matrix);

    return *this; 
}


