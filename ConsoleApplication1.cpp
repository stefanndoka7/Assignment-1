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

	double songlengthInSeconds;
    double totalBeats;
    double lengthofOneBeat;

	int choice;


    cout << "Hello! What was the name of the last song you listened to?\n";
    (cin >> songName);


    cout << "What's its bpm?\n";
    if (!(cin >> bpm) || (bpm <= 0))      //input validation for bpm
    {
        cout << "User input was invalid. Please restart the program and enter a valid input." << endl;
        return -1;
    }
    
    cout << "Enter how many minutes long it is, and then the remaining seconds\n";
    if (!(cin >> minutes >> seconds) || (seconds >= 60 || seconds < 0 || minutes < 0))
        
    {
        cout << "User input was invalid. Please restart the program and enter a valid input." << endl;
        return -1;
    }

    songlengthInSeconds = (minutes * 60) + seconds;     //calculate total song length in seconds for the total of beats in the song
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
	
	cout << "\n" << "----EDITING MENU----" << endl;
	cout << "1) edit song name" << endl;
	cout << "2) edit bpm" << endl;
	cout << "3) edit song length" << endl;
	cout << "4) exit program" << endl;
    
	cin >> choice;

	switch (choice) {           // I know this looks bad, we have not covered loops or functions yet. I just needed to display that I understand switch statements.
        case 1:
        cout << "\n" << "Enter new song name: " << endl;
        cin >> songName;

        cout << "Song Name:" << setw(50) << songName << setprecision(0) << fixed << "\n";
        cout << "Minutes in Song:" << setw(44) << minutes << "\n";
        cout << "Seconds in Song:" << setw(44) << seconds << "\n";
        cout << "BPM:" << setw(56) << bpm << "\n";
        cout << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";
        cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";

		break;
        
        case 2:
        cout << "\n" << "Enter new bpm: " << endl;
		cin >> bpm;

        songlengthInSeconds = (minutes * 60) + seconds;
		totalBeats = (bpm / 60) * songlengthInSeconds;

		lengthofOneBeat = static_cast<double>(60) / bpm;

        cout << "Song Name:" << setw(50) << setprecision(0) << fixed << songName << "\n";
        cout << "Minutes in Song:" << setw(44) << minutes << "\n";
        cout << "Seconds in Song:" << setw(44) << seconds << "\n";
        cout << "BPM:" << setw(56) << bpm << "\n";
        cout << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";
        cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";

        break;
        
        case 3:
			cout << "\n" << "Enter new song length (minutes and seconds): " << endl;
			cin >> minutes >> seconds;

			songlengthInSeconds = (minutes * 60) + seconds;
			totalBeats = (bpm / 60) * songlengthInSeconds;
            
            cout << "Song Name:" << setw(50) << setprecision(0) << fixed << songName << "\n";
            cout << "Minutes in Song:" << setw(44) << minutes << "\n";
            cout << "Seconds in Song:" << setw(44) << seconds << "\n";
            cout << "BPM:" << setw(56) << bpm << "\n";
            cout << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";
            cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";

            break;

		case 4:
			cout << "Exiting program." << endl;
			break;
        
        default:
        cout << "Invalid choice. Exiting program." << endl;
        return -1;
    }

	return 0;
		
    



   
}