#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;
//Global variables
int curRoom;
vector<string> items;
string border = "----------------------------------------\n";
/*Item index values
0 - "Vial" and be "Vial of blood"
1 - "Razor"
*/
//Declared functions
int roomStart();
int room1();
int room1chest();
int room2();
int room3();
int room4();
int room5();
void curItems();
//Main function
int main() {
	//Set up items
	items.push_back("None");
	items.push_back("None");

	bool run = true;
	curRoom = roomStart(); //Story setup
	do { //Game loop
		int roomNum;
		switch (curRoom) {
			case 1:
				roomNum = room1();
				if (roomNum == 2) {
					curRoom = 2;
				}
				else if (roomNum == 3) {
					curRoom = 3;
				}
				else if (roomNum == 6) {
					curRoom = 6;
				}
				break;
			case 2:
				roomNum = room2();
				if (roomNum == 1) {
					curRoom = 1;
				}
				break;
			case 3:
				roomNum = room3();
				if (roomNum == 1) {
					curRoom = 1;
				}
				else if (roomNum == 4) {
					curRoom = 4;
				}
				else if (roomNum == 5) {
					curRoom = 5;
				}
				break;
			case 4:
				roomNum = room4();
				if (roomNum == 3) {
					curRoom = 3;
				}
				break;
			case 5:
				roomNum = room5();
				if (roomNum == 3) {
					curRoom = 3;
				}
				break;
			case 6:
				roomNum = room1chest();
				if (roomNum == 1) {
					curRoom = 1;
				}
				else if (roomNum == 7) {
					curRoom = 7;
				}
				break;
			case 7:
				run = false;
				break;
		} 

	}while (run);
	cout << "\n\n\n\n\nGame Over\n\n\n\n\n";
	cin.ignore();
}
//Functions
void curItems() {
	bool itemBool = false;
	vector<int> index;
	for (int i = 0;i < items.size();i++) {
		if (items[i] != "None") {
			itemBool = true;
			index.push_back(i);
		}
	}
	if (itemBool) {
		cout << "Items: ";
		for (int i = 0; i < index.size();i++) {
			if (i == index.size() - 1) {
				cout << items[index[i]] << ".\n";
			}
			else {
				cout << items[index[i]] << ", ";
			}
		}
	}
	else {
		cout << "Items: None.\n";
	}
}
int roomStart(){
	cout << "You find yourself waking up in a strange room.\n";
	sleep(2);
	cout << "You get up to use the bathroom but find the door has been barred from the outside.\n";
	sleep(2);
	cout << "Your anxiety raised and you look for a way out, but all the windows are barred shut as well.\n";
	sleep(2);
	cout << "Looking down you see a handle peeking out from underneath the pentagram laden rug in the center of the room.\n";
	sleep(2);
	cout << "With distant murmurs approaching the door from the hallway you open the trapdoor and jump into the basement depths below.\n";
	sleep(2);
	cout << "After coughing up the dust that was dispersed from your landing you see lit candles surrounding a large chest with your name written on it.\n";
	sleep(2);
	cout << "Two doors are are visible under the glow of the candles.\n";
	return 1;
}
int room1(){
	int opt;
	bool optrun = true;
	while (optrun) {
		cout << border;
		cout << "Current room: Chest Room\n";
		curItems();
		cout << "1.	Inspect the large chest\n2.	Enter the metal door to the left\n3.	Enter the door to the right\nEnter your choice: ";
		cin >> opt;
		if (cin) {
			if (opt == 1) { 
				optrun = false;
				return 6;
			}
			else if (opt == 2) {
				optrun = false;
				return 2;
			}
			else if (opt == 3) { //move to other room stop the while loop
				optrun = false;
				return 3;
			}
			else {
				cout << "Please enter a vaild choice.\n";
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "Please enter a vaild choice.\n";
			cin.clear();
			cin.ignore();
		}
	}
}
int room1chest() {
	int opt;
	bool optrun = true;
	static bool firstEnter = true;
	if (firstEnter) {
		cout << "You get an uneasy feeling as you approach the chest.\n";
		sleep(2);
		cout << "Your ears ring and your skin crawls\n";
		sleep(2);
		firstEnter = false;
	}
	else {
		static bool secEnter = true;
		if (secEnter){
			secEnter = false;
			cout << "\"...give me your blood and you will be free...\" A disembodied voice whispers from all directions. \n";
			sleep(2);
		}
		else {
			cout << "\"...it is the only way to leave...\" a voice whispers.\n";
			sleep(2);
			cout << "You remember the voice asked for blood...\n";
			sleep(2);
		}
	}
	while (optrun) {
		cout << border;
		cout << "Current room: Chest Room(at chest)\n";
		curItems();
		if (items[0] != "Vial of blood" && items[1] != "Razor"){
			cout << "1.	Inspect the alter that the chest is on.\n2.	Inspect the candles.\n3.	Attempt to open the chest.\n4.	Back away from the chest.\nEnter your choice: ";
			}
		else if (items[0] != "Vial of blood" && items[1] == "Razor"){
			cout << "1.	Inspect the alter that the chest is on.\n2.	Inspect the candles.\n3.	Attempt to open the chest with your blood.\n4.	Back away from the chest.\nEnter your choice: ";
		}
		else if (items[0] == "Vial of blood" && items[1] != "Razor") {
			cout << "1.	Inspect the alter that the chest is on.\n2.	Inspect the candles.\n3.	Attempt to open the chest with the vial of blood.\n4.	Back away from the chest.\nEnter your choice: ";
		}
		else {
			cout << "1.	Inspect the alter that the chest is on.\n2.	Inspect the candles.\n3.	Attempt to open the chest with your blood.\n4.	Attempt to open the chest with the vial of blood.\n5.	Back away from the chest.\nEnter your choice: ";
		}
		cin >> opt;
		//Option without either item
		if (items[0] != "Vial of blood" && items[1] != "Razor"){
			if (cin) {
				if (opt == 1) {
					cout << "You try to move the chest put it appears to be far too heavy to move.\n";
					sleep(2);
				}
				else if (opt == 2) {
					cout << "The candles have been lit recently as there is not much wax dripping from them.\n";
					sleep(2);
				}
				else if (opt == 3) {
					cout << "It's locked with a strange lock without a normal key hole.\n";
					sleep(2);
				}
				else if (opt == 4) {
					cout << "You back away from the chest.\n";
					sleep(2);
					return 1;
				}
				else {
					cout << "Please enter a vaild choice.\n";
					cin.clear();
					cin.ignore();
				}
			}
			else {
				cout << "Please enter a vaild choice.\n";
				cin.clear();
				cin.ignore();
			}
		}
		//Option with the razor
		else if (items[0] != "Vial of blood" && items[1] == "Razor"){
			if (cin) {
				if (opt == 1) {
					cout << "You try to move the chest put it appears to be far too heavy to move.\n";
					sleep(2);
				}
				else if (opt == 2) {
					cout << "The candles have been lit recently as there is not much wax dripping from them.\n";
					sleep(2);
				}
				else if (opt == 3) {
					cout << "You cut you palm and place it on the strange lock.\n";
					sleep(2);
					cout << "The candles begin to dim to nothing as the chest opens by itself.\n";
					sleep(2);
					cout << "As the chest opens the whispering voice speaks to you one last time.\n";
					sleep(2);
					cout << "\"...you are mine now...\"\n";
					sleep(3);
					cout << "The floor under you falls and you vision fades...\n";
					sleep(2);
					cout << "\"...you are free...\"\n";
					sleep(2);
					return 7;
				}
				else if (opt == 4) {
					cout << "You back away from the chest.\n";
					sleep(2);
					return 1;
				}
				else {
					cout << "Please enter a vaild choice.\n";
					cin.clear();
					cin.ignore();
				}
			}
			else {
				cout << "Please enter a vaild choice.\n";
				cin.clear();
				cin.ignore();
			}
		}
		//Option with the blood vial
		else if (items[0] == "Vial of blood" && items[1] != "Razor"){
			if (cin) {
				if (opt == 1) {
					cout << "You try to move the chest put it appears to be far too heavy to move.\n";
					sleep(2);
				}
				else if (opt == 2) {
					cout << "The candles have been lit recently as there is not much wax dripping from them.\n";
					sleep(2);
				}
				else if (opt == 3) {
					cout << "You pour the vial of blood onto the strange lock.\n";
					sleep(2);
					cout << "All of the candles go out at once.\n";
					sleep(2);
					cout << "The whispering voice lets out a lound hiss.\n";
					sleep(2);
					cout << "Covering you ears to avoid the shreiking pain you try to scream.\n";
					sleep(2);
					cout << "\"THIS TAINED BLOOD IS NOT WHAT I WANT\" yells the voice booming from all corners of the room.\n";
					sleep(2);
					cout << "The chest springs open and a force pushes you from behind in.\n";
					sleep(2);
					cout << "Falling through this endless void you body begin to fade.\n";
					sleep(2);
					cout << "\"...this is what you get...\" the voice whispers.\n";
					sleep(5);
					cout << "You wake up in the same room.\n";
					sleep(2);
					cout << "This time there is no trap door.\n";
					sleep(2);
					cout << "This time you have no escape.\n";
					return 7;
				}
				else if (opt == 4) {
					cout << "You back away from the chest.\n";
					sleep(2);
					return 1;
				}
				else {
					cout << "Please enter a vaild choice.\n";
					cin.clear();
					cin.ignore();
				}
			}
			else {
				cout << "Please enter a vaild choice.\n";
				cin.clear();
				cin.ignore();
			}
		}
		//Option with both items
		else{
			if (cin) {
				if (opt == 1) {
					cout << "You try to move the chest put it appears to be far too heavy to move.\n";
					sleep(2);
				}
				else if (opt == 2) {
					cout << "The candles have been lit recently as there is not much wax dripping from them.\n";
					sleep(2);
				}
				else if (opt == 3) {
					cout << "You cut you palm and place it on the strange lock.\n";
					sleep(2);
					cout << "The candles begin to dim to nothing as the chest opens by itself.\n";
					sleep(2);
					cout << "As the chest opens the whispering voice speaks to you one last time.\n";
					sleep(2);
					cout << "\"...you are mine now...\"\n";
					sleep(3);
					cout << "The floor under you falls and you vision fades...\n";
					sleep(2);
					cout << "\"...you are free...\"\n";
					sleep(2);
					return 7;
				}
				else if (opt == 4) {
					cout << "You pour the vial of blood onto the strange lock.\n";
					sleep(2);
					cout << "All of the candles go out at once.\n";
					sleep(2);
					cout << "The whispering voice lets out a lound hiss.\n";
					sleep(2);
					cout << "Covering you ears to avoid the shreiking pain you try to scream.\n";
					sleep(2);
					cout << "\"THIS TAINED BLOOD IS NOT WHAT I WANT\" yells the voice booming from all corners of the room.\n";
					sleep(2);
					cout << "The chest springs open and a force pushes you from behind in.\n";
					sleep(2);
					cout << "Falling through this endless void you body begin to fade.\n";
					sleep(2);
					cout << "\"...this is what you get...\" the voice whispers.\n";
					sleep(5);
					cout << "You wake up in the same room.\n";
					sleep(2);
					cout << "This time there is no trap door.\n";
					sleep(2);
					cout << "This time you have no escape.\n";
					return 7;
				}
				else if (opt == 5) {
					cout << "You back away from the chest.\n";
					sleep(2);
					return 1;
				}
				else {
					cout << "Please enter a vaild choice.\n";
					cin.clear();
					cin.ignore();
				}
			}
			else {
				cout << "Please enter a vaild choice.\n";
				cin.clear();
				cin.ignore();
			}
		}
	}
}
int room2(){
	int opt; //Option integer for user input
	bool optrun = true; 
	static bool firstEnter = true; 
	if (firstEnter) { // Shows a message on the first time the user enters
		cout << "As you enter the door to the left of the chest you are hit with pungent scent of rotting flesh.\n"; //Print first message
		sleep(2); // Sleep
		cout << "Upon further inspection you see the corpses of cattle hanging on meat hooks.\n"; //Optional second message
		sleep(2); //Sleep
		cout << "The refrigeration unit in the room is clearly broken.\n";
		firstEnter = false;
	}
	else { //Shows a message on the second time the user enters
		cout << "The scent of the rotting cattle is still overwhelming.\n"; //Print a message on the second time the user enters the room
		sleep(2); //Sleep
		
	}
	while (optrun) {
		cout << border;
		cout << "Current Room: Butcher's Fridge\n"; //Display current room
		curItems(); //Display current items
		cout << "1-	Inspect the refrigeration unit in the back of the room.\n2-	Check out butchers table\n3-	Inspect the blood covered floor\n4-	Return to the chest room\nEnter your choice: "; //Choice selection 1. 2. 3. etc
		cin >> opt;
		if (cin) {
			if (opt == 1) { //Option 1
				cout << "The refrigeration unit is broken beyond repair.\n"; //Print message for the option
				sleep(2);
			}
			else if (opt == 2) { //Option 2
				cout << "On the table there is decaying butchered meat.\n"; //Print message for the option
				sleep(2);
				cout << "You don't want to eat it.\n";
				sleep(2);
			}
			else if (opt == 3) { //Option 3
				if (items[0] == "Vial") {
					cout << "You take the vial and fill it with the cattle blood.\n";
					sleep(2);
					items[0] = "Vial of blood";
				}
				else {
					cout << "The the blood as drained from the hanging cattle forming pools on blood on the floor.\n"; //Print message for the option
					sleep(2);
					}
			}
			else if (opt == 4) { //Option 4
				cout << "You step back into the chest room.\n"; //Print message for the option
				sleep(2);
				return 1; //Return a room number to go to
			}
			else {
				cout << "Please enter a vaild choice.\n"; //If an invalid value is taken
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "Please enter a vaild choice.\n"; //If an invalid input is taken
			cin.clear();
			cin.ignore();
		}
		}
}
//ROOM 3
int room3(){ 
	int opt; //Option integer for user input
	bool optrun = true; 
	static bool firstEnter = true; 
	if (firstEnter) { // Shows a message on the first time the user enters
		cout << "As you enter through the door candles on the walls begin lighting showing 2 doors on the left and right with a large\n steel door at the end of the hallway.\n"; //Print first message
		sleep(2); // Sleep
		firstEnter = false;
	}
	else { //Shows a message on the second time the user enters
		static bool secEnter = true;
		if (secEnter){ 
			secEnter = false; //Set second entry variable to false so this is not triggered agian
			cout << "A voice is heard yelling from the large steel door.\n"; //Print a message on the second time the user enters the room
			sleep(2); //Sleep
			cout << "You recognize the voice, but cannot make out what they are saying.\n";
			sleep(2);
	}
	}
	while (optrun) {
		cout << border;
		cout << "Current Room: The Hallway\n"; //Display current room
		curItems(); //Display current items
		cout << "1-	Enter the door to the left\n2-	Enter the door to the right\n3-	Enter the large steel door\n4-	Return to the chest room\nEnter your choice: "; //Choice selection 1. 2. 3. etc
		cin >> opt;
		if (cin) {
			if (opt == 1) { //Option 1
				cout << "You enter the door to the left.\n";
				sleep(2);
				return 4;
			}
			else if (opt == 2) { //Option 2
				cout << "You enter the door to the right\n";
				sleep(2);
				return 5;
			}
			else if (opt == 3) { //Option 3
				cout << "Upon further inspection the door appears to be welded on the edges.\n"; //Print message for the option
				sleep(2);
				cout << "You can hear a voice murrmuring though the door.\n";
				sleep(2);
			}
			else if (opt == 4) { //Option 4
				cout << "You return to the chest room.\n"; //Print message for the option
				sleep(2);
				return 1; //Return a room number to go to
			}
			else {
				cout << "Please enter a vaild choice.\n"; //If an invalid value is taken
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "Please enter a vaild choice.\n"; //If an invalid input is taken
			cin.clear();
			cin.ignore();
		}
		}
}
//ROOM 4
int room4(){
	int opt; //Option integer for user input
	bool optrun = true; 
	cout << border;
	static bool firstEnter = true; 
	if (firstEnter) { // Shows a message on the first time the user enters
		cout << "Opening the door you hear a scurring coming form behind a wooden desk.\n"; //Print a message on the second time the user enters the room
		sleep(2); //Sleep
		cout << "A lamp sitting on this desk switches on and reveals three cubicals to the left of you.\n";
		sleep(2);
		firstEnter = false;
	}
	else { //Displays message after the user has already entered the room once or twice
			cout << "The desk lamp begins to flicker as you enter the room.\n"; 
			sleep(2);
	}
	while (optrun) {
		cout << border;
		cout << "Current Room: The Office\n"; //Display current room
		curItems(); //Display current items
		cout << "1-	Inspect the desk \n2-	Inspect the cubicals\n3-	Inspect the whiteboard \n4-	Exit to the hall\nEnter your choice: "; //Choice selection 1. 2. 3. etc
		cin >> opt;
		if (cin) {
			if (opt == 1) { //Option 1
				static bool deskEnter = true;
				if (deskEnter) {
				cout << "You open the drawers and find a container of empty vials.\n"; //Print message for the option
				sleep(2);
				cout << "You pocket one for later\n";
				sleep(2);
				items[0] = "Vial";
				deskEnter = false;
				}
				else {
					cout << "There are tons of empty vials, but the one in you pocket should be enough\n";
					sleep(2);
				}
			}
			else if (opt == 2) { //Option 2
				cout << "The cubicals are covered in dust and seem very out of place in this trapdoor basement.\n"; //Print message for the option
				sleep(2);
				cout << "A post-it on one of the cubical walls has your name written on it.\n";
				sleep(2);
			}
			else if (opt == 3) { //Option 3
				cout << "The whiteboard is empty but dirty from constant use.\n"; //Print message for the option
				sleep(2);
			}
			else if (opt == 4) { //Option 4
				cout << "You leave back into the hallway.\n"; //Print message for the option
				sleep(2);
				return 3; //Return a room number to go to
			}
			else {
				cout << "Please enter a vaild choice.\n"; //If an invalid value is taken
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "Please enter a vaild choice.\n"; //If an invalid input is taken
			cin.clear();
			cin.ignore();
		}
		}
}
//ROOM 5
int room5(){
	int opt; //Option integer for user input
	bool optrun = true; 
	cout << border;
	static bool firstEnter = true; 
	if (firstEnter) { // Shows a message on the first time the user enters
		cout << "Opening the door you are hit with the pugent scent of an uncleaned washroom.\n"; //Print first message
		sleep(2); // Sleep
		cout << "You bear through the smell to investigate the room.\n"; //Optional second message
		sleep(2); //Sleep
		cout << "Your reflection in the grimy bathroom mirror stares at you above a sink flooded with filthy water.\n";
		sleep(2);
		firstEnter = false;
	}
	else { //Shows a message on the second time the user enters
		static bool secEnter = true;
		if (secEnter){ 
			secEnter = false; //Set second entry variable to false so this is not triggered agian
			cout << "You didn't brace yourself for the wretched smell.\n"; //Print a message on the second time the user enters the room
			sleep(2); //Sleep
			cout << "You bend over to vomit, but hold your composure.\n";
			sleep(2);
		}
		else { //Displays message after the user has already entered the room once or twice
			cout << "You brace yourself before entering this time.\n"; 
			sleep(2);
			cout << "The smell is still difficult to handle.\n";
			sleep(2);
		}
	}
	while (optrun) {
		cout << border;
		cout << "Current Room: The Washroom\n"; //Display current room
		curItems(); //Display current items
		cout << "1-	Investigate the sink\n2-	Investigate the toilet\n3-	Investigate the shower \n4-	Exit the bathroom \nEnter your choice: "; //Choice selection 1. 2. 3. etc
		cin >> opt;
		if (cin) {
			if (opt == 1) { //Option 1
				static bool sinkEnter = true;
				if (sinkEnter) {
					cout << "You stare into the flooded sink and see the glimmer of a straight razor through your reflection.\n";
					sleep(2);
					cout << "You bare the filth and grab it for later.\n";
					sleep(2);
					items[1] = "Razor";
					sinkEnter = false;
				}
				else {
					cout << "You look into the sink where you grabbed the straight razor.\n";
					sleep(2);
					cout << "Nothing more is in the grimy water.\n";
					sleep(2);
				}
			}
			else if (opt == 2) { //Option 2
				cout << "The toilet is flooded and surrounded by dead insects.\n"; //Print message for the option
				sleep(2);
				cout << "This is clearly where the foul smell is coming from.\n";
				sleep(2);
			}
			else if (opt == 3) { //Option 3
				cout << "The shower is flooded and covered in soap scum.\n"; //Print message for the option
				sleep(2);
				cout << "Compared to the rest of the washroom the scent is bearable.\n";
				sleep(2);
			}
			else if (opt == 4) { //Option 4
				cout << "You exit the washroom hoping not to return.\n"; //Print message for the option
				sleep(2);
				return 3; //Return a room number to go to
			}
			else {
				cout << "Please enter a vaild choice.\n"; //If an invalid value is taken
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "Please enter a vaild choice.\n"; //If an invalid input is taken
			cin.clear();
			cin.ignore();
		}
		}
}