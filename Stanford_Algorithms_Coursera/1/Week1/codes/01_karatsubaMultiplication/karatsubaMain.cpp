#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


//Function for Getting Count of Digits of the number 
int GetSize(long num)
{
	int len = 0;
	
	while(num != 0)
	{
		len++;
		num = num/10;
		
	}
	
	return len;
}


int main()
 {
 	long inputA=-1;
 	long inputB = -1;
 	int sizeA = -1;
 	int sizeB = -1;
 	cout<<"Enter first num: ";
 	cin>>inputA;
 	cout<<"Enter second num: ";
 	cin>>inputB;
 	cout<<endl;
 	
 	auto start = high_resolution_clock::now();
 	
 	//Digit num
 	int N = 0;
 	int N_1 = 0;
 	
 	int size1 = GetSize(inputA);
 	int size2 = GetSize(inputB);
 	if(size1>size2)
 	{
 	  N = size1;
	  N_1 = size1;	
	}
	else
	{
		N = size2;
		N_1 = size2;
	}
	
	if(N<2)
	{
		cout<<"RESULT: "<<inputA*inputB<<endl;
		return 0;
	}
	
	N = (N/2) + (N%2);
	long t = pow(10,N);
	long a = inputA/t;
	long b = inputA%t;
	long c = inputB/t;
	long d = inputB%t;
	
	//step1
	long num1 = a * c;
	//step 2
	long num2 = b * d;
	//step 3
	long tempNum = (a+b) * (c+d);
	//step4
	long num3 = tempNum - num1 - num2;
	
	
	long result = (pow(10,N_1)*num1) + (pow(10,N)*num3) + num2;
	
	cout<<"KARATSUBA Result: "<< result <<endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"KARATSUBA Processing Time: "<< duration.count() << " microseconds" <<endl;
	
	auto start1 = high_resolution_clock::now();
 	cout<<"NORMAL Multiplication Result: "<< inputA * inputB <<endl;
 	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout<<"Normal Multiplication Processing Time: "<< duration1.count() << " microseconds" <<endl;
	
    
 	
 	return 0;
 }