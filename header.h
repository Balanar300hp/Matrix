#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;
class Matrix {
public:
	Matrix();
	Matrix(int _rows, int _columns);
	Matrix(const Matrix &matrix);
	~Matrix();
	void Get_Matrix(string s);
	void Cout_Matrix();
	void Copy_Matrix(const Matrix &matrix);
	Matrix &operator=(const Matrix &matrix);
	friend Matrix operator+(const Matrix &firstMatrix, const Matrix &secondMatrix);
	friend Matrix operator*(const Matrix &firstMatrix, const Matrix &secondMatrix);
	int* operator [](int i);
	void   NewMemory();
	int get_rows();
	int get_columns();
private:
	string s{};
	int rows{};
	int columns{};
	int **_matrix{};
};
