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
    cout << "top" << endl;
    cin >> input;
    if(strcmp(input,"ADD")==0){
      cout << "1" << endl;
      s_member[i] = new student;
      
      cin >> s_member[i]->name;
      cin >> s_member[i]->last_name;
      cin >> s_member[i]->id;
      cin >> s_member[i]->gpa;
      cout << s_member[i]->name << " " << s_member[i]->last_name << ", " << s_member[i]->id << ", " << s_member[i]->gpa << endl;
      i++;
      cout << "exit" << endl;
    }
    else if(strcmp(input,"DELETE")==0){
      cout << "2" << endl;
    }
    else if(strcmp(input,"PRINT")==0){
      cout << "3" << endl;
      cout << i << endl;
      for(int x = 0;x<i;x++){
	
	if(s_member[x]!= NULL){
	  cout << s_member[x]->name << " " << s_member[x]->last_name << ", " << s_member[x]->id << ", " << s_member[x]->gpa << endl;
	}
	else{
	  cout << "member is null" << endl;
	}
      }
    }
    else if(strcmp(input,"QUIT")==0){
      stop = true;
      for (int x = 0;x<i; x++){
	free(s_member[x]);
      }
    }
  }
}
