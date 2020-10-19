

// Dhruv Jain
// 10/18/2020
//Student List
//Pointers and Structs


#include <iostream>
#include <cstring>

using namespace std;

struct student { //student Struct with First name, Last name, ID, and Gpa 

  char name [100];
  char last_name [50];
  int id;
  float gpa;

};

int main(){
  
  student **s_vector; //pointer to array of pointers
  student *s_member[50]; //array of pointers that point to students
  s_vector = &s_member[0];//points s_vector to first value in s_member 
  bool stop = false; //boolean to keep track if the user is still using the application
  int i = 0; //keeps track of how many students are made
  char input[30]; //char to track what the user wants to do 
  while (stop == false){ // while loop for application
    cout << "Please enter ADD, PRINT, or DELETE. If you would like to close the application enter QUIT" << endl; 
    cin >> input;// Reads user input
    if(strcmp(input,"ADD")==0){
      cout << "Please enter the first name of the student" << endl;
      s_member[i] = new student;
      
      cin >> s_member[i]->name; //reads name
      cout << "Please enter the Last name of the student" << endl;
      cin >> s_member[i]->last_name; //reads last name
      cout << "Please enter the ID of the student" << endl;
      cin >> s_member[i]->id; //reads id
      cout << "Please enter the Gpa of the student" << endl;
      cin >> s_member[i]->gpa; //reads gpa
      i++; //increase amount of students created
      }
    else if(strcmp(input,"DELETE")==0){
      cout << "Please enter student id of student you would like to delete" << endl;
      int temp = 0;
      cin >> temp;
      for (int x = 0; x<i; x++){
	if(temp == s_member[x]->id){
	  free(s_member[x]); //frees memory of the student that the user asks for
	  s_member[x]=NULL; //makes the pointer null
	}
	
	}
      
    }
    else if(strcmp(input,"PRINT")==0){
      for(int x = 0;x<i;x++){
	if(s_member[x]!= NULL){ //If the Student that the printer is on is not null
	  cout << s_member[x]->name << " " << s_member[x]->last_name << ", " << s_member[x]->id << ", "; //print First name, last name, and ID
	  cout.setf(ios::showpoint); //show floating zeros
	  cout.precision(3); //sets presicion to 3
	  cout << s_member[x]->gpa << endl; //prints gpa
	  cout.precision(100000000); // sets precision to a big number again
	  cout.unsetf(ios::showpoint);
	}
      }
    }
    else if(strcmp(input,"QUIT")==0){
      stop = true; //stops while loop
      for (int x = 0;x<i; x++){ //for loop to free all Students
	free(s_member[x]);
      }
    }
    else{
      cout << "That was not a valid command" << endl; 
    }
  }
}
