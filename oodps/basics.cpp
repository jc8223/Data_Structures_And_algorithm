#include <iostream>
#include <string>
using namespace std;

class book{
	private:
		int NoOfPages;
		int price;
		string name;

	public:
		void input(){
			cout<<"Enter the name of the book"<<endl;
			getline(cin,name);
			cout<<"Enter the price of the book"<<endl;
			cin>>price;
			cout<<"Enter the number of pages in the book"<<endl;
			cin>>NoOfPages;
		}
		void output(){
			cout<<"The name of the book is "<<name<<endl;
			cout<<"The price of the book is "<<price<<endl;
			cout<<"The number of pages in the book is "<<NoOfPages<<endl;
		}
		int countNoOfBooks( int p ){
			int count = 0;
			if( price == p ){
				count++;
			}
			return count;
		}
		bool isbookpresent( string n ){
			if( name == n ){
				return true;
			}
			return false;
		}
};

int main(){
	book b1;
	b1.input();
	b1.output();
	cout << b1.countNoOfBooks( 100 );
	cout << b1.isbookpresent( "Harry Potter" );
	return 0;
}