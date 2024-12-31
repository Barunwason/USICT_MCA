#include<iostream>
using namespace std;
class complex{
    private:
    int real;
    int imag;
    public:
    complex(int r,int i){
        real=r;
        imag=i;
    }
    void print(){
        cout<<real<<"+i"<<imag<<endl;
    }
    friend complex operator+(complex const& c1,complex const& c2);
};
complex operator+(complex const& c1,complex const& c2){
    return complex(c1.real+c2.real,c2.imag+c1.imag);
}
int main(){
    complex c1(1,4);
    complex c2(4,3);
    c1.print();
    c2.print();
    complex c3 =c1+c2;
    c3.print();
}