/* Rod cutting - Dynamic Programming */
/* 
 * length i -	1	2	3	4	5	6	7	8	9	10
 * price pi -	1	5	8	9	10	17	17	20	24	30
 *
 */
 #include <iostream>

using namespace std;

struct rod{
	unsigned length, price;
};
unsigned count = 0;
struct rod set[10] = {{1,1},{2,5},{3,8},{4,9},{5,10},
						{6,17},{7,17},{8,20},{9,24},{10,30}};
unsigned recursive_soln(unsigned n){
if(n == 0)
	return 0;
unsigned q = 0;
	for(int i = 0; i < n; i++){
		unsigned temp =  recursive_soln(n - i - 1 );
		q = (set[i].price + temp > q )?(set[i].price + temp ):q;
		count++;
	}
return q;
}
int main(){
	for(int i = 1; i <= 10; i++){
		cout<<"Maximal profit:"<<recursive_soln(i)<<endl;
		cout<<"Basic operation count:"<< count<<endl;
	}
	return 0;
}