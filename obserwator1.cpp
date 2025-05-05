//Observer Pattern

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student{
    private:
        string name;
        long indexID;
    public:
        Student(long indexID, string name);
        void ShowNotyfication(string infromation);
        long getIndexID(){
            return indexID;
        }
    };
    
    Student::Student(long indexID, string name){
        this->indexID = indexID;
        this->name = name; 
    };
    void Student::ShowNotyfication(string infromation){
        cout<<"Student "<<name<<" otrzymal wiadomosc: "<<infromation<<endl;
    };


class USOS{
    private:
        vector <Student*> StudentList;

    public:
        void addStudent(Student* student){
        StudentList.push_back(student);
    };

    void sendMessage(string message){
    
        for(Student* jedenStudent:StudentList)
            jedenStudent->ShowNotyfication(message);
    };
    ~USOS(){
        for(Student* jedenStudent:StudentList){
        cout<<"Student "<<jedenStudent->getIndexID()<<" skasowany z pamieci."<<endl;
        delete jedenStudent;
        }

    }
};


int main(int argc, char const *argv[])
{
    USOS* usos = new USOS;

    usos->addStudent(new Student(1,"Alicja"));
    usos->addStudent(new Student(2,"Roman"));

    usos->sendMessage("Witaj na kolejnym semetrze");

    delete usos;

    return 0;
}
