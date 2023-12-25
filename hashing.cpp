#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Student{
    public:
        string name;
        int reg_no;
        Student(string name, int reg_no){
            this->name = name;
            this->reg_no = reg_no;
        }
};
class Hashtable{
    public:
        vector< list<Student> >htable;
        int no_elem;
        int size;
        // constructor
        Hashtable(int s){
            htable.resize(s); // givieng the table some size
            size = s;
            no_elem = 0;
        }
        // hash function
        int hashvalue(Student s){
            return (s.reg_no % size); // division function --> collision addressed bt separate chaining
        }
        // adding a value to the hashtable
        void addStudent(Student s){
            int index = hashvalue(s);
            htable[index].push_back(s);
            cout << "Student " << s.reg_no << " added to the table" << endl;
            no_elem++;
            if(((float)no_elem/size) > 0.75)
                rehashing();
        }
        // deleting a value from the hashtable
        void deleteStudent(Student s){
            int index = hashvalue(s); // student, if present, must be at this position

            // checking if the student is found at the position
            list <Student> :: iterator it;
            for(it = htable[index].begin(); it != htable[index].end(); ++it){
                if(it->reg_no == s.reg_no)
                     break;
            }

            // if the student was found
            if(it != htable[index].end()){
                htable[index].erase(it);
                cout << "Student " << s.reg_no << " has been deleted from the table" << endl;
            }
            else{
                cout << "Student " << s.reg_no << " does not exist in the table" << endl;
            }
        }
        // updating a student
        void updateStudent(Student s){
            int index = hashvalue(s); // student, if present, must be at this position

            // checking if the student is found at the position
            list <Student> :: iterator it;
            for(it = htable[index].begin(); it != htable[index].end(); ++it){
                if(it->reg_no == s.reg_no)
                     break;
            }

            // if the student was found
            if(it != htable[index].end()){
                string tname;
                int treg;
                cout << "Enter new name : ";
                cin >> tname;
                cout << "Enter new reg no: ";
                cin >> treg;
                it->name = tname;
                it->reg_no = treg;
                cout << "Data of " << s.reg_no << " is updated " << endl;
            }
            else{
                cout << "Student " << s.reg_no << " does not exist in the table" << endl;
            }
        }
        // function for printing
        void displaying(){
            for(int i = 0; i < htable.size(); i++){
                cout << i << "--> ";
                list <Student> :: iterator it;
                for (it = htable[i].begin(); it != htable[i].end(); ++it){
                    cout << "(" << it->name << ", " << it->reg_no << ") ";
                }
                cout << endl;
            }
        }
        // function for rehashing
        void rehashing(){
            size+=5;
            vector < list<Student> > temp = htable;
            htable.resize(size);

            // copying all the elements back
            for(int i = 0; i < temp.size(); i++){
                htable[i] = temp[i];
            }
        }
};
int main(){
    Hashtable htable(5);
    Student s1("abc", 1);
    Student s2("abc", 11);
    Student s3("abc", 2);
    Student s4("abc", 12);
    Student s5("abc", 22);
    Student s6("abc", 3);
    Student s7("abc", 4);
    Student s8("abc", 14);
    Student s9("abc", 25);

    htable.addStudent(s1);
    htable.addStudent(s2);
    htable.addStudent(s3);
    htable.addStudent(s4);
    htable.addStudent(s5);
    htable.addStudent(s6);
    htable.addStudent(s7);
    htable.addStudent(s8);
    htable.addStudent(s9);

    htable.displaying();

    return 0;
}