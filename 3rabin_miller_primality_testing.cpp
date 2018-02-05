/* Rabin Miller Primality Testing 
 * Author : Mahesh Shakya
 * Date: February 5th, 2018
 * mahesh@gces.edu.np
*/
#include <iostream>
#include <random>
using namespace std;

int main(){

	unsigned long long num;
	cout<<"Enter a number(Primality Test):";
	cin>>num;
	if( num % 2 == 0) {
		cout<<num<<" is even.";
		exit(0);
	}

	/* We know num is odd, so n - 1 is even. i.e n - 1 = 2^t . s 
	 * generate alpha in Z(num)
	 * repeatedly square alpha ^ s , for t times
	 * if the last element in this sequence is not 1,then n is surely composite.
	 * if the first element of the sequence is 1, we declare  n to be prime.
	 * if s_alpha(k) = 1 and s_alpha(k - 1) is not -1, then we found
	 *			non-trivial square root of 1
	 * if s_alpha(k) = 1 and s_alpha(k - 1) is -1, we cannot be sure
	*/

	//c++ 11 random number generator
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type>
     distnum(2,num - 2); // distribution in range [2, num - 2]

    //generate alpha in Z(num)
    unsigned long long alpha = distnum(rng);
    unsigned long long num_minus_1 = num - 1;
    unsigned long long s = 0;
    unsigned long long t = 0;
    unsigned long long alpha_s_k;
    unsigned long long alpha_s_k_minus_1;
    /* find t and s such that n - 1 = 2^t . s  */
    unsigned long long x = num_minus_1;
    while(x % 2 == 0){
    	x /= 2;
    	t++;
    }
    s = x;
    cout<<"DEBUG: "<<num_minus_1<<" = 2 power"<<t<<" . "<<s<<endl;

	unsigned long long alpha_s = 1;
	for(int i = 0; i < s; i++){
		alpha_s = alpha_s * alpha % num;
		// cout<<"alpha:"<<alpha<<" alpha squared:"<<alpha_s<<endl;
	}	//alpha_s generated
	cout<<"DEBUG: "<<" alpha:"<<alpha<<" alpha_s:"<<alpha_s<<endl;
	if(alpha_s == 1 ) {
		cout<<num<<" is prime."<<endl; 
		exit(0);
	}
	
	// repeatedly square alpha ^ s , for t times
	alpha_s_k = alpha_s;
	unsigned long long i = 1;
	do{
		alpha_s_k_minus_1 = alpha_s_k;
		alpha_s_k = alpha_s_k * alpha_s % num;
		//if s_alpha(k) = 1 and s_alpha(k - 1) is not -1
		if(alpha_s_k == 1 && alpha_s_k_minus_1 != num_minus_1) {
			cout<<num<<" is composite";
			exit(0);
		}
		i++;
	}while(i < t);

	if(alpha_s_k != 1) {
		cout<<num<<" is composite."<<endl;
		exit(0);
	}

	cout<<num<<" is probably prime.";

	return 0;
}