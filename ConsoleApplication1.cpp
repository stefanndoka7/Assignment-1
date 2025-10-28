

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const string OUTFILENAME = "report.txt";

int main()
{
    string songName;    //declaring variables, seperated by whether they are input or output
    int bpm;
    double minutes;
    double seconds;

    double totalBeats;
    double lengthofOneBeat;


    cout << "Hello! What was the name of the last song you listened to?\n";
    (cin >> songName);


    cout << "What's its bpm?\n";
    if (!(cin >> bpm))      //input validation for bpm
    {
        cout << "User input was invalid. Please restart the program and enter a valid input." << endl;
        return -1;
    }
    
    cout << "Enter how many minutes long it is, and then seconds\n";
    if (!(cin >> minutes >> seconds))    //input validation for minutes and seconds
    {
        cout << "User input was invalid. Please restart the program and enter a valid input." << endl;
        return -1;
    }

    double songlengthInSeconds = (minutes * 60) + seconds;     //calculate total song length in seconds for the total of beats in the song
    totalBeats = (bpm / 60) * songlengthInSeconds;


    lengthofOneBeat = static_cast<double>(60) / bpm;     //calculate length of seconds in one beat, a far more useful metric than how many minutes in one beat

	ofstream outFile;      
	outFile.open(OUTFILENAME);

    
    cout << "Song Name:" << setw(50) << songName << "\n";       //output all the information in a nice format
	outFile << "Song Name:" << setw(50) << songName << "\n";

    cout << "Minutes in Song:" << setw(44) << minutes << "\n";
	outFile << "Minutes in Song:" << setw(44) << minutes << "\n";

    cout << "Seconds in Song:" << setw(44) << seconds << "\n";
	outFile << "Seconds in Song:" << setw(44) << seconds << "\n";

    cout << "BPM:" << setw(56) << bpm << "\n";
	outFile << "BPM:" << setw(56) << bpm << "\n";

    cout << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";
	outFile << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";

    cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";
	outFile << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";

    outFile.close();    //close the output file
	
}