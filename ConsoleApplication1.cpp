#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

const string OUTFILENAME = "report.txt";
const int VARIGNORE = 100000;

int main()
{
    string songName;    //declaring variables, seperated by whether they are input or output
    double bpm{};
    double minutes{};
    double seconds{};

    double songlengthInSeconds{};
    double totalBeats{};
    double lengthofOneBeat{};

    int choice{};
    int sentinel = 0;   
    
    cout << "Hello! What was the name of the last song you listened to?\n";
    cin >> (songName);


    cout << "What's its bpm?\n";
    while (true) {
        if (!(cin >> bpm) || (bpm <= 0))      //input validation for bpm
        {
            cout << "User input was invalid. Please try enter a valid input (any number above 0)." << endl;
			cin.clear();
			cin.ignore(VARIGNORE, '\n');
        }
        else
            break;
    }
   cout << "Enter how many minutes long it is, and then the remaining seconds\n";

   while (true) {
       if (!(cin >> minutes >> seconds) || (seconds >= 60 || seconds < 0 || minutes < 0))

       {
           cout << "User input was invalid. Please try entering a valid input" << "\n";
           cout << "(minutes can be any whole number, and seconds can be any whole number thats less than 60)" << endl;
           cin.clear();
           cin.ignore(VARIGNORE, '\n');
       }
       else
           break;
   }

    songlengthInSeconds = (minutes * 60) + seconds;     
    totalBeats = (bpm / 60) * songlengthInSeconds;


    lengthofOneBeat = (60) / bpm;     

	ofstream outFile;      
	outFile.open(OUTFILENAME);


    cout << "Song Name:" << setw(50) << songName << "\n";       
	outFile << "Song Name:" << setw(50) << songName << "\n";

    cout << "Minutes in Song:" << setw(44) << minutes << "\n";
	outFile << "Minutes in Song:" << setw(44) << minutes << "\n";

    cout << "Seconds in Song:" << setw(44) << seconds << "\n";
	outFile << "Seconds in Song:" << setw(44) << seconds << "\n";

    cout << "BPM:" << setw(56) << bpm << "\n";
	outFile << "BPM:" << setw(56) << bpm << "\n";

    cout << "Total Beats in Song:" << setw(40) << setprecision(2) << fixed << totalBeats << "\n";
	outFile << "Total Beats in Song:" << setw(40) << setprecision(2) << totalBeats << fixed << "\n";

    cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";
	outFile << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";


    outFile.close();   
	do
    {
        cout << "\n" << "----EDITING MENU----" << endl;
        cout << "1) edit song name" << endl;
        cout << "2) edit bpm" << endl;
        cout << "3) edit song length" << endl;
		cout << "4) display output" << endl;
        cout << "5) exit program" << endl;
        for (int line = 60; line > 0; line--)       //makes a line
        {
            cout << ".";
        }
        cout << "\n";

        cin >> choice;

        switch (choice) {           
        case 1:
            cout << "\n" << "Enter new song name: " << endl;
            cin >> (songName);

			cout << "\n" << "The song name has been updated to: " << songName << "\n";

            break;

        case 2:
            cout << "\n" << "Enter new bpm: " << endl;
            while (true) {
                if (!(cin >> bpm) || (bpm <= 0))      //input validation for bpm
                {
                    cout << "User input was invalid. Please try enter a valid input (any number above 0)." << endl;
                    cin.clear();
                    cin.ignore(VARIGNORE, '\n');
                }
                else
                    break;
            }

            songlengthInSeconds = (minutes * 60) + seconds;
            totalBeats = (bpm / 60) * songlengthInSeconds;

            lengthofOneBeat = (60) / bpm;

			cout << "The bpm has been updated to: " << setprecision(0) << fixed << bpm << "BPM" << "\n";

            break;

        case 3:
            cout << "\n" << "Enter new song length (minutes and seconds): " << endl;
            while (true) {
                if (!(cin >> minutes >> seconds) || (seconds >= 60 || seconds < 0 || minutes < 0))

                {
                    cout << "User input was invalid. Please try entering a valid input" << "\n";
                    cout << "(minutes can be any whole number, and seconds can be any whole number thats less than 60)" << endl;
                    cin.clear();
                    cin.ignore(VARIGNORE, '\n');
                }
                else
                    break;
            }

            songlengthInSeconds = (minutes * 60) + seconds;
            totalBeats = (bpm / 60) * songlengthInSeconds;


			cout << "\n" << "The song length has been updated to: " << setprecision(0) << fixed << minutes << " minutes and " << seconds << " seconds.\n";

            break;

        case 4:
            cout << "\n" << "----CURRENT SONG INFORMATION----" << endl;
            cout << "Song Name:" << setw(50) << songName << "\n";
            cout << "Minutes in Song:" << setw(44) << setprecision(0) << fixed << minutes << "\n";
            cout << "Seconds in Song:" << setw(44) << seconds << "\n";
            cout << "BPM:" << setw(56) << bpm << "\n";
            cout << "Total Beats in Song:" << setw(40) << setprecision(2) << totalBeats << "\n";
            cout << "Length of One Beat (in seconds):" << setw(28) << setprecision(4) << lengthofOneBeat << "\n";
			for(int line = 60; line > 0; line--) 
                {
                cout << ".";
			}
			break;

        case 5:
            cout << "\n" << "Exiting program." << endl;
			sentinel = 1;
            break;

        default:
            cout << "\n" << "Invalid choice. Exiting program." << endl;
            return -1;
        } 

    } while (sentinel == 0);
    
    return 0;

} 