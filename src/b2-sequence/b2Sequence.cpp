#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool is_b2_seq(vector<int> nums){
	int n = nums.size();
	
	int min = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(nums[i]<=min){
			return false;
		}
		
		min = nums[i];
	}
	
	bool seen[20001];
	memset(seen , false , sizeof(seen));
	for(int i = 0  ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			int sum = nums[i] + nums[j];
			
			if(seen[sum]){
				return false;
			}else{
				seen[sum] = true;
			}
			
		}
	}
	
	return true;

}


int main(){
	int n;	
	int count = 1;
	while(cin>>n){
		
		vector<int> nums(n);
		for(int i = 0 ; i < n; i++){
			cin>>nums[i];
		}
		
		bool result = is_b2_seq(nums);
		
		if(result){
			cout<<"Case #"<<count<<": It is a B2-Sequence."<<endl<<endl;
		}else{
			cout<<"Case #"<<count<<": It is not a B2-Sequence."<<endl<<endl;
		}
		
		count++;
	}
}
