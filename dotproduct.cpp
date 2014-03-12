#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> Vec;


int main(){
	Vec a, b;
	double atmp, btmp;
	int i;
	
	while(1){
		cout << "enter vector a: ";
		cin >> atmp;
		if(cin.fail()){
			if(cin.eof()){
				break;
			}
			cerr << "Numeric format error\n.";
			return 1; 
		}
		a.push_back(atmp);
	}
	cin.clear();
	cout << "vector a has " << a.size() << " values..\n";
	
	for(i = 0; i < a.size(); i++){
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	
	while(1){
		cout << "enter vector b: ";
		cin >> btmp;
		if(cin.fail()){
			if(cin.eof())break;
			cerr << "Numeric format error\n";
			return 1;
		}
		b.push_back(btmp);
	}
	
	cout << "vector b has " << b.size() << " values..\n";
	
	for(i = 0; i < b.size(); i++){
		cout << "b[" << i << "] = " << b[i] << "\n";
	}
	
	return 0;
}
