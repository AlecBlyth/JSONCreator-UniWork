#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int JSONCreator(string i0, int i1, int i2, int i3) {

	bool inputCheck;
	bool kanbanCheck;

	vector<string>roleVector; //Vector list for roles 
	vector<string>deptVector; //Vector list for departments
	vector<string>taskVector; //Vector list for task types
	vector<string>customKanban; //Vector list for custom Kanban labels 

	string role;  //Done
	string dept; //Done
	string task; //Done
	string label;  //Done

	char input;
	char test;
	const char* path = "/Users/Alec/Desktop/JSONFiles/ProjectFile.json";

	ofstream outfile(path); //Create new JSON file
	outfile << "{" << endl << "\"projectType\" :" << "\"" << i0 << "\"" << "," << endl; //Enter first line for JSON Structure. 

	cout << endl;
	cout << "Please enter roles: " << endl;

	for (int i = 0; i < i1; i++) { //Loop until all roles have been filled in 
		cin >> role;
		roleVector.push_back(role); //Push input into vector 
	}
	outfile << "\"projectRoles\" :" << "[" << endl; // Create new array inside JSON file
	cout << "Inserting Roles into JSON file!" << endl;
	for (unsigned i = 0; i < roleVector.size(); i++) { //Loop through role vector 
		if (roleVector.at(i) == roleVector.end()[-1]) { //If loop reaches end 
			outfile << "  " << "\"" << roleVector.at(i) << "\"" << endl; //Print last element into JSON array 
			break;
		}
		else {
			outfile << "  " << "\"" << roleVector.at(i) << "\"" << "," << endl; //Else print new element with comma for corresponding/last element 
		}


	}

	outfile << "]" "," << endl; // close JSON array and print comma for new array 
	cout << endl;

	if (i2 >= 1) { //Checks if project has one or more departments, if so allow use to input dept names.
		cout << "Please enter department names: " << endl;

		for (int x = 0; x < i2; x++) { //Loop until all departments have been filled in 
			cin >> dept;
			deptVector.push_back(dept); //Push input into vector 
		}
		outfile << "\"projectDepts\" :" << "[" << endl; // Create new array inside JSON file

		cout << "Inserting departments into JSON file!" << endl;

		for (unsigned x = 0; x < deptVector.size(); x++) { //Loop through dept vector 
			if (deptVector.at(x) == deptVector.end()[-1]) { //If loop reaches end 
				outfile << "  " << "\"" << deptVector.at(x) << "\"" << endl; //Print last element into JSON array 
				break;
			}
			else {
				outfile << "  " << "\"" << deptVector.at(x) << "\"" << "," << endl; //Else print new element with comma for corresponding/last element 
			}
		}
		outfile << "]" "," << endl; // close JSON array and print comma for new array 

	}
	else {
		outfile << "\"projectTasks\" :" << "[" << endl << "  " << "NULL" << endl << "]," << endl; // Creates placeholder for array. 
	}

	if (i3 >= 1) { //Checks if project has one or more tasks, if so allow use to input task types.
		cout << "Please enter task types: " << endl;

		for (int a = 0; a < i3; a++) { //Loop until all tasks have been filled in 
			cin >> task;
			taskVector.push_back(task); //Push input into vector 
		}
		outfile << "\"projectTasks\" :" << "[" << endl; // Create new array inside JSON file

		cout << "Inserting tasks into JSON file!" << endl;

		for (unsigned a = 0; a < taskVector.size(); a++) { //Loop through task vector 
			if (taskVector.at(a) == taskVector.end()[-1]) { //If loop reaches end 
				outfile << "  " << "\"" << taskVector.at(a) << "\"" << endl; //Print last element into JSON array 
				break;
			}
			else {
				outfile << "  " << "\"" << taskVector.at(a) << "\"" << "," << endl; //Else print new element with comma for corresponding/last element 
			}
		}
		outfile << "]," << endl; // close JSON array and print comma for new array 

	}
	else {
		outfile << "\"projectTasks\" :" << endl << "[" << endl << "  " << "NULL" << endl << "]," << endl; // Creates placeholder for array. 
	}

	cout << "Does this project have custom Kanban labels?" << endl;
	cin >> input;
	switch (input) {
	case 'Y':
		kanbanCheck = true;
		cout << "Please enter Kanban labels: " << endl;
		for (int z = 0; z < 5; z++) { //Loop until all labels have been filled in 
			cin >> label;
			customKanban.push_back(label); //Push input into vector 
		}
		outfile << "\"projectLabels\" :" << "[" << endl; // Create new array inside JSON file

		cout << "Inserting labels into JSON file!" << endl;

		for (unsigned z = 0; z < customKanban.size(); z++) { //Loop through label vector 
			if (customKanban.at(z) == customKanban.end()[-1]) { //If loop reaches end 
				outfile << "  " << "\"" << customKanban.at(z) << "\"" << endl; //Print last element into JSON array 
				break;
			}
			else {
				outfile << "  " << "\"" << customKanban.at(z) << "\"" << "," << endl; //Else print new element with comma for corresponding/last element 
			}
		}
		outfile << "]," << endl; // close JSON array and print comma for new array 
		break;
	case 'N':
		kanbanCheck = false;
		cout << "Entering Default Values..." << endl;
		outfile << "\"projectLabels\" :" << endl << "[" << endl << "  " << "\"Backlog\"" << "," << endl << "  " << "\"In Progress\"" << "," << endl << "  "  <<  "\"Testing\"" << "," << endl << "  " << "\"Complete\"" << "," << endl << "  "  << "\"Blocked\"" << endl << "]," << endl;
		break;
	default : 
		kanbanCheck = false;
		cout << "Entering Default Values..." << endl;
		outfile << "\"projectLabels\" :" << endl << "[" << endl << "  " << "\"Backlog\"" << "," << endl << "  " << "\"In Progress\"" << "," << endl << "  " << "\"Testing\"" << "," << endl << "  " << "\"Complete\"" << "," << endl << "  " << "\"Blocked\"" << endl << "]," << endl;
		break;
	}
	cout << "Does this project have personalised subjects?" << endl;
	cin >> input;

	switch (input) {
	case 'Y' :
		cout << "Subjects = True" << endl;
		outfile << "\"projectSubjects\" :" << endl << "  " << "true" << endl; // Creates boolean in JSON
		inputCheck = true;
		break;
	case 'N' :
		cout << "Subjects = False" << endl;
		outfile << "\"projectSubjects\" :" << endl << "  " << "false" << endl; // Creates boolean in JSON
		inputCheck = false;
		break;
	default :
		cout << "Subjects = False" << endl;
		outfile << "\"projectSubjects\" :" << endl << "  " << "false" << endl; // Creates boolean in JSON
		inputCheck = false;
		break;
	}

	cout << endl << "=====================Summary=====================" << endl; 
	cout << "Project Type: " << i0 << endl;
	cout << "------------------------------" << endl;
	cout << "Project Roles: " << endl;
	for (vector<string>::iterator i = roleVector.begin(); i != roleVector.end(); i++)
	cout << *i << ' ' << endl;
	cout << "------------------------------" << endl;
	cout << "Project Departments: " << endl;
	for (vector<string>::iterator i = deptVector.begin(); i != deptVector.end(); i++)
		cout << *i << ' ' << endl;
	cout << "------------------------------" << endl;
	cout << "Project Tasks: " << endl;
	for (vector<string>::iterator i = taskVector.begin(); i != taskVector.end(); i++)
		cout << *i << ' ' << endl;
	cout << "------------------------------" << endl;
	cout << "Project Kanban Board: " << endl;
	if (kanbanCheck == true) {
		for (vector<string>::iterator i = customKanban.begin(); i != customKanban.end(); i++)
			cout << *i << ' ' << endl;
	}
	else {
		cout << "Backlog | In Progress | Testing | Complete | Blocked" << endl;
	}
	cout << "------------------------------" << endl;

	cout << "Project Subjects: "; {
		if (inputCheck == true) {
			cout << " True" << endl;
		}
		else {
			cout << " False" << endl; 
		}
	}
	cout << "------------------------------" << endl;

	cout << "Are these values correct? (Y/N) " << endl; 
	cin >> input;

	switch (input) {
	case 'Y' :
		outfile << "}" << endl;
		outfile.close(); //Finalise file and close. 
		cout << "JSON file has been created!" << endl;
		exit(1);
	case 'N' :
		outfile.close(); //Finalise file and close.
	}
	return 0;
}


void jsonMenu() {
	
	string ProjectType;
	char input;
	int roleNum;
	int deptNum;
	int taskNum;

	cout << "Enter Project Type:" << endl;
	cin >> ProjectType;
	cout << "How many roles are in " << ProjectType << "?" << endl;
	cin >> roleNum;
	cout << "How many departments are in " << ProjectType << "?" << endl;
	cin >> deptNum;
	cout << "How many task types are in " << ProjectType << "?" << endl;
	cin >> taskNum;

	cout << "Current Selection" << endl;
	cout << "=================" << endl;
	cout << "Project Type: " << ProjectType << endl;
	cout << "Number of Roles: " << roleNum << endl;
	cout << "Number of Departments: " << deptNum << endl;
	cout << "Number of Tasks: " << taskNum << endl;
	cout << "=================" << endl;
	cout << "Are these correct? (Y/N)" << endl;

	cin >> input;

	switch (input) {
	case 'Y':
		JSONCreator(ProjectType, roleNum, deptNum, taskNum);
		break;
	case 'N':
		jsonMenu();
		break;
	default:
		jsonMenu();
		break;
	}
}
void menu() {

	int input;
	cout << "                                Menu                              " << endl;
	cout << "1: Create JSONs" << endl;
	cout << "2: Help" << endl;
	cout << "3: Exit" << endl;

	cin >> input;

	switch (input) {
	case 1:
		cout << "Loading JSON Creator" << endl;
		jsonMenu();
		break;
	case 2:
		cout << endl;
		cout << "This application is used to create files for ProManage" << endl;
		cout << "To create files, select 1 from the menu screen, afterwhich you will be prompt with questions regarding a project structure." << endl;
		cout << "Project Type is the type of project the client has requested, for example construction or software" << endl;
		cout << "A project will have roles, departments and tasks. The client will give you a list of roles, departments and tasks" << endl;
		cout << "Insert the number of these respective attributes into the system and check if the values are correct." << endl;
		cout << "Once the values are entered, enter the attributes and proceed." << endl;
		menu();
	case 3:
		cout << "Program Closing" << endl;
		break;
	}
}	
int main() {
	
	//UI Elements 

	//Layer 1 
	cout << "\033[1;34m        \033[0m";  cout << "\033[1;34m   \033[0m"; cout << "\033[7;4;34m          \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m            \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m        \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m        \033[0m\n";
	//Layer 2
	cout << "\033[1;34m        \033[0m"; cout << "\033[1;34m  \033[0m"; cout << "\033[7;4;34m            \033[0m"; cout << "\033[1;34m     \033[0m"; cout << "\033[7;4;34m               \033[0m"; cout << "\033[1;34m   \033[0m"; cout << "\033[7;4;34m         \033[0m"; cout << "\033[1;34m    \033[0m"; cout << "\033[7;4;34m         \033[0m\n";
	//Layer 3
	cout << "\033[1;34m        \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m    \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m    \033[0m"; cout << "\033[1;34m       \033[0m"; cout << "\033[7;4;34m    \033[0m"; cout << "\033[1;34m   \033[0m"; cout << "\033[7;4;34m     \033[0m"; 
	cout << "\033[1;34m     \033[0m"; cout << "\033[7;4;34m        \033[0m"; cout << "\033[1;34m  \033[0m"; cout << "\033[7;4;34m        \033[0m\n";
	//Layer 4
	cout << "\033[1;34m        \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m              \033[0m"; cout << "\033[1;34m       \033[0m"; cout << "\033[7;4;34m           \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m    \033[0m"; cout << "\033[1;34m  \033[0m"; 
	cout << "\033[7;4;34m   \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m   \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m    \033[0m\n";
	//Layer 5
	cout << "\033[1;34m        \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m              \033[0m"; cout << "\033[1;34m       \033[0m"; cout << "\033[7;4;34m           \033[0m"; cout << "\033[1;34m      \033[0m"; cout << "\033[7;4;34m    \033[0m"; 
	cout << "\033[1;34m  \033[0m"; cout << "\033[7;4;34m       \033[0m"; cout << "\033[1;34m \033[0m"; cout << "\033[7;4;34m    \033[0m\n";
	//Layer 6
	cout << "\033[1;34m        \033[0m"; cout << "\033[1;34m \033[0m";	cout << "\033[7;4;34m    \033[0m";	cout << "\033[1;34m      \033[0m";	cout << "\033[7;4;34m    \033[0m";cout << "\033[1;34m       \033[0m";	cout << "\033[7;4;34m    \033[0m";	
	cout << "\033[1;34m   \033[0m";	cout << "\033[7;4;34m     \033[0m";	cout << "\033[1;34m     \033[0m";cout << "\033[7;4;34m    \033[0m";	cout << "\033[1;34m   \033[0m";cout << "\033[7;4;34m     \033[0m";	cout << "\033[1;34m  \033[0m";cout << "\033[7;4;34m    \033[0m\n";
	//Layer 7
	cout << "\033[1;34m        \033[0m"; cout << "\033[7;4;34m     \033[0m";cout << "\033[1;34m      \033[0m";cout << "\033[7;4;34m     \033[0m";cout << "\033[1;34m   \033[0m";cout << "\033[7;4;34m               \033[0m";cout << "\033[1;34m   \033[0m";
	cout << "\033[7;4;34m      \033[0m";cout << "\033[1;34m    \033[0m";cout << "\033[7;4;34m   \033[0m";cout << "\033[1;34m   \033[0m";cout << "\033[7;4;34m      \033[0m\n";
	//Layer 8
	cout << "\033[1;34m        \033[0m"; cout << "\033[7;4;34m     \033[0m";cout << "\033[1;34m      \033[0m";cout << "\033[7;4;34m     \033[0m";cout << "\033[1;34m   \033[0m";cout << "\033[7;4;34m            \033[0m";cout << "\033[1;34m      \033[0m";
	cout << "\033[7;4;34m      \033[0m";cout << "\033[1;34m     \033[0m";cout << "\033[7;4;34m \033[0m";	cout << "\033[1;34m    \033[0m";cout << "\033[7;4;34m      \033[0m\n";
	
	cout << "==========================================================================" << endl;
	cout << "           ABM JavaScript Object Notation Generator for ProManage      " << endl;
	cout << "		                Verson 1.04      " << endl;
	cout << "		   (C) Copyright ABM Corporation 1993      " << endl;
	cout << "		      Written by: Alexander Blyth      " << endl;
	cout << "==========================================================================" << endl;
	menu();

}
