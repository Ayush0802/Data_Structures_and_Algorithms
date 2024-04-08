/////////////////////////////////////////////////////////          ENCAPSULATION          /////////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class Student {

//     private:
//         string name;
//         int age;
//         int height;

//     public:
//     int getAge() {
//         return this->age;
//     }
// };

// int main() {

//     Student first;

//     cout << "Sab sahi chalra hai" << endl;

//     return 0;
// }


//////////////////////////////////////////////////////////          INHERITANCE          ////////////////////////////////////////////////////////// 


/*
    SUPER CLASS       MODE OF INHERITANCE       CHILD CLASS
    public            public                    public
    public            protected                 protected
    public            private                   private
    protected         public                    protected
    protected         protected                 protected
    protected         private                   private
    private           public                    NA
    private           protected                 NA
    private           private                   NA
*/

// #include<iostream>
// using namespace std;

// class Human {

//     protected:
//     int height;

//     public: 
//     int weight;

//     private:
//     int age;

//     public:
//     int getAge() {
//         return this->age;
//     }

//     void setWeight(int w) {
//         this->weight = w;

//     }

// };

// class Male: protected Human {

//     public:
//     string color;

//     void sleep() {
//         cout << "Male Sleeping" << endl;
//     }

//     int getHeight() {
//         return this->height;
//     }

//     int getWeight() {
//         return this->weight;
//     }

//     int getAge() {
//         return this->age;
//     }

// };

// int main() {

//     Male m1;
//     cout << m1.height << endl;
//     cout << m1.weight << endl;
//     cout << m1.age << endl;

//     return 0;
// }


//////////////////////////////////////////////////////          SINGLE INHERITANCE          //////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class Animal {

//     public:
//     int age;
//     int weight;

//     public:
//     void speak() {
//         cout << "Speaking " << endl;
//     }
// };

// class Dog: public Animal {

// };

// int main() {

//     Dog d;
//     d.speak();
//     cout << d.age << endl;

//     return 0;
// }


////////////////////////////////////////////////////          MULTI-LEVEL INHERITANCE          ////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class Animal {

//     public:
//     int age;
//     int weight;

//     public:
//     void speak() {
//         cout << "Speaking " << endl;
//     }
// };

// class Dog: public Animal {

// };

// class GermanShepherd: public Dog {

// };

// int main() {

//     GermanShepherd g;
//     g.speak();

//     return 0;
// }


/////////////////////////////////////////////////////          MULTIPLE INHERITANCE          /////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class Animal {

//     public:
//     int age;
//     int weight;

//     public:
//     void bark() {
//         cout << "Barking " << endl;
//     }
// };

// class Human {
//     public:
//     string color;

//     public:
//     void speak() {
//         cout << "Speaking " << endl;
//     }
// };

// //Multiple Inheritance
// class Hybrid: public Animal, public Human {

// };


// int main() {

//     Hybrid obj1;
//     obj1.speak();
//     obj1.bark();

//     return 0;
// }


///////////////////////////////////////////////////          HIERARCHICAL INHERITANCE          ///////////////////////////////////////////////////


// #include<iostream>
// using namespace std;
// //Hierarchical Inheritance
// class A {

//     public:
//     void func1() {
//         cout << "Inside Funcion 1" << endl;
//     }

// };

// class B: public A {
//     public:
//     void func2() {
//         cout << "Inside Funcion 2" << endl;
//     }
// };

// class C: public A {
//     public:
//     void func3() {
//         cout << "Inside Funcion 3" << endl;
//     }
// };

// int main() {

//     A object1;
//     object1.func1();

//     B object2;
//     object2.func1();
//     object2.func2();

//     C object3;
//     object3.func1();
//     object3.func3();

//     return 0;
// }


/////////////////////////////////////////////////////          INHERITANCE AMBIGUITY          /////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class A {
//     public:

//     void func() {
//         cout << " I am A" << endl;
//     }
// };

// class B {
//     public:

//     void func() {
//         cout << " I am B" << endl;
//     }
// };

// class C: public A, public B {


// };

// int main() {

//     C obj;
//     // obj.func();

//     obj.A::func() ;
//     obj.B::func();

//     return 0;
// }


/////////////////////////////////////////////////////////          POLYMORPHISM          /////////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;

// class A {

//     public:
//     void sayHello() {
//         cout << "Hello Love Babbar" << endl;
//     }
    
//     int sayHello(char name) {
//         cout << "Hello Love Babbar" << endl;
//         return 1;
//     }

//     void sayHello(string name) {
//         cout << "Hello " << name  << endl;
//     }

// };

// class B {
//     public:
//     int a;
//     int b;

//     public: 
//     int add() {
//         return a+b;
//     }

//     void operator+ (B &obj) {
// /*        int value1 = this -> a;
//         int value2 = obj.a;
//         cout << "output " << value2 - value1 << endl; 
//         */
//        cout << "Hello Babbar" << endl;
//     }

//     void operator() () {
//         cout << "main Bracket hu " << this->a << endl;
//     }

// };

// class Animal {
    
//     public:
//     void speak() {
//         cout << "Speaking "<< endl;
//     }

// };

// class Dog: public Animal {

//     public:
//     void speak() {
//         cout << "Barking " << endl;
//     }

// };

// int main() {

//     Dog obj;
//     obj.speak();

//     B obj1, obj2;
//     obj1.a = 4;
//     obj2.a = 7;
//     obj1 + obj2;
//     obj1();

//     A object;
//     object.sayHello();
    
//     return 0;
// }