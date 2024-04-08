#include<iostream>
#include<cstring>
using namespace std;

class Hero {
    
    //properties
    private:      //only works within the class if directly called
    int health;

    public:       //works everywhere 
    char *name;
    char level;
    static int timeToComplete;

    //default constructor called if no parameterised constructor is called
    Hero() 
    {
        cout << "Simple constructor called" << endl;
    }

    //Paramerterised Constructor
    Hero(int health) 
    {
        this -> health = health;
    }

    Hero(int health, char level) 
    {
        this -> level = level;
        this -> health = health;
    }

    //Copy Constructor
    //Shallow Copy
    // Hero(Hero& temp)
    // {
    //     cout<<"Shallow Copy Constructor called"<<endl;
    //     this->name = temp.name;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    //Deep Copy
    Hero(Hero& temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"Deep Copy Constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }


    //print function
    void print()
    {
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl;
    }

    //setter & getter
    int getHealth() 
    {
        return health;
    }

    char getLevel() 
    {
        return level;
    }

    void setHealth(int h) 
    {
        health = h;
    }

    void setLevel(char ch) 
    {
        level = ch;
    }

    void setName(char name[]) {
        this->name = name;
    }

    static int random() {           //static function only allows static member
        return timeToComplete ;
    }

    //Destructor
    ~Hero() 
    {   
        cout << "Destructor called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main() {

    //Static Keyword
    cout << Hero::timeToComplete << endl;
    cout << Hero::random() << endl;
    // Hero a1;
    // cout << a1.timeToComplete << endl;
    // Hero b1;
    // b1.timeToComplete = 10 ;
    // cout  << a1.timeToComplete << endl;
    // cout << b1.timeToComplete << endl;
    cout<<endl<<endl;




    //creation of Object
    Hero ramesh;   
    cout << "Size of Ramesh is " << sizeof(ramesh) << endl;

    //use setter
    ramesh.setHealth(70);
    char hame[6] = "Ayush";
    ramesh.setName(hame);
    //use getter
    cout << "health is: " << ramesh.getHealth() << endl; 
    cout << "name is: " << ramesh.name << endl; 
    
    ramesh.level = 'A';
    cout << "Level is: " << ramesh.level << endl; 
    cout<<endl<<endl;





    //static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is  " << a.level << endl;
    cout << "health is " << a.getHealth() << endl;

    //dynamicallly
    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout << "level is  " << (*b).level << endl;
    cout << "health is " << (*b).getHealth() << endl;
    (*b).setLevel('B');
    (*b).setHealth(80);
    cout << "level is  " << b->level << endl;
    cout << "health is " << b->getHealth() << endl;
    cout<<endl<<endl;
    




    //calling parameterized Constructor
    //statically
    Hero r(10);
    char n1[6] = "Ayush";
    r.setName(n1);
    cout << "Address of r " << &r << endl;
    r.print();

    //dynamically
    Hero *h =  new Hero(22, 'B');
    char n2[6] = "Ayush";
    h->setName(n2);
    h->print();
    cout<<endl<<endl;





    //copy Constructor
    Hero *R = new Hero(50,'C');
    R->print();

    Hero S(*R);      
    S.print();
    cout<<endl<<endl;
    delete R;



   
    //Shallow and Deep Copy
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[6] = "Ayush";
    hero1.setName(name);
    hero1.print();

    Hero hero2(hero1);

    hero1.name[0] = 'a';
    hero1.print();
    hero2.print();
    cout<<endl<<endl;





    //Copy Assignment Operator
    Hero heroa(10,'C');
    Hero herob(45,'X');
    char name2[7] = "Babbar";
    herob.setName(name2);
    heroa.print();
    herob.print();
    heroa = herob;
    heroa.print();
    herob.print();
    cout<<endl<<endl;
 
    return 0;
}