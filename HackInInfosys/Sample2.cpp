/*
There is a battle between heroes and villains going on. You have M heroes, all of them have the same
health H. There are N villains, health of the ith villain is Vi. When a hero, with health H battles a 
villain with health Vi, one of the three scenarios can happen: if H > Vi: The villain is defeated and 
the health of the hero is decreased by Vi if H < Vi: The villain wins, his health is not affected and 
the hero is no longer able to fight. if H = Vi: Both of them are considered defeated and neither can 
fight. The heroes start fighting villains one by one in the same order, first villain 1 then villain 
2 and so on. It is might be possible that before defeating all the villains, all the heroes are 
defeated. Therefore, to ensure the victory of the heroes, you want to remove some villains from the 
front. Your task is to find the minimum number of villains you need to remove from the front such that
the victory of the heroes is guaranteed. 
Note: If in the last battle, both the hero and villain are 
defeated and no more heroes or villains remain, it would still be considered a victory since all the 
villains are defeated.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m, h;
	cin >> n >> m >> h;
	vector<int> villains(n);
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> villains[i];
		sum += villains[i];
	}
	sort(villains.begin(), villains.end());
	reverse(villains.begin(), villains.end());
	vector<int> heroes(m, h);
	int count = 0;
	int ptr = 0;
	for(int i=0; i<n; i++){
		if(villains[i] <= heroes[ptr]){
			heroes[ptr] -= villains[i];
		}
		
		else if (villains[i] > heroes[ptr]){
			count++;
		}
		
		else{
			ptr++;
			i--;
		}
		cout << endl;
		cout << "Villain: " << villains[i] << " Hero: " << heroes[ptr] << " Count: " << count << endl;
	}
	if(sum <= h*m){
		count = 0;
	}
	cout << count;
	return 0;
}
