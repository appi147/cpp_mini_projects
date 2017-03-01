#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class complex
{
	double real;
	double imaginary;
	public:
		complex (double r=0, double i=0)
		{
			real=r;
			imaginary=i;
		}
		double mod (void)
		{
			return sqrt((real*real) + (imaginary*imaginary));
		}
		void conjugate(void)
		{
			imaginary = -imaginary;
		}
		complex operator + (complex);
		complex operator - (complex);
		friend ostream& operator<<(ostream& os, const complex& c);
		friend istream& operator>>(istream& os, const complex& c); 
		friend complex operator * (complex,complex);
		friend complex operator / (complex,complex);
		friend complex operator / (complex,double);
};
/*
void complex::input(void)
{
	cout<<"\nEnter real part : ";
	cin>>real;
	cout<<"\nEnter imag part : ";
	cin>>imaginary;
}
void complex::display(void)
{
	cout << real << " +j"<<imaginary;
}
*/
ostream& operator<<(ostream& os, const complex& c)  
{  
    os<<c.real<<"+j"<<c.imaginary;
    return os; 
}  
istream& operator>>(istream& is, const complex& c)  
{  
    is>>c.real>>c.imaginary; 
    return is; 
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
	temp.imaginary = this->imaginary - c.imaginary;
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

void list(void)
{
	cout<<"\n\t\t\t\t1. Mod\n\t\t\t\t2. Add\n\t\t\t\t3. Subtract\n\t\t\t\t";
	cout<<"4. Multiply\n\t\t\t\t5. Divide\n\t\t\t\t6. Conjugate\n\t\t\t\t7. Exit\n\t\tPress any other button to reproduce this menu\n";
}
int main()
{
	cout<<"\t\t\t\tHi Everyone!\n\t\tThis program can do following operations on complex numbers\n";
	list();
	while(true)
	{
		char choice;
		complex a,b,c;
		double z;
		cout<<"\n\t\t\tEnter any choice\n\t\t\t\t";
		choice=getchar();
		switch(choice)
		{
			case ('1'):
				cin>>a;
				z=a.mod();
				cout<<"Mod of "<<a<<"is "<<z<<endl;
				break;
			case ('2'):
				cin>>a>>b;
				c=a+b;
				cout<<"Addition of "<<a<<" and "<<b<<" is "<<c<<endl;
				break;
			case ('3'):
				cin>>a>>b;
				c=a-b;
				cout<<"Subtraction of "<<a<<" by "<<b<<" is "<<c<<endl;
				break;
			case ('4'):
				cin>>a>>b;
				c=a*b;
				cout<<"Multiplication of "<<a<<" and "<<b<<" is "<<c<<endl;
				break;
			case ('5'):
				cin>>a>>b;
				c=a/b;
				cout<<"Division of "<<a<<" by "<<b<<" is "<<c<<endl;
				break;
			case ('6'):
				cin>>a;
				cout<<"Conjugate of "<<a;a.conjugate();cout<<" is "<<a<<endl;
				break;
			case('7'):
				exit(0);
			default:
				list();
				break;
		}
	}
	return 0;
}
