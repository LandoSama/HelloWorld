#include <iostream>
#include "vektor2.hpp"

using namespace std;

void PrintVec (std::vector<double> v){
	std::vector<double> v;
	for (int i=0; i<v.size();i++){
		cout << v[i] << endl;
	}
}


void testplus()
{
	std::vector<float>	v = {1.0, 2.0, 3.0};
	vektor2<float>		x(v), y(v), z;
	cout << "test5" << endl;
	z = x + y;
	//cout << "z = " << z << endl;
	cout << "end test5" << endl;
}

void testScalarMultip(){
	std::vector<double> v = {3.5,4.5,5.5};
	double	a = 2;
	vektor2<double>	x(v);
	vektor2<double> z;
	
	cout << "testing scalar multiplication" << endl;
	z = a * x;
	PrintVec(v);
	//cout << "x = " << x << endl;
	//cout << "z = " << z << endl;
	cout << "end test" << endl; 
}

int main(int argc, char *argv[])
{
	int 		rc;

	cout << "main start" << endl;

	testplus();

	return(0);
}
