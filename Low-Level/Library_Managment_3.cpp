#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Design a library management system for issuing books to students and tracking inventory.

/*
    Assumptions I Made:
    I need a Librarian  - Librarian has master access 
                        - They can remove and add books
                        - Take out books from a students system

    I need Students - They Take out and return books
                    - need a list of books theyve taken out
                    - need a list of when they took out and returned books 
                    - need an indicator if book is late
                    - Student needs name and ID



    Books in a library have a serial barcode
    can have multiple of the same book 
    Books have a Title
    Books have a Author

    Need to add and remove books (damages, lost, newly purchased books)

*/

class Books{
    public:
    int takenout; // when the book was lent
    int returndate; // when the book is late
    bool taken = false; // 
    string title;
    string author;
    string serial_code;
    Books(string t, string a, string s){ // adding books
        title = t;
        author = a;
        serial_code = s;
    };
};

// i dont have to assign here i can assume?
class Student{
    public:
    string Name;
    string Student_ID;
    bool tardiness = false;
    unordered_map<string, Books> LibraryBooks; // title and books
    
    private:
    Student(string i, string n){
        Name = n;
        Student_ID = i;
    }
    friend class Librarian;
    friend class library;
    




};

class library{ // will act like the librarian since admin should also be able to access this
private:

unordered_map<string, Student> Students_books; // system of students ID and then Student 

unordered_map<string, Books> Library_Collection; // keeps all the books they have, this book ID and then book

void AddStudents(string ID, string name){

    if(Students_books.count(ID) <= 0){
        Student newStudent = Student(ID, name); // now created new student
        Students_books[ID] = newStudent;
    }
    else{
        cout << "Sorry, the student "<< Students_books[ID].Name << " is already in the system";
    }
}

void addBook(string t, string a, string s){
    Library_Collection[s] = Books(t,a,s);
}


friend class Librarian;

public:


void checkLates(string ID, int cd){ // ID is student ID and cd is Current Date
    if(Students_books.count(ID) > 0){
        if(!Students_books[ID].tardiness){ // false means they are not tarty but will need to check the books
            
            for (const auto& pair : Students_books[ID].LibraryBooks) {
             
                if(pair.second.returndate < cd){
                    Students_books[ID].tardiness = true;
                    break;
                }
            }
            
        }
    }
    else{
        cout << "Sorry your ID does not exist and they will add you into the system";
    }

}


void TakeoutBook(string ID, int cd,string t, string a, string s){ // student Id, Current DAte, Book Title, Book Author, and Book Serial Code
    checkLates( ID, cd);
     if(!Students_books[ID].tardiness){
        if(Library_Collection.count(s) <= 0){
            cout << "Sorry the Book is not in our system I will add it and let you take it out";
            addBook(t,a,s);
        }
    
        Library_Collection[s].taken = true;
        Library_Collection[s].takenout = cd;
        Library_Collection[s].returndate = cd + 20;
        Students_books[ID].LibraryBooks[t] = Library_Collection[s];
        cout << "Enjoy your books";

     }
     else{
        cout << "Sorry the system indicates you have overdue books";
     }

}

void ReturnBook(string ID, string serial_code, int cd) {
        if (Students_books.count(ID) == 0) {
            cout << "Student ID " << ID << " does not exist in the system." << endl;
            return;
        }

        if (Students_books[ID].LibraryBooks.count(serial_code) == 0) {
            cout << "The student has not borrowed this book." << endl;
            return;
        }

        // Check if the book is being returned late
        if (Students_books[ID].LibraryBooks[serial_code].returndate < cd) {
            checkLates(ID, cd);
            cout << "Book returned late and students ability to not take future books is " << Students_books[ID].tardiness << endl;
        }

        Library_Collection[serial_code].taken = false;
        Students_books[ID].LibraryBooks.erase(serial_code);

    }



};

class Librarian{
    string name;

};
