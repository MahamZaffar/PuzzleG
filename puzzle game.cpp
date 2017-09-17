

#include <iostream>
#include<string>
#include <cstdlib>

#include <ctime>

using namespace std;


const int arraySize = 4;



char elements[ arraySize ] [ arraySize ] = {{'1','2','3','4'},    //arrays
			 {'5','6','7','8'},
			 {'9','A','B','C'},
		     {'D','E',' ','F'}};

  char chack  [ arraySize ] [ arraySize ] = {{'1','2','3','4'},  //arrays
			 {'5','6','7','8'},
			 {'9','A','B','C'},
			 {'D','E','F',' '}};

int vSP = 3; // vertical space Position
int hSP = 2; // horizontal space Position
 
 

 	
 //functions
 
void moveUp();
void moveDown();
void moveRight();
void moveLeft();
void randomise();             // randomize the array 
int winer();                  // chacks if player have solved the puzzel

                
int main()                	//main function
{
  const string USERNAME = "Maham";
	const string PASSWORD = "153175";
	string pass;
	string username;
	int counter=0;
	do
	{
	if(counter<3)
	{
		cout<<"Enter username and password "<<endl;
		cout<<"Enter username ";
		getline(cin,username); 
		cout<<"Enter password ";
		getline(cin,pass);
	if (username == USERNAME && pass == PASSWORD)
		{
			cout<<"Sucessfully logged in "<<endl;
			counter = 4;
			srand(time(0));                 
	randomise();
	bool quite(false);          //bool flag
	do                          //do-while loop
	{
	for(int i = 0; i < arraySize; i++){
	for(int j = 0; j < arraySize; j++)
	cout << "  " << elements[i][j];
	cout << endl << endl;
	}
	char a;
	cout << "8 - Up, 2 - Down, 4 - Left, 6 - Right" << endl; 
	cin >> a;
	switch(a)
	{
	case '8':
	//case 'w':
	moveUp();
	break;

	case '2':
	//case 'z':
	moveDown();
	break;

	//case 's':
	case '6':
	moveRight();

	break;

	case '4':
	//	case 'A':
	moveLeft();
	break;

	default:
	cout << "Wrong character, pleas type again!" << endl;
	break;

	}
	int c = winer();
	if(c == 1){
	cout << "Bravo! You solved the puzle!" << endl;
	
	quite = true;
	}
	system("cls"); 
	}while(quite == false);

			
		}
	else
		{
			cout<<"Invalid Username or password. Try again. "<<endl;
			counter++;
		}
	}
	else
	{
		exit(0);
	}
	}
	while(counter<3);

 	
          
	
	return 0;


 }
 	
 
void moveUp()
{
	int vP = vSP;
	if(vP + 1 < 4 && vP >= 0){
	
	elements[vSP][hSP] = elements[vSP + 1][hSP];
	elements[vSP + 1][hSP] = ' ';
	vSP += 1;
	}
}
void moveDown()
{
	int vP = vSP;
	if(vP + 1 <= 4 && vP > 0){
	
	elements[vSP][hSP] = elements[vSP - 1][hSP];
	elements[vSP - 1][hSP] = ' ';
	vSP -= 1;
	}
}
void moveRight()
{
	int hP = hSP;
	if(hP + 1 <= 4 && hP > 0){
	
	elements[vSP][hSP] = elements[vSP][hSP - 1];
	elements[vSP][hSP - 1] = ' ';
	hSP -= 1;
	}
}
void moveLeft()
{
	int hP = hSP;
	if(hP + 1 < 4 && hP >= 0){
	
	elements[vSP][hSP] = elements[vSP][hSP + 1];
	elements[vSP][hSP + 1] = ' ';
	hSP += 1;
	}
}
void randomise()
{
	for(int i = 0; i < 20000; i++)
	{
	int a = 1 + rand() % 4;
	switch(a)
	{
	case 1:
	moveUp();
	break;

	case 2:
	moveDown();
	break;

	case 3:
	moveRight();

	break;

	case 4:
	moveLeft();
	break;
	}
}
}
int winer()
{
int ans;

for(int i = 0; i < arraySize; i++)

{

	for(int j = 0; j < arraySize; j++)

	{

if(elements[i][j] == chack[i][j])
ans = 1;
else 
return -1;
	}
}
return 1;

}
