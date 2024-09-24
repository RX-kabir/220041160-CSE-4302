#include<iostream>


using namespace std;


class Calculator{

private:
    int current;


public:
    Calculator(int value =0) : current(value){}

    int getcurrent() const{
        return current;
        }

    void add(int value){
        current+=value;
        }

    void subtract(int value){
        current-=value;
        }

    void multiply(int value){
        current*=value;
        }
    int divide(int value){
        if(value==0){
            cout<<"Not possible"<<endl;;
            }
        else{
        int remainder=current%value;
            current/=value;
            return remainder;

            }
    }
    void clear(){
        current=0;
        }


    void display()const{
        cout<<"Calculator Display : "<<current<<endl;
        }


    ~Calculator(){
        cout<<"Destructor of the Calculator object is called."<<endl;
        }
        };


int main(){
    Calculator c1;
    c1.add(10);
    c1.subtract(20);
    c1.multiply(-2);
    c1.display();
    }
