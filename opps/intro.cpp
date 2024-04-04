#include<bits/stdc++.h>
using namespace std;
class hero{
    //Properties
    private:
    int health;
    public:
    char *name;
    char level;
    static int timeTocomplete;

    hero(){
        cout<<"Simple Constructor  called "<<endl;
        name=new char[100];

    }

    //Paramerterised Constructor
    hero(int health){
        cout<<"this->"<<this<<endl;
        this->health=health;
    }
    hero(int health,int level){
        this->level=level;
        this->health=health;
    }
    //Copy Constructor
    hero (hero& temp){
        char *ch=new char [strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        cout<<"Copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
    void print(){
        cout<<endl;
        cout<<"[Name: "<<name<<" ,";
        cout<<"Health "<<this->health<<" ,";
        cout<<"Level "<<this->level<<"]"<<endl;
        cout<<endl;
        // cout<<level<<endl;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }

    //Destructor
    ~hero(){
        cout<<"Destructor called"<<endl;
    }

};

int hero::timeTocomplete=5;

int main(){
    cout<<hero::timeTocomplete<<endl;
    

    //statically allocation
    //here destructor automatically called
   // hero a;
    //dynamic alocation 
    //here destructor manually called
    // hero *b=new hero();
    // delete b;

    //  hero hero1;
    // hero1.sethealth(12);
    // hero1.setlevel('D');
    // char name[7]="Deepak";
    // hero1.setname(name);

    // hero1.print();

    //use default copy constructor
    // hero hero2(hero1);
    // // hero2.print();
    // //Sawllo copy
    // hero1.name[0]='P';
    // hero1.print();
    // hero2.print();
    // hero1=hero2;
    // hero1.print();
    // hero2.print();
    
    




    // hero suresh(40 , 'C');
    // suresh.print();
    // hero vivek(suresh);
    // vivek.print();




    // object created statically
    // hero vishal(10);
    // vishal.print();
    // // cout<<"Address of Vishal "<<&vishal<<endl;
    // //dynamically 
    // hero *h=new hero(11);
    // h->print();
    // hero temp(22,'C');
    // temp.print();

    
    //static allocation 
    // hero a;
    // a.sethealth(70);
    // a.setlevel('A');
    // cout<<"health is "<<a.gethealth()<<endl;
    // cout<<"level is "<<a.level<<endl;

    // //dynamic allocation
    // hero *b=new hero;
    // b->sethealth(70);
    // b->setlevel('A');
    // //first method to access *b
    // cout<<"health is "<<(*b).gethealth()<<endl;
    // cout<<"level is "<<(*b).level<<endl;
    // //seccond method to access *b
    // cout<<"health is "<<b->gethealth()<<endl;
    // cout<<"level is "<<b->level<<endl;


    // //Creation of Objects
    // hero vishal;
    // cout<<"Vishal health is "<<vishal.gethealth()<<endl;
    // vishal.sethealth(70);   
    // // vishal.health=70;
    // vishal.level='A';
    // cout<<"health is: "<<vishal.gethealth()<<endl;
    // cout<<"level is: "<<vishal.level<<endl;
    // cout<<"size:"<<sizeof(vishal)<<endl;


    return 0;
}