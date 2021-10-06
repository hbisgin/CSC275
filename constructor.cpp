#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Fruit{
    public:
        Fruit():w(0), price(0){count++;}
        Fruit(float w):w(w), price(0){Explicitcount++; cout<<"weight entered: "<<w<<endl;}
        float getWeight(){return w;}
        int static count;
        int static Explicitcount;
        float & operator[](int i){if (i==0) return w; else return price;}
        friend ostream &operator<<(ostream &obj, Fruit &f);
        friend istream &operator>>(istream &obj, Fruit &f);
    private:
        float w, price;

};

int Fruit::count = 0;
int Fruit::Explicitcount= 0;

ostream & operator<<(ostream &obj, Fruit &fruit)
{
    //ostream obj;
    obj<<fruit.w<<" "<<fruit.price<<endl;
    return obj;
}

istream & operator>>(istream &obj, Fruit &fruit)
{
    //ostream obj;
    float a, b;
    obj>>fruit.w;
    obj>>b;
    fruit.price=b;
    return obj;
}

const Fruit operator+ (Fruit f1, Fruit f2);
int main()
{
    Fruit f, f2(2), f3;
    cout<<f.getWeight()<<endl;
    cout<<f2.getWeight()<<endl;
    f = f + f2;
    cout<<f.getWeight()<<endl;
//    (f+f2) = f3; //left hand side is const, you can't change
    Fruit f4 = f + 2.5;
    cout<<f4.getWeight()<<endl;
    cout<<"constructor called this many times: "<<Fruit::count<<endl;
    cout<<"explicit constructor called this many times: "<<Fruit::Explicitcount<<endl;
    cout<<f4<<endl;
    cin>>f4;
    cout<<f4<<endl;
    f4[0]=11;
    cout<<f4<<endl;

}

const Fruit operator + (Fruit f1, Fruit f2)
{
   float weight= f1.getWeight() + f2.getWeight();
   return Fruit(weight);
}
