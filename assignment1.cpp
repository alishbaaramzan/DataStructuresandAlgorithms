#include <iostream>
using namespace std;

int timeComplexity(int n){
	int sum = 0;  	
    for(int i=1; i<n; i++ )  	
        for( int j=1; j<i*i; j++ )  	
            if( j%1 == 0 ) 
 	            for( int k=0; k<j; k++ )  	sum++; 

  return sum;
}
int main(){
    int arr_time[] = {10, 20, 30 ,40,50,60,70,80,90,100};
    for(int i = 0; i < sizeof(arr_time)/sizeof(arr_time[0]); i++){
        int result = timeComplexity(arr_time[i]);
        cout << "For the value " << arr_time[i] << " the loop ran for " << result << " times" << endl;
    }
    return 0;
}