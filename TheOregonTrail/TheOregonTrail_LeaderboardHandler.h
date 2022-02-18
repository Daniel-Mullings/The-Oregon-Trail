#ifndef LEADERBOARDHANDLER_H
#define LEADERBOARDHANDLER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <ctime>

#include "SQLite/sqlite3.h"


namespace Leaderboard_Handler 
{
	class LeaderboardDataEntry {
	private:
		int id;
		std::string username;
		std::string date;
		std::string time;
		int score;

		int setID();
		std::string setUsername(bool setUsername_p, int invalidUsernameCounter = 0);
		std::string setDate();
		std::string setTime();

		std::string formatDateTime(int dayOrhour_p, int monthOrminute_p, int yearOrsecond_p, int formatCode_p);
	public:
		LeaderboardDataEntry(int userScore_p = 0, bool setUsername_p = false);

		int getID();
		std::string getUsername();
		std::string getDate();
		std::string getTime();
		int getScore();
	};

	int callback(void* NotUsed, int argc, char** argv, char** azColName);
	void leaderboardDatabaseController(bool scoreSave = false, bool scoreLoad = false, LeaderboardDataEntry playerData = LeaderboardDataEntry(0));
	void leaderboardDataInput(int userScore_p = 0);
	void leaderboardDataOutput();

	std::string formatLeaderboardRecord(std::string rank_p, std::string player_p, std::string date_p, std::string time_p, std::string score_p);
	std::string formatLeaderboardField(std::string fieldEntry_p, int fieldWidth_p);
}
#endif //!LEADERBOARDHANDLER_H