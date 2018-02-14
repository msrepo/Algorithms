/* Longest common subsequence */
/*
 * X = <A , B, C, B, D, A, B>
 * Y = <B,  D, C, A, B, A>
 */

#include <iostream>
using namespace std;

unsigned count;

void printArray(char * vec, unsigned size);
unsigned lcsn(char M[],int ms, char N[],int ns);


int main(){
	char X[] = {'A','B','C','B','D','A','B'};
	char Y[] = {'B','D','C','A','B','A'};

	// char X[] = {'A','B','C'};
	// char Y[] = {'B','D','C'};
	cout<<"Sequence X:"<<endl;
	// printVector(X);
	printArray(X,sizeof(X));

	cout<<"Sequence Y:"<<endl;
	// printVector(Y);
	printArray(Y,sizeof(Y));
	for(int i = 0; i < sizeof(Y); i++){
		count = 0;
		cout<<"Longest Common Subsequence Size:"<<lcsn(X + i,sizeof(X) - i,Y + i,sizeof(Y) - i)<<endl;
		cout<<"Basic Operation Count:"<<count<<endl;
	}
	return 0;
}

unsigned lcsn(char M[],int msize,
 char N[], int nsize){
 	
 	unsigned subsoln1 = 0, subsoln2 = 0;

	if(msize == 0 || nsize == 0)
		return 0;

	 if(M[0] == N[0]){
	 	count++;
	 	// cout<<"Match Found at the start of "<<endl;
	 	// printArray(M,msize); printArray(N,nsize);
	 	return 1 + lcsn(M + 1, msize - 1, N + 1, nsize - 1);
	 }else{
	 	if(msize > 1){
	 		subsoln1 = lcsn(M+1, msize - 1, N,nsize);
	 	
	 		// cout<<"Subsolution for "<<endl;
	 		// printArray(M+1,msize - 1); printArray(N,nsize);
	 		// cout<<"is "<<subsoln1<<endl;
	 	}

	 	if(nsize > 1){
	 		subsoln2 = lcsn(M,msize, N + 1, nsize - 1);
			// cout<<"Subsolution for "<<endl;
	 		// printArray(M,msize); printArray(N+1,nsize - 1);
	 		// cout<<"is "<<subsoln2<<endl;
	 	}
	 	count++;
	 	return subsoln1 > subsoln2 ? subsoln1 : subsoln2;
	 }

}

void printArray(char * vec,unsigned size){
	for(int i = 0; i < size; i++)
		cout<<'\t'<<vec[i];
	cout<<endl;
}
