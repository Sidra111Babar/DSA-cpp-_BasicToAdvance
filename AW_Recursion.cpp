#include <iostream>
using namespace std;
// Base case is that case where recursive call should stop and it is written firstly before the definition of the function 
void printFirstFour(int n) {
    // Base case: stop recursion when n is greater than 4 (Base case pe wo condition dalini hoti ha jhan pe stop krna hota ha recursion ko)
    if (n > 4) {
        return;
    }

    // Print the current value of n
    cout << n << " ";   // base case kay bad function jo work kr rha hota ha wo sara work like uski implementation yhan pe apply krni hoti ha

    // Recursively call the function with the next value of n
    printFirstFour(n + 1); // yhan pe ak to function call ho ga jo function ki definition ho gi us kay according dusra value update ho gi
}
void printNumbers(int start, int end) {
    if (start > end) 
        return;
    
    cout << start << " "; 
    printNumbers(start + 1, end);
}
void printinReverse_Order(int n){
	if(n <= 0){
		return;
	}
	cout << n << " ";
	printinReverse_Order(n - 1);
}
int sum(int n) {
    if (n == 1) {                                                                       // when n = 1 return 1 ho ga or recursive call stop h gi
        return 1;
    }             
                                                                                      // cout << 1; This line is for the purpose of dry run as 1 will print 9 times this means that 9 times recursive call will occur
    return n + sum(n - 1);                                                             // n ki value 10 thi yhan akr 9 ho jay gi phr jb dobara yhan aya ga 8 ho gi .... process repeat ho ga until n ki value 1 na ho jay
                                                                                   // lakin jo return value ho gi wo n me add wali ho gi like n + 9 (10 + 9) in first recursive call, n + 8(19 + 8) in second
                                                                                       // n + 7(27 + 7) in 3rd, n + 6(34 + 6) in 4th, n + 5(40 + 5) in 5th, n + 4(45 + 4) in 6th, n + 3(49 + 3) in 7th, n + 2(52 + 2) in 8th, n + 1(54 + 1) = 55 in 9th recursive call
                                                                                      // return 55
}
void printTable(int num, int multiplier) {
    if (multiplier > 10) {  // Print the table up to 10
        return;
    }
    cout << num << " * " << multiplier << " = " << num * multiplier << endl;
    printTable(num, multiplier + 1); 
}
int factorial(int n){
	if(n <= 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return n * factorial(n - 1);
}

bool isPrime(int n, int i = 2) {
    if (n <= 2) {
        return (n == 2) ? true : false;                                 // if n is 0 and 1 then not a prime no if n is 2 then prime no
    }
    if (n % i == 0) {                                                 // if divisible to any other number other than itself then not a prime no return false
        return false;
    }
    if (i * i > n) {
        return true;                                                     // agr kisi pe b divide na huwa it means i * i ab greater hi aya ga and return true   
    }
    return isPrime(n, i + 1);
}
void reverseArray(string arr[], int i) {
    if (i == 0) {
        return;
    }
    cout << arr[i - 1] << " ";
    reverseArray(arr, i - 1);
}
void AllFactors(int n, int i = 1) {
    if (i < 1) {
        return;
    }
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        cout << i << " ";
    }
    AllFactors(n, i + 1);
}


int main() {
    // Start the recursion with n = 1
    printFirstFour(1);
    cout << endl;
    printNumbers(3,10);
    cout << endl;
    printinReverse_Order(4);
    cout << endl;
    cout << "SUM is : " << sum(10);
    cout << endl;
    cout << "--------------Table-----------------\n";
    printTable(4,1);
    cout << "Factorial is : " << factorial(3) << endl;
    cout << "Fibonacci series is : " << fibonacci(5);
    cout << endl;
    if(isPrime(5)){
    	cout << "Prime\n";
	}
	else{
		cout << "Not a Prime\n";
	}
	if(isPrime(4)){
    	cout << "Prime\n";
	}
	else{
		cout << "Not a Prime\n";
	}
	if(isPrime(2)){
    	cout << "Prime\n";
	}
	else{
		cout << "Not a Prime\n";
	}
	if(isPrime(0)){
    	cout << "Prime\n";
	}
	else{
		cout << "Not a Prime\n";
	}
	if(isPrime(1)){
    	cout << "Prime\n";
	}
	else{
		cout << "Not a Prime\n";
	}
	
	 string arr[] = {"Hello", "world", "this", "is", "a", "test"};
    int length = sizeof(arr) / sizeof(arr[0]);   // fixed formula to calculate length of string
    reverseArray(arr, length);
    AllFactors(10);
    cout << endl;
    AllFactors(2);
    cout << endl;
    AllFactors(5);
    
    return 0;
}

