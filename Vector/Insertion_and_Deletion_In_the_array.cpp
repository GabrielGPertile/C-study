//libraries
#include<iostream>
#include<vector>
#include<limits>

//function prototype
void showMenu();
void insertValueInt(int *integerPointer);
void insertValueInVector_Beginning(std::vector<int>& myVectro, int number);
void insertValueIn_Vector_End(std::vector<int>& myVectro, int number);
void removeValueVector(std::vector<int>& myVectro);
void removeEspecificateValue(std::vector<int>& myVectro, int number);
void showVector(std::vector<auto>& showVector);
void clearScreen();
void pauseScreen();


//program main
int main()
{
	int option = 0;
	int number = 0;
	
	std::vector<int> myVector;
	
	do{
		showMenu();
		
		std::cout<<"Choose your option:\n";
		insertValueInt(&option);
		
		clearScreen();
		
		switch(option){
			case 1 :
				std::cout<<"Insert a value:\n";
				insertValueInt(&number);
				
				insertValueInVector_Beginning(myVector, number);
				
				clearScreen();				
			break;
			
			case 2 :
				std::cout<<"Insert a value:\n";
				insertValueInt(&number);
				
				insertValueIn_Vector_End(myVector, number);
				
				clearScreen();		
			break;
			
			case 3 :
				std::cout<<"Remove a last value in vector!\n";
				
				removeValueVector(myVector);
				
				pauseScreen();
				
				clearScreen();
			break;
			
			case 4 :
				std::cout<<"Values in vector:\n";
				
				showVector(myVector);
				
				std::cout<<"Insert a position to delete a value:\n";
				insertValueInt(&number);
				
				removeEspecificateValue(myVector, number);
				
				std::cout<<"A position deleting is:"<<number<<"\n";
				
				pauseScreen();
				
				clearScreen();
			break;
			
			case 5 :
				showVector(myVector);
				
				pauseScreen();
				
				clearScreen();
			break;
			
			case 0 :
				std::cout << "Exiting the application. Goodbye!\n";
			break;
			
			default :
				std::cout << "Invalid option. Please choose a valid option.\n";
                
				pauseScreen();
                
				clearScreen();
			break;
		}
	}while(option != 0);
	
}

//function body
void showMenu(){
	std::cout<<"Menu\n";
	std::cout<<"1 - Insertion at the beginning of the array utilizing a insert\n";
	std::cout<<"2 - Insertion at the end of the array utilizing push_back\n";
	std::cout<<"3 - Erase a value in vector\n";
	std::cout<<"4 - Erase a specified value in vector\n";
	std::cout<<"5 - Show the vector\n";
	std::cout<<"0 - Exit the application\n";
}

void insertValueInt(int *integerPointer){
	int assistantMAX = INT_MAX;
	int assistantMIN = INT_MIN;
	
	while(!(std::cin >> *integerPointer) || *integerPointer > assistantMAX || *integerPointer < assistantMIN){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Needs a number\n";
		std::cout<<"Digit again:\n";
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void insertValueInVector_Beginning(std::vector<int>& myVectro, int number){
	myVectro.insert(myVectro.begin(), number);
}

void insertValueIn_Vector_End(std::vector<int>& myVectro, int number){
	myVectro.push_back(number);
}

void removeValueVector(std::vector<int>& myVectro){
	myVectro.pop_back();
}

void removeEspecificateValue(std::vector<int>& myVectro, int number){
	myVectro.erase(myVectro.begin() + number);
}

void showVector(std::vector<auto>& showVector){
	for(int i = 0; i < showVector.size(); i++){
		std::cout<<"Position ["<<i<<"]:"<<showVector[i]<<"\n";
	}
}

void clearScreen(){
	#ifdef _WIN32
		system("cls");
	#elif defined __unix__ || __linux__
		system("clear");
	#elif defined __APPLE__
		system("clear");
	#else
		for(int i = 0; i < 50; i++){
			std::cout<<"\n";
		}
	#endif
}

void pauseScreen(){
	std::cout << "Press Enter to continue...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
