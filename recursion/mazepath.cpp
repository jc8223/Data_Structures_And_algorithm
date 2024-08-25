#include<iostream>
using  namespace std;

int mazepath(int sr,int sc, int er,int ec){
	if(sr==er && sc==ec) return 1;
	if(sr>er || sc > ec) return 0 ;
	int rightWays = mazepath(sr,sc+1,er,ec);
	int DownWays = mazepath(sr+1,sc,er,ec);
	return rightWays+DownWays;
}

int mazepath2(int er,int ec){
	if(er==1 && ec==1) return 1;
	if(1>er || 1 > ec) return 0 ;
	int rightWays = mazepath2(er,ec-1);
	int DownWays = mazepath2(er-1,ec);
	return rightWays+DownWays;
}

void printpath(int sr,int sc, int er,int ec,string s){
	if(sr==er && sc==ec) {
		cout << s << endl; 
		return;
	}
	if(sr>er || sc > ec) return;
	printpath(sr,sc+1,er,ec,s+'R');
	printpath(sr+1,sc,er,ec,s+'D');
	return;
}

int main(){
	cout << mazepath2(3,7) << " Ways"<< endl;
}