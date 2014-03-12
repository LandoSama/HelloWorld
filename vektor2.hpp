#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class vektor2
{
	private:
		int i;
		std::vector<T> x;
	public:
		vektor2();
		vektor2(const std::vector<T> &v);
		~vektor2();
		vektor2<T>  operator-(const vektor2<T> &o);
		vektor2<T>	operator+(const vektor2<T> &o);
		vektor2<T>	operator*(const vektor2<T> &o);
		vektor2<T>	operator*(const T &a);
		bool 	isValid() const;
};

template<typename T>
vektor2<T>::vektor2(){
	std::cout << "Construct vektor2 from vector<T>" << std::endl;
	return;
}

template<typename T>
vektor2<T>::vektor2(const std::vector<T> &o){
	std::cout << "Construct vektor2 from vector<T>" << std::endl;
	x = o;
	return;
}

template<typename T>
vektor2<T>::~vektor2(){
	std::cout << "Destruct vektor2" << endl;
	return;
}

template<typename T>
vektor2<T>   vektor2<T>::operator+(const vektor2<T> &o){
	vektor2<T> r;
	std::vector<T> y;
	
	y.resize(x.size());
	for(i=0; i<x.size(); i++){
		y[i] = x[i] + o.x[i];
	}
	r = y;
	return(r);
}

template <typename T>
vektor2<T>	vektor2<T>::operator-(const vektor2<T> &o){
	vektor2<T> r;// does this declare a new vektor2?
	//std::vektor2<T> y;// what is the std:: part for?
	
	r.x.resize(x.size());//what is resize doing...?
	for(i = 0; i < x.size(); i++){ // what is auto for?
		r.x[i] = x[i] - o.x[i];
	}
	return(r);
}

template <typename T>
vektor2<T> vektor2<T>::operator*(const vektor2<T> &o){
	vektor2<T>	r;
	T	p = 0;
	if(x.size() != o.x.size()){
		puts("Error x's size not equal to b's size");
		return -1;
	}
	for(i = 0; i <= x.size(); i++){
		p += (x[i])*(o.x[i]);
	}
	r = {p};
	return(r);
}

template <typename T>
vektor2<T>  vektor2<T>::operator*(const T &a){
	vektor2<T> r;
	
	r.x.resize(x.size());
	for(i = 0; i < x.size(); i++){
		r.x[i] = x[i] * a;
	}
	return(r);
}

template<typename T>
bool vektor2<T>::isValid() const
{
	if(x.size() == 0) return false;
	return(true);
}





