#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "player.h"
#include "statistic.h"
#include "team.h"

using namespace std;

void team::print() {
	cout << "Number of Games: " << games_played << " Number of Players: " << players << "\n";
	for (int i = 0; i < players; i++) {
		p[i].print();
	}
	cout << "\n";
}
void team::addGame() {
	if (games_played < 15) {
		for (int i = 0; i < players; i++) {
			int curr_game = p[i].get_num_games_played();
			p[i].set_num_games_played(curr_game + 1);
			string n1 = p[i].get_name();
			int n2 = p[i].get_num();
			int made3, attempt3, made2, attempt2, madeft, attemptft;
			cout << n1 << " [" << n2 << "]\n";
			cout << "3 Pointers (made attempted): ";
			cin >> made3 >> attempt3;
			p[i].set_3pt(attempt3, made3);
			cout << "2 Pointers (made attempted): ";
			cin >> made2 >> attempt2;
			p[i].set_2pt(attempt2, made2);
			cout << "Free throws (made attempted): ";
			cin >> madeft >> attemptft;
			p[i].set_ft(attemptft, madeft);


		}
		games_played++;
	}
	else
		cout << "Max Games already entered";
}
void team::sortByJersey() {
	cout << "PLayers Sorted by Jersey\n";
	for (int i = 0; i < players - 1; i++) {
		for (int j = i + 1; j < players; j++) {
			int j1 = p[i].get_num();
			int j2 = p[j].get_num();
			if (j1 > j2) {
				player t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	;
}
void team::sortByName() {
	cout << "PLayers Sorted by Name\n";
	for (int i = 0; i < players - 1; i++) {
		for (int j = i + 1; j < players; j++) {
			string n1 = p[i].get_name();
			string n2 = p[j].get_name();
			if (n1 > n2) {
				player t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
}
void team::removePlayer() {
	cout << "Enter player jersey number: ";
	int jerseyNum;
	cin >> jerseyNum;
	int foundPlayer = -1;
	for (int i = 0; i < players; i++) {
		if (p[i].get_num() == jerseyNum)
			foundPlayer = i;
	}
	if (foundPlayer != -1) {
		cout << p[foundPlayer].get_name() << " [" << p[foundPlayer].get_num() << "] removed" << endl;
		for (int i = foundPlayer; i <= players - 1; i++)
			p[i] = p[i + 1];
		players--;
	}
	else {
		cout << "Player not found" << endl;
	}
	
}
void team::displayPlayer() {
	bool found = false;
	int r;
	cout << "Enter player jersey number: ";
	cin >> r;
	for (int i = 0; i < players; i++) {
		int q = p[i].get_num();
		string q2 = p[i].get_name();
		if (q == r)
			p[i].print();
		


	}if (found == false)
		cout << "Player Not Found\n";
}

void team::read() {
	ifstream f;
	int in_num;
	string in_name;
	int in_3a, in_3m, in_2a, in_2m, in_fta, in_ftm;
	f.open("bballin.txt");
	if (!f.fail()) {
		f >> players;
		f >> games_played;
		for (int i = 0; i < players; i++) {
			f >> in_num; p[i].set_jersey(in_num);
			//f >> in_name;
			f.ignore();
			getline(f, in_name);
			p[i].set_name(in_name);
			for (int j = 0; j < games_played; j++) {
				p[i].set_num_games_played(j);
				f >> in_3m; f >> in_3a;
				f >> in_2m; f >> in_2a;
				f >> in_ftm; f >> in_fta;
				p[i].set_3pt(in_3a, in_3m);
				p[i].set_2pt(in_2a, in_2m);
				p[i].set_ft(in_fta, in_ftm);
			}

		}
	}
}
void team::write() {
	ofstream f;
	string name_out;
	int out_3a, out_3m, out_2a, out_2m, out_fta, out_ftm, jersey_out;
	f.open("bballout.txt");
	if (!f.fail()) {
		f << players << " ";
		f << games_played << " \n";
		for (int i = 0; i < players; i++) {
			name_out = p[i].get_name();
			jersey_out = p[i].get_num();
			f << jersey_out << " " << name_out << endl;
			for (int j = 0; j < games_played; j++) {
				p[i].set_num_games_played(j);
				out_3a = p[i].get_3att();
				out_3m = p[i].get_3made();
				out_2a = p[i].get_2att();
				out_2m = p[i].get_2made();
				out_fta = p[i].get_ftatt();
				out_ftm = p[i].get_ftmade();
				f << out_3a << " " << out_3m << " ";
				f << out_2a << " " << out_3m << " ";
				f << out_fta << " " << out_ftm << endl;

			}

		}
	}
}
