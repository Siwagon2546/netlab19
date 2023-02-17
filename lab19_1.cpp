#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream dest(filename);
    int a,b,c;
    string text;
    char name[100];
    char grade;
    char format[] = "%[^:]: %d %d %d" ;
    while(getline(dest ,text)){
        sscanf(text.c_str(),format,&name,&a,&b,&c);
        names.push_back(name);
        scores.push_back((a+b+c));
        grade = score2grade(a+b+c);
        grades.push_back(grade);
        
    }
    

}

void getCommand(string &com,string &key){
    cout<<"Please input your command: ";
    string line;
    char format[] = "%s  %[^:]s";
    char txt1[20], txt2[50];
    getline(cin,line);
    sscanf(line.c_str(),format,&txt1,&txt2);
    com = txt1;
    key = txt2;
    
}

void searchName(vector<string> names,const vector<int> scores,vector<char> grades,string key){
    cout<<"---------------------------------\n";
    int k=0;
    for(unsigned int i=0;i<names.size() ;i++){
        string textn = toUpperStr(names[i]);
        if(key == textn){
            cout<<names[i]<<"'s score = "<<scores[i]<<endl;
            cout<<names[i]<<"'s grade = "<< grades[i]<<endl;
            k++;
        }
    }
    if(k==0) cout<<"Cannot found.\n";
    cout<<"---------------------------------\n";

    

}

void searchGrade(vector<string> names,const vector<int> scores,vector<char> grades,string key){
    cout<<"---------------------------------\n";
    int k=0;
    for(unsigned int i=0;i<grades.size();i++){
        if(*key.c_str() == grades[i]){
            cout<<names[i]<<" ("<<scores[i]<<")"<<endl;
            k++;
        }
    }
    if(k==0) cout<<"Cannot found.\n";
    cout<<"---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
