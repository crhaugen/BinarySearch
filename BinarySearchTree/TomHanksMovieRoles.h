#pragma once
// Author: Chyanne Haugen
//Definition and Declaration of the TomHanksMovieRoles class

#include <string>

using namespace std;

class TomHanksMovieRoles
{
private:

	string movieTitle;
	int yearReleased;
	string role;

public:
	TomHanksMovieRoles() : movieTitle(""), yearReleased(0), role("")
	{

	}

	TomHanksMovieRoles(string movieTitle, int yearReleased, string role) : movieTitle(movieTitle), yearReleased(yearReleased), role(role)
	{

	}

	//accessors
	string getMovieTitle() const
	{
		return movieTitle;
	}

	int getYearReleased() const
	{
		return yearReleased;
	}

	string getRole() const
	{
		return role;
	}

	//mutators
	void setMovieTitle(string movieTitle)
	{
		this->movieTitle = movieTitle;
	}

	void setYearReleased(int yearReleased)
	{
		this->yearReleased = yearReleased;
	}

	void setRole(string role)
	{
		this->role = role;
	}

	//function that overloads << method with cout
	friend istream& operator >>(istream& inStream, TomHanksMovieRoles &tomHanksRole)
	{
		string inputLine;
		const char tab(9);

		getline(inStream, inputLine, tab);

		if (!inStream.eof()) //taking data from the file stream and making tomHanksMovieRoles objects
		{
			tomHanksRole.setMovieTitle(inputLine);
			getline(inStream, inputLine, tab);
			tomHanksRole.setYearReleased(stoi(inputLine));
			getline(inStream, inputLine);
			tomHanksRole.setRole(inputLine);
		}

		return(inStream);
	}

	//function that overloads << method with cout
	friend ostream& operator <<(ostream& outStream, const TomHanksMovieRoles &tomHanksRole)
	{
		outStream << tomHanksRole.movieTitle << " " << tomHanksRole.yearReleased << " " << tomHanksRole.role << endl;

		return(outStream);
	}

};