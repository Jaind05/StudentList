#include <iostream>
#include <cstring>

using namespace std;

struct student {

  char name [100];
  char last_name [50];
  int id;
  float gpa;

};

int main(){
  
  student **s_vector;
  student *s_member[50];
  s_vector = &s_member[0];
  bool stop = false;
  int i = 0;
  char input[30]; 
  while (stop == false){
    cout << "Please enter ADD, PRINT, or DELETE. If you would like to close the application enter QUIT" << endl; 
    cin >> input;
    if(strcmp(input,"ADD")==0){
      cout << "Please enter the first name of the student" << endl;
      s_member[i] = new student;
      
      cin >> s_member[i]->name;
      cout << "Please enter the Last name of the student" << endl;
      cin >> s_member[i]->last_name;
      cout << "Please enter the ID of the student" << endl;
      cin >> s_member[i]->id;
      cout << "Please enter the Gpa of the student" << endl;
      cin >> s_member[i]->gpa;
      i++;
      }
    else if(strcmp(input,"DELETE")==0){
      cout << "Please enter student id of student you would like to delete" << endl;
      int temp = 0;
      cin >> temp;
      for (int x = 0; x<i; x++){
	if(temp == s_member[x]->id){
	  free(s_member[x]);
	  s_member[x]=NULL;
	}
	
	}
      
    }
    else if(strcmp(input,"PRINT")==0){
      for(int x = 0;x<i;x++){
	if(s_member[x]!= NULL){
	  cout << s_member[x]->name << " " << s_member[x]->last_name << ", " << s_member[x]->id << ", ";
	  cout.setf(ios::showpoint);
	  cout.precision(3);
	  cout << s_member[x]->gpa << endl;
	  cout.precision(100000000);
	  cout.unsetf(ios::showpoint);
	}
      }
    }
    else if(strcmp(input,"QUIT")==0){
      stop = true;
      for (int x = 0;x<i; x++){
	free(s_member[x]);
      }
    }
    else{
      cout << "That was not a valid command" << endl; 
    }
  }
}
