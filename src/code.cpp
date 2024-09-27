#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Operation's Menu
void menu(){
	cout << "1. To add two binaries." << endl;
	cout << "2. To subtract two binaries" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "\n";
}

// 1's compliment Function
string one_s_compliment(string binary){  
 
    string compliment = "";
       
    for (int i = 0; i < binary.length(); i++){
        if (binary[i] == '0'){
            compliment += '1';
        }
        else{
            compliment += '0';
        }
    }
    
    return compliment;  
}

// Reverse String Function
string reverse_string(string binary){
	
	string reverse = "";
	
	for (int i = binary.length() - 1; i >= 0 ; i--){
		reverse += binary[i];
	}
	
	return reverse;
}

// 2's compliment Function
string __two_s_compliment__(string binary){
	
    string ones_complement = one_s_compliment(binary);
    string twos_compliment = "";
    char carry = '1';  

    for (int i = ones_complement.length() - 1; i >= 0; i--){
        if (ones_complement[i] == '1' && carry == '1'){
            twos_compliment += '0';  
        }
        else if (ones_complement[i] == '0' && carry == '1'){
            twos_compliment += '1';  
            carry = '0';  
        }
        else{
            twos_compliment += ones_complement[i];  
        }
    }
    
    if (carry == '1'){
        twos_compliment += '1';
    }
    
    twos_compliment = reverse_string(twos_compliment);
    
    return twos_compliment;
}

// Fix Length
string fix_binaries(string b1, string b2){
	string binary = "";
	if (b1.length() > b2.length()){
		int difference = b1.length() - b2.length();
		binary = reverse_string(b2);
		
		for (int i = 0; i < difference; i++){
			binary += '0';
		}
		
		binary = reverse_string(binary);
		return binary;
	}
	else if (b1.length() < b2.length()){
		int difference = b2.length() - b1.length();
		binary = reverse_string(b1);
		
		for (int i = 0; i < difference; i++){
			binary += '0';
		}
		
		binary = reverse_string(binary);
		return binary;
	}
	
	return binary;
}

// Binary Addition
string binary_addition(string b1, string b2){
	
	string sum = "";
	string binary1 = b1;
	string binary2 = b2;
	char carry = '0';
	
	if (b1.length() > b2.length()){
		binary2 = fix_binaries(b1, b2);
	}
	else if (b1.length() < b2.length()){
		binary1 = fix_binaries(b1, b2);
	}
	else{
		binary1 = b1;
		binary2 = b2;
	}
	
	binary1 = reverse_string(binary1);
	binary2 = reverse_string(binary2);
	
	for (int i = 0; i < binary1.length(); i++){
		if (binary1[i] == '1' && binary2[i] == '1'){
			if (carry == '0'){
				sum += '0';
				carry = '1';
			}
			else{
				sum += '1';
				carry = '1';
			}
		}
		else if ((binary1[i] == '1' && binary2[i] == '0') || (binary1[i] == '0' && binary2[i] == '1')){
			if (carry == '0'){
				sum += '1';
				carry = '0';
			}
			else{
				sum += '0';
				carry = '1';
			}
		}
		else if (binary1[i] == '0' && binary2[i] == '0'){
			if (carry == '0'){
				sum += '0';
				carry = '0';
			}
			else{
				sum += '1';
				carry = '0';
			}
		}
	}
	
	if (carry == '1') {
        sum += '1';
    }
    
    sum = reverse_string(sum);
	
	return sum;
}

// Binary Subtraction 
string binary_subtraction(string b1, string b2){
	string difference = "";
	string binary1 = b1;
	string binary2 = __two_s_compliment__(b2);
	
	difference = binary_addition(binary1, binary2);
	
	return difference;
}

// Main Function
int main(){
	/*
	[+] This program is has capability of adding two binaries and finding 
	    difference of two binaries, the program can detect if they are 
	    not equal to each other in length, it can also fix them.
	    And print the required operation on it.
	
		1. Addition of binaries is very simple.
		2. Subtraction of binaries is done using 2's compliment and then adding them.
	
	*/
	
	char choice = '0';
	
	menu();
	
	cout << "Enter your choice : ";
	cin >> choice;
	
	if (choice == '1'){
		string binary1 = "";
		string binary2 = "";
		
		cout << "Enter your first binary value : ";
		cin >> binary1;
		
		cout << "Enter your second binary value : ";
		cin >> binary2;
		
		cout << "---------------------------------------------------------------------------------" << endl;
    	cout << "The Binary addition of " << binary1 << " with " << binary2 << " is : " << binary_addition(binary1, binary2) << endl;
	}
	else if (choice == '2'){
		string binary1 = "";
		string binary2 = "";
		
		cout << "Enter your first binary value : ";
		cin >> binary1;
		
		cout << "Enter your second binary value : ";
		cin >> binary2;
		
		cout << "---------------------------------------------------------------------------------" << endl;
    	cout << "The Binary Subtraction of "<< binary2 << " from " << binary1 << " is : " << binary_subtraction(binary1, binary2) << endl;
	}
	else{
		cout << "Invalid Option, Try Again....";
		exit;
	}
	
	return 0;
}
