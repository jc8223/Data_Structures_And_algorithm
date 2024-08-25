#include <iostream>
using namespace std;

class Gun{
	public:
	int ammo;
	int damage;
	int scope;
}
class player{
	private:
		int id;
		string name;
		int score;
		Gun gun;

	public:
		player(int id, string name, int score){
			this->id = id;
			this->name = name;
			this->score = score;
		}
		int getID(){
			return id;
		}
		string getName(){
			return name;
		}
		int getScore(){
			return score;
		}
		void setID(int id){
			this->id = id;
		}
		void setName(string name){
			this->name = name;
		}
		void setScore(int score){
			this->score = score;
		}
		void print(){
			cout << "ID: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Score: " << score << endl;
		}
};

int main(){
	player Jatin(1, "Jatin", 100);
	Jatin.print();
	return 0;
}
