#include<iostream>
#include<vector>
#include <limits>

void showMenu();
void inserirValue(int *integerPointer);
void clearScreen();
void pauseScreen();


int main()
{
	int option = 0;
	int number = 0;
	
	std::vector<int> myVector;	
		
	do{
		showMenu();
		
		std::cout<<"Choose your option:\n";
		inserirValue(&option);
		
		clearScreen();
		
		switch(option){
			case 1 :
				std::cout<<"Insert a value:\n";
				inserirValue(&number);
				
				myVector.push_back(number);
				
				clearScreen();
			break;
			
			case 2 :
				myVector.pop_back();
				
				clearScreen();
			break;
			
			case 3 :
				std::cout<<"Which index do you want to remove?\n";
				inserirValue(&number);
				
				myVector.erase(myVector.begin() + number);
				
				
				clearScreen();
			break;
			
			case 4 :
				std::cout<<"Show values into vector:\n";
				
				for(int i = 0; i < myVector.size(); i++){
					std::cout<<"Value for position "<<i<<" is: "<<myVector[i]<<"\n";
				}
				
				system("pause");
				
				clearScreen();
			break;
			
			case 0:
                std::cout << "Exiting the application. Goodbye!\n";
            break;
            
            default:
                std::cout << "Invalid option. Please choose a valid option.\n";
                
				pauseScreen();
                
				clearScreen();
            break;
		}
		
		
	}while(option != 0);
	
	
return 0;
}

void showMenu(){
	std::cout << "Vector functionalities\n";
	std::cout << "1 - Insert value\n";
	std::cout << "2 - Erase a value in vector\n";
	std::cout << "3 - Erase a specified value in vector\n";
	std::cout << "4 - Show the vector\n";
	std::cout << "0 - Exit the application\n";
}

void inserirValue(int *integerPointer){
	std::cin>>*integerPointer;
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
