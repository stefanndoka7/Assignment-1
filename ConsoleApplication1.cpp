// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string songName;    //declaring variables, seperated by whether they are input or output
    double bpm;
    double minutes;
    double seconds;

	double totalBeats;
	double lengthofOneBeat;


    cout << "Hello! What was the name of the last song you listened to?\n";
    cin >> songName;


    cout << "What's its bpm?\n";
    cin >> bpm;


    cout << "Enter how many minutes long it is, and then seconds\n";
    cin >> minutes >> seconds;


	double songlengthInSeconds = (minutes * 60) + seconds;     //calculate total song length in seconds for the total of beats in the song
    totalBeats = (bpm / 60) * songlengthInSeconds;  


	lengthofOneBeat = 60 / bpm;     //calculate length of seconds in one beat, a far more useful metric than how many minutes in one beat
    

    cout << songName << " is " << minutes << ":" << seconds << " long, and has a bpm of " << bpm << "." << "\n";
    cout << "Additionally, " << songName << " has " << totalBeats << " total beats, and every beat is " << lengthofOneBeat << " seconds long.";
}


