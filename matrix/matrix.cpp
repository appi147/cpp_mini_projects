#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
class matrix
{
	double **p;
	int d1,d2;
	void identity (void);
	public:
		matrix (int, int);
		void print (void);
		friend matrix transpose (matrix);
		void inverse (void);
		inline void begin (int,int);
		matrix operator + (matrix);
		matrix operator - (matrix);
		friend matrix operator * (matrix, matrix);
		void operator = (float);
		matrix operator / (float);
		matrix operator + (float);
		matrix operator - (float);
		matrix operator * (float);
		void operator = (matrix);
};
matrix :: matrix (int x, int y)
{
	d1 = x;
	d2 = y;
	p = new double *[d1];
	for (int i = 0; i < d1; i++)
	{
		p[i] = new double[d2];
	}
}
matrix transpose (matrix A)
{
	matrix B(A.d2, A.d1);
	for(int i = 0;i < A.d1; i++)
	{
		for (int j = 0; j < A.d2; j++)
		{
			B.p[j][i] = A.p[i][j];
		}
	}
	return B;
}
void matrix :: identity (void)
{
	for (int i = 0; i < d1; i++)
		for (int j = 0; j < d2; j++)
			p[i][j] = 0;
	for(int i = 0; i < d1; i++)
		p[i][i] = 1;
}
void matrix :: inverse (void)
{
	float v;
	matrix B (d1, d2);
	B.identity();
	for (int i = 0; i < d1; i++)
	{
		v = p[i][i];
		for (int j = 0; j < d2; j++)
		{
			p[i][j] /= v;
			B.p[i][j] /= v;
		}
		for (int k = 0; k < d1; k++)
		{
			float m, n;
			m = p[k][i];
			if (i != k);
			{
				for (int j = 0; j < d2; j++)
				{
					p[k][j] -= ( ( p[i][j] ) * m);
					B.p[k][j] -= ( ( B.p[i][j] ) * m);
				}
			}
		}
	}
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)
		{
			p[i][j] = B.p[i][j];
		}
	}
}
void declare (int &m, int &n)
{
	cout << "\nEnter no of rows followed by no of columns\n";
	cin >> m >> n;
}
inline void matrix :: begin (int a, int b)
{
	float val;
	cout << "\nEnter elements row by row (using spaces)" << endl;
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)			
		{
			cin >> val;
			p[i][j] = val;
		}
	} 
}
void matrix :: print (void)
{
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)
		{
			cout.width(9);
			cout.precision(3);
			cout.setf(ios::showpoint);
			cout << p[i][j] << " \n"[j==d2-1];
		}
	}
}
matrix matrix :: operator + (matrix c)
{
	matrix temp (d1, d2);
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] + c.p[i][j];
		}
	}
	return (temp);
}
matrix matrix :: operator - (matrix c)
{
	matrix temp (d1, d2);
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] - c.p[i][j];
		}
	}
	return (temp);
}
matrix operator * (matrix d, matrix c)
{
	matrix temp (d.d1, c.d2);
	temp = 0;
	for (int i = 0; i < d.d1; i++)
	{
		for (int j = 0; j < c.d2; j++)			
		{
			for (int k = 0; k < d.d2; k++)
			{
				temp.p[i][j] += d.p[i][k] * c.p[k][j];
			}
		}
	}
	return (temp);
}
void matrix :: operator = (matrix A)
{
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			p[i][j] = A.p[i][j];
		}
	}
}
void matrix :: operator = (float a)
{
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			p[i][j] = a;
		}
	}
}
matrix matrix :: operator + (float f)
{
	matrix temp (d1, d2);
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] + f;
		}
	}
	return temp;
}
matrix matrix :: operator - (float f)
{
	matrix temp (d1, d2);
	for(int i = 0; i < d1; i++)
	{
		for(int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] - f;
		}
	}
	return temp;
}
matrix matrix :: operator * (float f)
{
	matrix temp (d1, d2);
	for (int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] * f;
		}
	}
	return temp;
}
matrix matrix :: operator / (float f)
{
	matrix temp (d1, d2);
	for(int i = 0; i < d1; i++)
	{
		for (int j = 0; j < d2; j++)			
		{
			temp.p[i][j] = p[i][j] / f;
		}
	}
	return temp;
}
void list (void)
{
	cout << "\n\t\t\t\t1. Transpose\n\t\t\t\t2. Add\n\t\t\t\t3. Subtract\n\t\t\t\t";
	cout << "4. Multiply\n\t\t\t\t5. As a Sum of Symmetric and ";
	cout << "\n\t\t\t\t   Skew Symmetric Matrix\n\t\t\t\t6. Inverse\n\t\t\t\t";
	cout << "7. Exit\n\t\tPress any other button to reproduce this menu\n";
}
int main()
{
	cout << "\t\t\t\tHi Everyone!\n\t\tThis program can do following operations on matrices\n";
	list();
	while(true)
	{
		char choice;
		int a, b;
		cout << "\n\t\t\tEnter any choice\n\t\t\t\t";
		choice = getchar();
		if (choice == '1')
		{
			declare (a, b);
			matrix  A(a, b);
			matrix  B(b, a);
			A.begin(a, b);
			B = transpose(A);
			B.print();
		}
		else if (choice == '2')
		{
			declare(a, b);
			matrix A(a, b);
			matrix B(a, b);
			matrix C(a, b);
			cout << "\t\t\tMatrix 1:\n";
			A.begin(a, b);
			cout << "\t\t\tMatrix 2:\n";
			B.begin(a, b);
			C = A + B;
			C.print();
		}
		else if (choice == '3')
		{
			declare (a, b);
			matrix A(a, b);
			matrix B(a, b);
			matrix C(a, b);
			cout << "\t\t\tMatrix 1:\n";
			A.begin(a, b);
			cout << "\t\t\tMatrix 2:\n";
			B.begin(a, b);
			C = A - B;
			C.print();
		}
		else if (choice == '4')
		{
			cout << "\n\t\tLet me remind you a fact on matrices\n m1 x n1 and m2 x n2 ";
			cout << "matrix can be multiplied only when n1 and m2 are equal\n";
			printf("\t\t\t\t%c\n\n", 1);
			cout << "\t\t\tMatrix 1:\n";
			declare(a, b);
			cout << "\t\t\tMatrix 2:\n";
			int d, e;
			declare(d, e);
			if (b == d)
			{
				matrix A(a,b);
				matrix B(d,e);
				matrix C(a,e);
				cout << "\t\t\tMatrix 1:\n";
				A.begin(a,b);
				cout<<"\t\t\tMatrix 2:\n";
				B.begin(d,e);
				C = A * B;
				C.print();
			}
			else
				cout << "\n\n\t\t\t\tTOLD YA!!!\n\n";
		}
		else if (choice == '5')
		{
			cout << "\n\t\t\tAnother quick fact\n\t";
			cout << "Operation can only be performed when no of rows and columns are equal";
			declare(a, b);
			if (a == b)
			{
				matrix A(a, a);
				A.begin(a, a);
				matrix B(a, a);
				B = transpose(A);
				matrix C(a, a);
				matrix D(a,a);
				C = A + B;
				D = A - B;
				C = C / 2;
				D = D / 2;
				cout << "\t\t\t\tSymmetric Matrix:\n";
				C.print();
				cout << "\t\t\t\tSkew Symmetric Matrix:\n";
				D.print();
			}
			else
				cout << "\n\t\t\t\tTOLD YA!!!\n\n";
		}
		else if (choice == '6')
		{
			cout << "\n\t\t\tJust Another Quick Fact";
			cout << "\n  Inverse of a matrix can only be found if it has equal no of rows and columns";
			declare(a, b);
			if (a == b)
			{
				matrix A(a, b);
				A.begin(a, b);
				A.inverse();
				A.print();
			}
			else
				cout << "\n\t\t\t\tTOLD YA!!!\n\n";
		}
		else if (choice == '7')
			exit(0);
		else
			list();
	}
	return 0;
}
