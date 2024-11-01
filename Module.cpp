#include <iostream>
#include <Windows.h>

using namespace std;
class TMatrix {
	double m_matrix[4][4];
public:
	//Конструктор без параметрів заповнює всю матрицю нулями
	TMatrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m_matrix[i][j] = 0;
			}
		}
	}

	//Метод для задання елементів матриці
	virtual void inputEl()  {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << "Введіть m_matrix[" << i << "][" << j << "] : ";
				cin>>m_matrix[i][j];
			}
		}
	}
	//Метод для виведення елементів матриці на екран

	virtual void outputEl()  const {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " m_matrix[" << i << "][" << j << "] = ";
				cout << m_matrix[i][j]<<endl;
			}
		}
	}
	//Метод для знаходження максимального елемента
	virtual double getMaxEl()  const {
		double max = m_matrix[0][0];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (m_matrix[i][j] > max) {
					max = m_matrix[i][j];
				}
			}
		}
		return max;
	}
};


class TVector1 : public TMatrix {
	double m_vector[4];
public:
	//Конструктор без параметрів заповнює вектор

	TVector1() {
		for (int i = 0; i < 4; i++) {
				m_vector[i] = 0;
		}
	}

	//Метод для задання елементів вектора

	virtual void inputEl()  override {
		for (int i = 0; i < 4; i++) {
				cout << "Введіть m_vector[" << i  << "] : ";
				cin >> m_vector[i];
		}
	}

	//Метод для виведення елементів вектора на екран

	virtual void outputEl()  const override {
		for (int i = 0; i < 4; i++) {
				cout << " m_vector[" << i <<  "] = ";
				cout << m_vector[i] << endl;
		}
	}

	//Метод для знаходження максимального елемента

	virtual double getMaxEl() const override {
		double max = m_vector[0];
		for (int i = 0; i < 4; i++) {
				if (m_vector[i] > max) {
					max = m_vector[i];
			}
		}
		return max;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TMatrix matrix1;
	matrix1.inputEl();
	matrix1.outputEl();
	double max_matrix = matrix1.getMaxEl();

	TVector1 vector1;

	vector1.inputEl();
	vector1.outputEl();
	double max_vector=vector1.getMaxEl();

	cout << "Найбільний елемента введеної матриці: " << max_matrix << endl;
	cout << "Найбільний елемента введеного вектора: " << max_vector << endl;

}
