#include <iostream>
#include <string>
#include <fstream>
#include <cmath> // the modf func is here -- takes in a float, returns the fraction part and also records the integer part
#include <cstdlib>
#include <cassert>
using namespace std;

bool bothdivisible(int num, int denom, int divider);
int simplifier(bool smallernum, bool equal, int& num, int& denom, int origdenom, int orignum);

int main(){

double input;

cout << "Enter the decimal to be converted" << endl;
cin >> input;
double originput = input;


int tens = 1;

double fracpart, intpart = 0;

bool contflag = true;
do {
fracpart = modf(input, &intpart); 
//cout << fracpart << " " << intpart << endl;

if (fracpart != 0.0){
	input *= 10;
	tens *= 10;
}
else 
	contflag = false;


//cout << endl << "Contflag " << contflag << endl << endl;
}
while (contflag);

cout << originput << " = " << input << " / " << tens << endl;

int num, denom, orignum, origdenom;
num = input;
denom = tens;
bool smallernum;
bool equal;
orignum = num;
origdenom = denom;

if (num < denom){
	smallernum = true;
}
else if (denom > num){
	smallernum = false;
	equal = false;
}
else if (denom == num){
	equal = true;
	smallernum = false;
}


int result = simplifier(smallernum, equal, num, denom, origdenom, orignum);

if (result == 1){
	cout << orignum << "/" << origdenom << " = " << result << endl;
}




return 0;
}


int simplifier(bool smallernum, bool equal, int& num, int& denom, int origdenom, int orignum){
	int start;
	
if (smallernum){
	start = num;
}

else{ if (not equal){
start = denom;
}
else {
return 1;
}
}

	for (int i = (start); 0 < i; i--){
		if (bothdivisible(num, denom, i)){
			num /= i;
			denom /= i;
		}
	}
	if (denom == 1){
		cout << orignum << "/" << origdenom << " = " << num << endl;
	}
	else
		cout << orignum << "/" << origdenom << " = " << num << "/" << denom << endl;

	return 0;
}
	


bool bothdivisible(int num, int denom, int divider){
	if ((num % divider == 0)&&(denom % divider == 0))
		return true;
	else
		return false;
}