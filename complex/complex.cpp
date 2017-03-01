#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class complex
{
	double real;
	double imaginary;
	public:
		complex(double r=0, double i=0)
		{
			real=r;
			imaginary=i;
		}
		double mod(void)
		{
			return sqrt(real*real + imaginary*imaginary);
		}
		void conjugate(void)
		{
			imaginary = -imaginary;
		}
		complex operator+(complex);
		complex operator-(complex);
		friend complex operator*(complex,complex);
		friend complex operator/(complex,complex);
		friend complex operator/(complex,double);
		void display (void);
		void input(void);
};

void complex::input(void)
{
	cout<<"\nEnter real part : ";
	cin>>real;
	cout<<"\nEnter imag part : ";
	cin>>imaginary;
}
complex complex::operator+(complex c)
{
	complex temp;
	temp.real = this->real+ c.real;
	temp.imaginary = this->imaginary + c.imaginary;
	return (temp);
}
complex complex::operator-(complex c)
{
	complex temp;
	temp.real = this->real- c.real;
	temp.real = this->imaginary - c.imaginary;
	return (temp);
}
complex operator*(complex d,complex c)
{
	complex temp;
	temp.real = (d.real)* (c.real)-(d.imaginary)*(c.imaginary);
	temp.imaginary = (d.imaginary)*(c.imaginary) + (d.real) * (c.imaginary) ;
	return (temp);
}
complex operator/(complex c,double d)
{
	complex temp;
	temp.real = c.real / d;
	temp.imaginary = c.imaginary / d; 
	return (temp);
}
complex operator/(complex c,complex d)
{
	complex temp;
	double t;
	t = d.mod();
	d.conjugate();
	temp = c * d;
	t = pow(t,2);
	temp = temp / t;
	return (temp);
}
void complex::display(void)
{
	cout << real << " + j"<<imaginary;
}
void list(void)
{
	cout<<"\n\t\t\t\t1. Mod\n\t\t\t\t2. Add\n\t\t\t\t3. Subtract\n\t\t\t\t";
	cout<<"4. Multiply\n\t\t\t\t5. Divide\n\t\t\t\t6. Conjugate\n\t\t\t\t7. Exit\n\t\tPress any other button to reproduce this menu\n";
}
int main()
{
	cout<<"\t\t\t\tHi Everyone!\n\t\tThis program can do following operations on complex numbers\n";
	list();
	while(1)
	{
		char choice;
		complex a,b,c;
		double z;
		cout<<"\n\t\t\tEnter any choice\n\t\t\t\t";
		choice=getchar();
		switch(choice)
		{
			case ('1'):
				a.input();
				z=a.mod();
				cout<<"Mod of ";a.display();cout<<"is "<<z<<endl;
				break;
			case ('2'):
				a.input();
				b.input();
				c=a+b;
				cout<<"Addition of ";a.display();cout<<" and ";b.display();cout<<" is ";c.display();cout<<endl;
				break;
			case ('3'):
				a.input();
				b.input();
				c=a-b;
				cout<<"Subtraction of ";a.display();cout<<" by ";b.display();cout<<" is ";c.display();cout<<endl;
				break;
			case ('4'):
				a.input();
				b.input();
				c=a*b;
				cout<<"Multiplication of ";a.display();cout<<" and ";b.display();cout<<" is ";c.display();cout<<endl;
				break;
			case ('5'):
				a.input();
				b.input();
				c=a/b;
				cout<<"Division of ";a.display();cout<<" by ";b.display();cout<<" is ";c.display();cout<<endl;
				break;
			case ('6'):
				a.input();
				cout<<"Conjugate of ";a.display();a.conjugate();cout<<"is ";a.display();cout<<endl;
				break;
			case('7'):
				exit(007);
			default:
				list();
				break;
		}
	}
	return 0;
}
