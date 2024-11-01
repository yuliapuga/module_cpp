#include <iostream>
#include <Windows.h>

using namespace std;
class TMatrix {
	double m_matrix[4][4];
public:
	//����������� ��� ��������� �������� ��� ������� ������
	TMatrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m_matrix[i][j] = 0;
			}
		}
	}

	//����� ��� ������� �������� �������
	virtual void inputEl()  {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << "������ m_matrix[" << i << "][" << j << "] : ";
				cin>>m_matrix[i][j];
			}
		}
	}
	//����� ��� ��������� �������� ������� �� �����

	virtual void outputEl()  const {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " m_matrix[" << i << "][" << j << "] = ";
				cout << m_matrix[i][j]<<endl;
			}
		}
	}
	//����� ��� ����������� ������������� ��������
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
	//����������� ��� ��������� �������� ������

	TVector1() {
		for (int i = 0; i < 4; i++) {
				m_vector[i] = 0;
		}
	}

	//����� ��� ������� �������� �������

	virtual void inputEl()  override {
		for (int i = 0; i < 4; i++) {
				cout << "������ m_vector[" << i  << "] : ";
				cin >> m_vector[i];
		}
	}

	//����� ��� ��������� �������� ������� �� �����

	virtual void outputEl()  const override {
		for (int i = 0; i < 4; i++) {
				cout << " m_vector[" << i <<  "] = ";
				cout << m_vector[i] << endl;
		}
	}

	//����� ��� ����������� ������������� ��������

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

	cout << "��������� �������� ������� �������: " << max_matrix << endl;
	cout << "��������� �������� ��������� �������: " << max_vector << endl;

}