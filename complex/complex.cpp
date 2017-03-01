#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class complex
{
	float x;
	float y;
	public:
		complex(float real=0, float imag=0)
		{
			x=real;
			y=imag;
		}
		float mod(void)
		{
			return sqrt(x*x + y*y);
		}
		void conjugate(void)
		{
			y = -y;
		}
		complex operator+(complex);
		complex operator-(complex);
		friend complex operator*(complex,complex);
		friend complex operator/(complex,complex);
		friend complex operator/(complex,float);
		void display (void);
		void input(void);
};

void complex::input(void)
{
	cout<<"\nEnter real part : ";
	cin>>x;
	cout<<"\nEnter imag part : ";
	cin>>y;
}
complex complex::operator+(complex c)
{
	complex temp;
	temp.x = x+ c.x;
	temp.y = y + c.y;
	return (temp);
}
complex complex::operator-(complex c)
{
	complex temp;
	temp.x = (*this).x- c.x;
	temp.y = y - c.y;
	return (temp);
}
complex operator*(complex d,complex c)
{
	complex temp;
	temp.x = d.x* c.x-d.y*c.y;
	temp.y = d.y*c.x + d.x * c.y ;
	return (temp);
}
complex operator/(complex c,float d)
{
	complex temp;
	temp.x = c.x / d;
	temp.y = c.y / d; 
	return (temp);
}
complex operator/(complex c,complex d)
{
	complex temp;
	float t;
	t = d.mod();
	d.conjugate();
	temp = c * d;
	t = pow(t,2);
	temp = temp / t;
	return (temp);
}
void complex::display(void)
{
	cout << x << " + j"<<y;
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
		float z;
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
