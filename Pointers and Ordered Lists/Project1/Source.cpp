#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


class orderedList {
protected:
	int* acc = new int[20];
	
public:
	orderedList() {
		//Everytime a new orderedList is created, each item is set to empty or nullptr
		for (int i = 0; i < 20; i++) {
			acc[i] = NULL;
		}
	}

	//Member function that adds items to the ordered list and sorts it in ascending order
	void addItem(int temp_item) {
		int* temp = new int(temp_item);
		for (int i = 0; i < 20; i++) {
			if (acc[i] == NULL) {
				acc[i] = *temp;
				break;
			}
		}
		int temp2;
		//First for loop that will be used to loop through the items in the list
		for (int i = 0; i < 20; i++) {
			//Second for loop that will be used to check each item in the list to see if there is a value that is less than the current one at position [i]
			for (int j = i + 1; j < 20; j++) {
				//If there is a value at position [j] (1+i) that is > than the value at position [i]:
				//Use the temp int variable to store the value in acc[i], set acc[i] to the value stored at acc[j], change acc[j] to the temp value
				if (acc[j] < acc[i]) {
					temp2 = acc[i];
					acc[i] = acc[j];
					acc[j] = temp2;
				}
			}
		}
	}

	//Member function that removes an item at a specified position and then resorts it in ascending order
	void removeItem(int num_remove) {
		int error = 0;
		for (int i = 0; i < 20; i++) {
			if (acc[i] == num_remove) {
				acc[i] = NULL;
				error = 1;
				break;
			}
		}
		if (error == 0) {
			cout << "The item entered does not exist in the list, try removing again." << endl;
		}
		int temp;
		//First for loop that will be used to loop through the items in the list
		for (int i = 0; i < 20; i++) {
			//Second for loop that will be used to check each item in the list to see if there is a value that is less than the current one at position [i]
			for (int j = i + 1; j < 20; j++) {
				//If there is a value at position [j] (1+i) that is > than the value at position [i]:
				//Use the temp int variable to store the value in acc[i], set acc[i] to the value stored at acc[j], change acc[j] to the temp value
				if (acc[j] < acc[i]) {
					temp = acc[i];
					acc[i] = acc[j];
					acc[j] = temp;
				}
			}
		}
	}

	//Function to print the current values in the list
	void printList() {
		for (int i = 0; i < 20; i++) {
			if (acc[i]) {
				cout << "list value: " << acc[i] << endl;
			}
		}
	}

	//Function to check if the list is empty. Iterates through list, if it finds an item in the list: return false, else return true
	bool isEmpty() {
		for (int i = 0; i < 20; i++) {
			if (acc[i] != NULL) {
				return false;
			}
		}
		return true;
	}

	//Function to check if the list is full. Iterates through and returns false if it finds an empty spot in the list.
	bool isFull() {
		for (int i = 0; i < 20; i++) {
			if (acc[i] == NULL) {
				return false;
			}
		}
		return true;
	}
};

class reverseList : public orderedList {

public:
	reverseList() {
		orderedList();
	}

	//The addItem method for the reverseList class inserts items at the end of the list and sorts from the end 
	void addItem(int temp_acc) {
		int* temp = new int(temp_acc);
		for (int i = 19; i > 0; i--) {
			if (acc[i] == NULL) {
				acc[i] = *temp;
				break;
			}
		}

		int temp2;
		//First for loop that will be used to loop through the items in the list
		for (int i = 19; i > 0; i--) {
			//Second for loop that will be used to check each item in the list to see if there is a value that is less than the current one at position [i]
			for (int j = i - 1; j > 0; j--) {
				//If there is a value at position [j] (1+i) that is > than the value at position [i]:
				//Use the temp int variable to store the value in acc[i], set acc[i] to the value stored at acc[j], change acc[j] to the temp value
				if (acc[j] > acc[i]) {
					temp2 = acc[i];
					acc[i] = acc[j];
					acc[j] = temp2;
				}
			}
		}
	}

	

};


int main() {
	srand((unsigned)time(0));
	orderedList Jack;
	reverseList Mason;
	int menu = 0;
	//The while loop initiates the menu which is used to control the list by adding, deleting, or printing the list.
	while (menu != -1) {
		cout << "Press 1 to add an item to the list: " << endl;
		cout << "Press 2 to delete an item from the list: " << endl;
		cout << "Press 3 to print the list: " << endl;
		cout << "Press -1 to exit the menu: " << endl;
		cin >> menu;

		if (menu == 1) {
			int add_item;
			cout << "Enter the number to be added to the list: " << endl;
			cin >> add_item;
			Jack.addItem(add_item);
		}
		else if (menu == 2) {
			int remove_item;
			cout << "Enter the number you would like to delete from the list: " << endl;
			cin >> remove_item;
			Jack.removeItem(remove_item);
		}
		else if (menu == 3) {
			Jack.printList();
		}
		else if (menu == -1) {
			break;
		}
	}
	menu = 0;
	while (menu != -1) {
		cout << "Press 1 to add an item to the list: " << endl;
		cout << "Press 2 to delete an item from the list: " << endl;
		cout << "Press 3 to print the list: " << endl;
		cout << "Press -1 to exit the menu: " << endl;
		cin >> menu;

		if (menu == 1) {
			int add_item;
			cout << "Enter the number to be added to the list: " << endl;
			cin >> add_item;
			Mason.addItem(add_item);
		}
		else if (menu == 2) {
			int remove_item;
			cout << "Enter the number you would like to delete from the list: " << endl;
			cin >> remove_item;
			Mason.removeItem(remove_item);
		}
		else if (menu == 3) {
			Mason.printList();
		}
		else if (menu == -1) {
			break;
		}
	}

}