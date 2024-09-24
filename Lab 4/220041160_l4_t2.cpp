#include<iostream>

using namespace std;

class Flight{

    private:
        int flightNumber;
        string destination;
        float distance;
        float maxFuelCapacity;

        double CalFuel(){
           if(distance<=1000)
                return 500;
            else if(distance>1000 && distance<=2000)
                return 1100;
            else if(distance>2000)
                return 2200;
            else
                cout<<"Wrong input"<<endl;


                }

        public:
            void FeedInfo(){
               cout<<"Enter flight number : ";
               cin>>flightNumber;
               cin.ignore();

               cout<<"Enter Destination : ";
               cin>>destination;

               cout<<"Distance : ";
               cin>>distance;

               cout<<"Enter Max Fuel Capacity : ";
               cin>>maxFuelCapacity;

            }

            void ShowInfo(){
                cout<<"Flight number : "<<flightNumber<<endl;
                cout<<"Destination : "<<destination<<endl;
                cout<<"Max Fuel Capacity : "<<maxFuelCapacity<<endl;

                if(maxFuelCapacity>=CalFuel())
                    cout<<"Fuel capacity is fit for this flight distance."<<endl;

                else
                    cout<<"Not sufficient Fuel Capacity for this flight"<<endl;
                    }
                    };





int main(){
    Flight f1;
    f1.FeedInfo();
    f1.ShowInfo();
    }
