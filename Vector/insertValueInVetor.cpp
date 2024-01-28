//libraries
#include<iostream>
#include<vector>
#include<limits>

//function prototype
void showMenu();
void insertValueInt(int *integerPointer);
void insertValueInVector(int number, std::vector<int>& myVectro);
void showVector(const std::vector<int>& myVectro);
void clearScreen();
void pauseScreen();

//program main
int main()
{
	int option = 0;
	int number = 0;
	
	std::vector<int> myVectro;
	
	do{
		showMenu();
		insertValueInt(&option);
		
		clearScreen();
		
		switch(option){
			case 1 :
				std::cout<<"Insert a value:\n";
				insertValueInt(&number);
				
				std::cout<<"Inserting the value into the array...\n";
				
				insertValueInVector(number, myVectro);
				
				pauseScreen();
				
				clearScreen();
			break;
			
			case 2 :
				std::cout<<"Show values into vector:\n";
				
				showVector(myVectro);
				
				system("pause");
				
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

return 0;
}

//function body
void showMenu(){
	std::cout<<"Menu\n";
	std::cout<<"1 - Insert a value\n";
	std::cout<<"2 - Show values into vector\n";
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

void insertValueInVector(int number, std::vector<int>& myVectro){
	myVectro.push_back(number);
}

void showVector(const std::vector<int>& myVectro){
	for(int i = 0; i < myVectro.size(); i++){
		std::cout<<"Position ["<<i<<"]:"<<myVectro[i]<<"\n";
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
