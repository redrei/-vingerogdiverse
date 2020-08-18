#pragma once
#include "iostream"
class Matrix{
    private:
        int m;
        int n;
        double ** matrix;
    public:
        Matrix();
        Matrix(int m, int n);
        explicit Matrix(int m);
        ~Matrix();
        double get(int row, int col) const;
        void set(int row, int col, double value);
        double* operator [](int index);
        int getRows() const;
        int getColumns() const;
        bool isValid() const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
        Matrix(const Matrix & rhs);
        void operator=(const Matrix & rhs);
        Matrix operator+=(const Matrix& rhs);
        Matrix operator+(const Matrix& rhs);
};