#include<iostream>


using namespace std;


class Array{
public:
    Array(int size=2){a = new int[size]; length = 0; capacity = size;}
    Array(const Array &aobj);
    Array &operator=(const Array &aobj);
    int & operator[](int index);
    //testing something
    Array * operator+(const Array &rhs);
    
private:
    int *a, length, capacity;

};

void TestCopyConstructor(Array a){ cout<<"I don nothing bu creating ARray copies"<<endl;}

int main()
{

Array array1, array2(4);
array1[0] = 5;
array1[1] =105;
cout<<array1[0]<<endl;

array2[0] = 20;
array2 = array1;
cout<<array2[0]<<endl;
cout<<array2[1]<<endl;

TestCopyConstructor(array1);
TestCopyConstructor(array1);

array1 = array1;
cout<<array1[0]<<endl;

Array *top = array1+array2;
//top = &array1;
cout<<"=============="<<endl;


for(int i=0; i<4; i++)
    cout<<top->operator[](i)<<endl;

}

Array::Array(const Array &aobj)
{
    capacity  = aobj.capacity;
    capacity = aobj.capacity;
    a = new int[capacity];
    for(int i=0; i<length; i++)
        a[i] = aobj.a[i];
    cout<<"copy constructor called you know?"<<endl;

}

int & Array::operator[](int index){
    return a[index];

}

Array & Array::operator=(const Array &aobj)
{
    if (this==&aobj)
       return *this;
    //if(capacity!=aobj.capacity) { delete [] a; a = new int[aobj.capacity]; }
    delete [] a;
    length = aobj.length;
    capacity = aobj.capacity;
    a = new int[capacity];
    for(int i=0; i<capacity; i++)
        a[i] = aobj.a[i];

    return *this;
}

Array * Array::operator+(const Array &rhs)
{
    int c = capacity + rhs.capacity;
    Array *ptr = new Array(c);
    
    for (int i=0;i<length; i++){
        ptr->operator[](i) = a[i];
        ptr->length++;
    }

    for(int i=length; i<length+rhs.length-1; i++) 
    {
        ptr->operator[](i) = rhs.a[i-length];   
        ptr->length++;
    }
    return ptr;
}
