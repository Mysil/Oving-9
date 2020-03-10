#include "Matrix.h"
#include <iostream>
#include <utility>
#include <iomanip> 

using namespace std; 


//Konstruerer en rows x cols dim matrise
Matrix::Matrix(int row, int col, double val)
{
    rows = new int(row);
    cols = new int(col);
    matrix = new double*[*rows];
    for(int i = 0; i < *rows; i++)
    {
        matrix[i] = new double[*cols];

        for(int j = 0; j < *cols; j++)
        {
            matrix[i][j] = val; 
        }
    }
}

//Konstruerer en "ugyldig matrise"
Matrix::Matrix() : matrix{nullptr} 
{
    rows = new int(0);
    cols = new int(0);
}



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
        for (int j = 0; j < *rows; j++)
        {
            delete[] matrix[j];
            matrix[j] = nullptr;
        }

        delete[] matrix; 
        matrix = nullptr;
        delete rows; 
        delete cols;
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

//Dyp kopiering av eksisterende matrise, allokerer nytt minne. 
Matrix::Matrix(const Matrix& rhs)
{  
    if (rhs.isValid() == true)
    {   
        rows = new int(*rhs.rows); 
        cols = new int (*rhs.cols);
        matrix = new double*[*rows];

        for (int i = 0; i<*rows; i++)
        {
            matrix[i] = new double[*cols];
            for(int j = 0; j<*cols; j++)
            {
                matrix[i][j] = rhs.matrix[i][j];
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



Matrix& Matrix::operator+=(Matrix rhs)
{
    if (!(*cols == *rhs.cols && *rows == *rhs.rows))
    {
       return *this = Matrix{};
    }
    else
    {
        for (int i = 0; i<*rows; i++)
        {
            for (int j = 0; j<*cols; j++)
            {
                matrix[i][j] += rhs.matrix[i][j];
            }
        }
        return *this;
    }
}

Matrix Matrix::operator+(Matrix rhs)
{
    if (!(*cols == *rhs.cols && *rows == *rhs.rows))
    {
       Matrix product{};
       return product; 
    }
    else
    {
        Matrix product{*rows, *cols};
         for (int i = 0; i<*rows; i++)
        {
            for (int j = 0; j<*cols; j++)
            {
                product.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
            }
        }
        return product;
    }
}
