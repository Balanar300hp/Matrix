// ConsoleApplication25.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>

Matrix::Matrix(): rows(0), columns(0)//конструктор инициализации 
{
	_matrix = new int*[0];
	_matrix[0] = new int[0];
}

Matrix::Matrix(int _rows, int _columns):rows(_rows),columns(_columns)//конструктор с параметрами 
{
	_matrix = new int*[rows];

	for (int i = 0; i< rows; i++)
		_matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++) { //  обнуление массива
		for (int j = 0; j < columns; j++) _matrix[i][j] = 0;
	};
}

Matrix::Matrix(const Matrix & matrix):rows(matrix.rows),columns(matrix.columns)//конструктор копирования 
{
	_matrix = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		_matrix[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
			_matrix[i][j] = matrix._matrix[i][j];
	}
}

Matrix::~Matrix() // деструктор
{
	for (int i = 0; i < rows; i++)
		delete[] _matrix[i];

	delete[] _matrix;
}

void Matrix::Get_Matrix(string s2) // получаем матрицу из файла
{
	string s1;
	s1 = s2 + ".txt";
	ifstream fin(s1); // сконструируем объект класса ifstream для ввода из файла
	if (fin.is_open()) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				fin >> _matrix[i][j]; // выводим из файла данные
		fin.close(); // закрываем файл
	}
	else {
		cout << "Error name";
		exit(0);
	}
}
void Matrix::Cout_Matrix() // вывод матрицы
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << " " << _matrix[i][j];
		};
		cout << "\n";
	};
}


Matrix& Matrix::operator =(const Matrix& matrix1) {
	if (this != &matrix1) {
		(Matrix(matrix1)).swap(*this);
	}
	return *this;
}
Matrix Matrix::operator +(const Matrix &firstMatrix) {
	
	Matrix result(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			result[i][j] = firstMatrix._matrix[i][j] + this->_matrix[i][j];
		}
	}
	return result;
}


Matrix Matrix::operator *(const Matrix &m) {
	Matrix result(this->rows, m.columns);
	int a = 0;

	for (int row = 0; row < this->rows; row++) {
		for (int col = 0; col < m.columns; col++) {
			a = 0;
			for (int i = 0; i < this->columns; i++) {
				a = a + this->_matrix[row][i] * m._matrix[i][col];
			}
			result._matrix[row][col] = a;
		}
	}
	return result;
}


int Matrix::get_rows() // получаем кол-во строк
{
	return rows;
}

int Matrix::get_columns()// получаем кол-во столбцов 
{
	return columns;
}

int* Matrix::operator [] (int index)// перегружаем оператор [] на входе получили номер строки
{
	return this->_matrix[index];

}
void Matrix::swap(Matrix & m1) {
	std::swap(m1._matrix, _matrix);
	std::swap(m1.columns, columns);
	std::swap(m1.rows, rows);

}

void enter() {
	cout << "\n";

}
int main()
{
	string s1;
	setlocale(LC_ALL, "Russian");
	cout << "Введите размерность матрицы: строки и столбцы" << endl;
	int a, b;
	cin>>a;
	cin>>b;
	cout <<"Введите имя файла"<<"\n";
	cin >> s1;
	Matrix _matrix(a, b);
	_matrix.Get_Matrix(s1);
	_matrix.Cout_Matrix();
	enter();
	Matrix _matrix2(a, b);
	_matrix2 = _matrix + _matrix;
	_matrix2.Cout_Matrix();
	enter();
	Matrix _matrix3(a, b);
	_matrix3 = _matrix * _matrix;
	_matrix3.Cout_Matrix();
	enter();
	int *row_matrix;
	row_matrix = _matrix[1];
	for (int i = 0; i < _matrix.get_columns(); i++)
	cout << " " << row_matrix[i];
	enter();
	cout << " " << _matrix.get_columns() << endl;
	cout << " " << _matrix.get_rows() << endl;

	system("pause");
    
}

