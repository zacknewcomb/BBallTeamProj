#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "statistic.h"
using namespace std;

class player{
public:
	void set_3pt(int attempts, int made);
	void set_2pt(int attempts, int made);
	void set_ft(int attempts, int made);
	void total_pts();
	string get_name();
	int get_num();
	int get_num_games_played();
	int get_3att();
	int get_3made();
	int get_2att();
	int get_2made();
	int get_ftatt();
	int get_ftmade();
	void set_num_games_played(int g);
	void set_name(string x);
	void set_jersey(int j);
	int get_calc_perc3(int a, int b);
	int get_calc_perc2(int c, int d);
	int get_calc_percft(int e, int f);

private:
	string name = "";
	int jersey_num = 0;
	int num_games_played = 0;
	int total_points = 0;
	astat lst_3pt[15];
	astat lst_2pt[15];
	astat lst_ft[15];

};
