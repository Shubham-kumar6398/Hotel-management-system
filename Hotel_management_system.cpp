#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define size 5
class Customer
{
    public:
    string name;
    string address;
    string Id_proof;
    string phone;
    string checkin;
    string checkout;
    float payment;
};
class Room : public Customer
{
    public:
    Customer eco[size];
    Customer preeco[size];
    Customer lux[size];
    int i = 0,j=0,k=0;
    int rent1 = 2000;
    int rent2 = 4000;
    int rent3 = 10000;
};
class Hotel : public Room
{
    public:
    void checkin();
    void checkout(int a);
    void available()
    {
        if(i<size)
        {
            cout<<"Room Type = Economic , Availabel room = "<<size - i<<endl;
        }
        if(j<size)
        {
            cout<<"Room Type = Premium Economic , Availabel room = "<<size - j<<endl;
        }
        if(k<size)
        {
            cout<<"Room Type = Luxury , Availabel room = "<<size - k<<endl;
        }
    }
    void report();
    void search(string name);
};
int reserve(int &x,Customer arr[])
{
    if(x>=size)
    {
        cout<<"Room not available"<<endl;
        return -1;
    }
    else
    {
        string y;
        Room room;
        cout<<"Enter the name"<<endl;getline(cin,y);
        getline(cin,arr[x].name);
        cout<<"\nEnter the address"<<endl;
        getline(cin,arr[x].address);
        cout<<"\nEnter the Id_proof like aadhar no."<<endl;
        getline(cin,arr[x].Id_proof);
        cout<<"\nEnter the phone no."<<endl;
        getline(cin,arr[x].phone);
        cout<<"\nEnter the check-in date"<<endl;
        getline(cin,arr[x].checkin);
        cout<<"\nEnter the check-out date"<<endl;
        getline(cin,arr[x].checkout);
        cout<<"\nEnter the advance payment if any"<<endl;
        cin>>arr[x].payment;
        cout<<"Reservation is confirmed"<<endl;
        x++;
        return 0;
    }
}
void Hotel :: checkin()
{
    
    system("cls");
    cout<<"\n1. Economy Room";
    cout<<"\n2. Premium Economy Rooms";
    cout<<"\n3. Luxury Customer\n";
    cout<<"Enter your choose : ";
    int a;
    cin>>a;
    if(a == 1)
    {
        system("cls");
        cout<<"Rent is Rs."<<rent1<<" for 24 hrs\n";
        a = reserve(i,eco);
        if(a!=-1)
        cout<<"Your room no. is "<<(100+i)<<endl;
    }
    else if(a == 2)
    {
        system("cls");
        cout<<"Rent is Rs."<<rent2<<" for 24 hrs\n";
        a = reserve(j,preeco);
        if(a!=-1)
        cout<<"Your room no. is "<<(200+j)<<endl;
    }
    else if(a == 3)
    {    
        system("cls");
        cout<<"Rent is Rs."<<rent3<<" for 24 hrs\n";
        a = reserve(k,lux);
        if(a!=-1)
        cout<<"Your room no. is "<<(300+k)<<endl;
    }
    else
    {
        return;
    }
    getch();
}
void generate(Customer arr[],int a,int rent)
{
    int x = 0;
    cout<<"Enter the no of days of stay"<<endl;
    cin>>x;
    x = x*rent;
    cout<<"**********************BILL**********************"<<endl<<endl;;
    cout<<"THANK YOU FOR VISITING YOUR HOTEL "<<endl;
    cout<<"Name = "<<arr[a-1].name<<endl;
    cout<<"Total rent = "<<x<<endl;
    cout<<"Advance payment = "<<arr[a-1].payment<<endl;
    cout<<"Due payment = "<<x-arr[a-1].payment<<endl<<endl;
    cout<<"**********************Please Revisit Us**********************"<<endl;
}
void Hotel :: checkout(int a)
{
    int b = 0;
    if(a>100&&a<200)
    {
        a = a-100;
        if(a>i)
        {
            b++;
        }
        else
        {
            generate(eco,a,rent1);
            i--;
        }
    }
    else if(a>200&&a<300)
    {
        a = a -200;
        if(a>j)
        {
            b++;
        }
        else
        {
            generate(preeco,a,rent2);
            j--;
        }
    }
    else{
        a =a - 300;
        if(a>k)
        {
            b++;
        }
        else
        {
            generate(lux,a,rent3);
            k--;
        }
    }
    if(b>0)
    {
        cout<<"Invalid Room No."<<endl;
    }
    getch();
}
void Hotel :: search(string name)
{
    int a = 0;
    for(int x = 0;x<i;x++)
    {
        if(eco[x].name == name)
        {
            a++;
            cout<<"coustomer name = "<<eco[x].name<<", Room No. = "<<x+101<<endl;;
        }
    }
    for(int x = 0;x<j;x++)
    {
        if(preeco[x].name == name)
        {
            a++;
            cout<<"coustomer name = "<<preeco[x].name<<", Room No. = "<<x+201<<endl;
        }
    }
    for(int x = 0;x<k;x++)
    {
        if(lux[x].name == name)
        {
            a++;
            cout<<"coustomer name = "<<lux[x].name<<", Room No. = "<<x+301<<endl;
        }
    }
    if(a==0)
    {
        cout<<"No, Customer found with this name"<<endl;
    }
}
int main(){
    Hotel hotel;
    int a;
    string str;
    do
    {
        system("cls");
        cout<<"HOTEL MANAGEMENT SYSTEM"<<endl;
        cout<<"\n1. Check-In Room";
        cout<<"\n2. Check-Out Room";
        cout<<"\n3. Search Customer";
        cout<<"\n4. Available Rooms";
        cout<<"\n5. Exit";
        cout<<"\n\nEnter Option: ";
        cin>>a;
        switch(a)
        {
            case 1: hotel.checkin();
                    break;

            case 2: if(hotel.i==0&&hotel.j==0&&hotel.k==0)
                    {
                        cout<<"No Guest is in the Hotel";
                        getch();
                    }
                    else
                    {
                        int a;
                        cout<<"Enter room no."<<endl;
                        cin>>a;
                        hotel.checkout(a);
                    }
                    break;
            case 3: cout<<"Enter the name of customer\n";
                    getline(cin,str);
                    getline(cin,str);
                    hotel.search(str);
                    getch();
                    break;
            case 4: hotel.available();
                    getch();
                    break;
        }
    }while(a!=5);
    return 0;
}
