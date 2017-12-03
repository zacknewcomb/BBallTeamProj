#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "player.h"
#include "statistic.h"

using namespace std;

void player::set_3pt(int attempts, int made) {
	lst_3pt[num_games_played].set_attempt(attempts);
	lst_3pt[num_games_played].set_made(made);


}
void player::set_2pt(int attempts, int made) {

	lst_2pt[num_games_played].set_attempt(attempts);
	lst_2pt[num_games_played].set_made(made);
}
void player::set_ft(int attempts, int made) {

	lst_ft[num_games_played].set_attempt(attempts);
	lst_ft[num_games_played].set_made(made);

}
void player::total_pts() {
	int total = 0;
	total = (lst_3pt[num_games_played].get_made() * 3) + (lst_2pt[num_games_played].get_made() * 2) + lst_ft[num_games_played].get_made();
	total_points = total;
}

string player::get_name() { return name; }
int player::get_num() { return jersey_num; }
int player::get_num_games_played() { return num_games_played; }
int player::get_3att() { return lst_3pt[num_games_played].get_attempts(); }
int player::get_3made() { return lst_3pt[num_games_played].get_made(); }
int player::get_2att() { return lst_2pt[num_games_played].get_attempts(); }
int player::get_2made() { return lst_2pt[num_games_played].get_made(); }
int player::get_ftatt() { return lst_ft[num_games_played].get_attempts(); }
int player::get_ftmade() { return lst_ft[num_games_played].get_made(); }
void player::set_num_games_played(int g) {
	num_games_played = g;
}
void player::set_name(string x) {
	name = x;
}
void player::set_jersey(int j) {
	jersey_num = j;
}
int player::get_calc_perc3(int a, int b) {
	return lst_3pt[num_games_played].calc_perc(a, b);
}
int player::get_calc_perc2(int c, int d) {
	return lst_2pt[num_games_played].calc_perc(c, d);

}
int player::get_calc_percft(int e, int f) {
	return lst_ft[num_games_played].calc_perc(e, f);
}
