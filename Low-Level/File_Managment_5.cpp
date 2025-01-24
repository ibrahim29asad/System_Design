#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Implement a file system where you can create, read, write, and delete files and folders.

/*
My Assumptions
I can create a file 
I can create folders
File has contents 
I can read File
I can write File 

I can delete and move Files and Folders
*/


class File{

public:
string title; // Unique Identifier
vector<string>contents; // what is placed inside the file 

File(string name){
    title = name;
}


};

class Folder{
public:
string title; // Unique Identifier
unordered_map<string, Folder> sub_folders;
unordered_map<string, File> files; // makes sure that each file is unique 

Folder(string name){
    title = name;
}



};

class FileManagment{


    unordered_map<string, Folder> Current_Folder;
    Folder* Root; 

    FileManagment(){
        Root = &Current_Folder["Root"];
    }

    Folder createFolder(string name){
        return Folder(name);
        
    }

    File createFile(string name){
        File newFile = File(name);
        return newFile;
    }


    void addFolder(string name) {
        Folder newFolder = createFolder(name);
        Root->sub_folders[name] = newFolder;
    }


    vector<string> ReadFiles(string name){
        if(Root->files.count(name) <= 0){
            cout << "file is not here \n";
            vector<string> Read;
            return Read;
        }
        return Root->files[name].contents;
    }

    void reader (string name){
        vector<string> Read = ReadFiles(name);
        for(int i = 0; i < Read.size(); i++){
            cout << Read[i] << "\n";
        }
    }

    void write(string name, string content) {
        
        if(Root->files.count(name) <= 0){
            cout << "file is not here \n";
            return;
        }
        Root->files[name].contents.clear();
        Root->files[name].contents.push_back(content);
    }

    void append(string name, string content) {
        
        if(Root->files.count(name) <= 0){
            cout << "file is not here \n";
            return;
        }   
        Root->files[name].contents.push_back(content);
    
    }



    void addFile(string name) {
        File newFile = createFile(name);
        Root->files[name] = newFile;
    }

    void listFolders(){

        cout << "Files in " << Root->title << ":\n"; // name of the rile
        for (auto& FoldersList : Root->sub_folders) {
            cout << "- " << FoldersList.first << endl;
        }
        
    } 

    void listFiles() {
        cout << "Files in " << Root->title << ":\n";
        for (auto& file : Root->files) {
            cout << "- " << file.first << endl;
        }
    }

    void enterFolder(string folderName) {
        if (Root->sub_folders.find(folderName) != Root->sub_folders.end()) {
            Root = &Root->sub_folders[folderName];
            cout << "Entered folder: " << folderName << endl;
        } else {
            cout << "Folder is not Availbe!" << endl;
        }
    }

  
};

int main(){
    cout << "Hello World";
}