#include <iostream>
#include <fstream> // Included so you can store data for future reference
#include "menu.hpp"
#include "event.hpp"

using namespace std; // This is a basic program, bugger off

/*
TODO:
-Seasonal events, i.e. holidays etc. that are automatic
-Information for each event: Time, end time, day of the week (multiple allowed), all day event or not, description, where, transportation? Make sure that depending on like, all day or not, it doesn't ask certain questions like time b/c it doesn't need to
-Edits event option: choose which part of the information you want to change
-For new event, seperate variables for each part, make sure to have titles for all of them, then you can ask which part you want to edit (Make sure that you don't have any variables that you can ask for that you don't need, i.e. time if it's all day)
-When checking schedule or something, set the data values in the check schedule function by reading the text file.
*/

int main()
{
    // Variables
    int menuChoice;       // Input for which option you want
    bool menuChoiceError; // If you input something that's not allowed, this is true

    // Display
    cout << endl
         << "Activity Tracker" << endl
         << endl;
    menu();

    do
    {
        // Asks for which option you want to do
        cout << "Which option do you want to do? Input a number:" << endl;
        cin >> menuChoice;
        cout << endl;

        // Switch that determines what happens based on your input
        switch (menuChoice)
        {
        // Checks schedule
        case 1:
            checkSchedule();
            break;

        // New event
        case 2:
            newEvent();
            break;

        // Edits event
        case 3:
            editEvent();
            break;

        // Deletes event
        case 4:
            deleteEvent();
            break;

        // Exits program
        case 9:
            cout << "Exiting program..." << endl
                 << endl;
            break;

        // Error if something that's not an option is input
        default:
            cout << "What you just did was create an error, try again." << endl
                 << endl;
            menuChoiceError = true;
            break;
        }

        // Ifs to change based on if menuChoice is an error, check above switch defualt
        if (menuChoice != 9 && menuChoiceError == false)
        {
            // Displays menu again
            cout << "Action complete! What's next?" << endl
                 << endl;
            menu();
        }
        else if (menuChoice != 9 && menuChoiceError == true)
        {
            // Displays menu again, and sets menuChoiceError to false so you can input an error later
            menu();
            menuChoiceError = false;
        }
    } while (menuChoice != 9);

    return 0;
}

void menu()
{
    cout << "Menu:" << endl
         << "1) Check schedule" << endl
         << "2) New event" << endl
         << "3) Edit an event" << endl
         << "9) Exit program" << endl
         << endl;
}

void checkSchedule()
{
}

/*
TODO:
-Write all this data to text file
*/
void newEvent()
{
    Event newEvent;

    // Asks for name
    cout << "What is your event called?" << endl;
    newEvent.setName();
    // Asks for all day
    cout << "Is your event all day? (0 for false, 1 for true)" << endl;
    newEvent.setAllDay();
    // If all day is true, doesn't ask, but if not, asks for time. Or ask for military time then add a ":"
    if (newEvent.eventAllDay == false)
    {
        cout << "What time is the event at?" << endl;
        newEvent.setTime();
    }
}

void editEvent()
{
}

void deleteEvent()
{
}