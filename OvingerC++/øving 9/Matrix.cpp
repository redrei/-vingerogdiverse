#include "Matrix.h"    
double Matrix::get(int row, int col) const{
    return matrix[row][col];
}
void Matrix::set(int row, int col, double value){
    matrix[row][col] = value;
}
double* Matrix::operator[](int index){
    //returnerer en rad av matrisen
    return matrix[index];
}
int Matrix::getRows() const{
    return m;
}
int Matrix::getColumns() const{
    return n;
}
bool Matrix::isValid() const{
    return  not(matrix == nullptr);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    if(!mat.isValid()){
        //returnerer en tom os hvis det er en ugyldig matrise
        return os;
    }
    //skriver ut alle verdiene, med en endl mellom hver rad
    for(int i = 0; i<mat.m;i++){
        for(int k = 0; k<mat.n;k++){
            os << mat.matrix[i][k] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix::Matrix(int m, int n):m{m},n{n}{
    //lager en array pointere til arrayer
    matrix = new double*[m];
    for(int i = 0; i<m;i++){
        //fyller opp arrayene med 0 og legger de inn i matrisen som rader
        double*row = new double[n]{0};
        matrix[i] = row;
    }
}
Matrix::Matrix(int m):Matrix{m,m}{
    //har allerede laget en nullmatrise, så nå fyller jeg inn alle de diagonale feltene med 1'ere
    for(int i = 0; i < m; i++){
        matrix[i][i] = 1;
    }
}
Matrix::Matrix(){
    //referer til nullpointer og m og n settes til null
    matrix = nullptr;
    n = 0;
    m=0;
}
Matrix::~Matrix(){
    //sletter alle arrayene, før jeg så sletter pointerarrayen
    for(int i = 0; i<m; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
Matrix::Matrix(const Matrix & rhs){
    if(rhs.isValid()){
        //hvis rhs er en gyldig matrise kopierer jeg m og n, lager en tom matrise før jeg så tar en dyp kopiering av alle verdiene
        m = rhs.m;
        n = rhs.n;
        matrix = new double*[m];
        for(int i = 0; i<m;i++){
            double*row = new double[n]{0};
            matrix[i] = row;
        }
        for(int i = 0; i<m; i++){
            for(int k=0; k<n;k++){
                matrix[i][k] = rhs.matrix[i][k];
            }
        }
    }else{
        //lager ugyldig matrise
        matrix = nullptr;
        n = 0;
        m = 0;
    }
}

void Matrix::operator=(const Matrix & rhs){
    //akkurat det samme som kopikonstruktøren
    if(rhs.isValid()){
        m = rhs.m;
        n = rhs.n;
        matrix = new double*[m];
        for(int i = 0; i<m;i++){
            double*row = new double[n]{0};
            matrix[i] = row;
        }
        for(int i = 0; i<m; i++){
            for(int k=0; k<n;k++){
                matrix[i][k] = rhs.matrix[i][k];
            }
        }
    }else{
        matrix = nullptr;
        m=0;
        n=0;
    }
}

Matrix Matrix::operator+=(const Matrix& rhs){
    if(m != rhs.m or n != rhs.n){
        //setter matrisen til å være ugyldig
        matrix = nullptr;
        n=0;
        m=0;
    }else{
        //hvis matrisene er like så plusses felt for felt av arrayene sammen
        for(int i =0;i<m;i++){
            for(int k=0;k<n;k++){
                matrix[i][k]+=rhs.matrix[i][k];
            }
        }
    }
    //returnerer denne matrisen som resultat, siden det er resultatet
    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs){
    //lager en kopi av matrisen til venstre av pluss tegnet, og returnerer kopi += rhs
    Matrix temp{*this};
    return temp+=rhs;
}