#include <iostream>
#include <cstring>

using namespace std;

int main(){

	int n;
	while(cin>>n){
		if(n == 0){
			return 0;
		}
	
		int matrix[n][n];
		int count[2][n];
		
		memset(count , 0 , sizeof(count));
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> matrix[i][j];
				count[0][i] = count[0][i] + matrix[i][j];
				count[1][j] = count[1][j] + matrix[i][j];
			}
		}
		
		
		int odd_r = -1;
		int odd_c = -1;
		bool result = false;
		
		for(int i = 0 ; i < n ; i++){
			if(count[0][i]%2 == 1){
				if(odd_r != -1){
					result = true;
					break;
				}
				odd_r = i+1;
			}
			
			if(count[1][i]%2 == 1){
				if(odd_c != -1){
					result = true;
					break;
				}
				odd_c = i+1;
			}
		}
		
		if(result){
			cout<<"Corrupt"<<endl;
		}
		else if(odd_r == -1 && odd_c == -1){
			cout<<"OK"<<endl;
		}else if(odd_r != -1 && odd_c != -1){
			cout<<"Change bit ("<<odd_r<<","<<odd_c<<")"<<endl;
		}else{
			cout<<"Corrupt"<<endl;
		}
	}
	
	return 0;
}