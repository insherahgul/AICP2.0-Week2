#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MIN_PARTICIPANTS = 10;
const int MAX_PARTICIPANTS = 36;

struct Participant {
    string name;
    double amountPaid;
};

int main() {
    int numParticipants;
    int numCarers = 2; // Initial number of carers
    int numExtraParticipants;
    float extratotalCost;

    // Input validation loop
    do {
        cout << "Enter the number of interested senior citizens (between "
             << MIN_PARTICIPANTS << " and " << MAX_PARTICIPANTS << "): ";
        cin >> numParticipants;
        cin.ignore(); // Consume newline character
    } while (numParticipants < MIN_PARTICIPANTS || numParticipants > MAX_PARTICIPANTS);

    // Check if an additional carer is needed
    if (numParticipants > 24) {
        numCarers++; // Add an extra carer
    }

    // Determine the number of extra participants based on the total capacity
    int maxCapacity = MAX_PARTICIPANTS + numCarers;
    numExtraParticipants = maxCapacity - numParticipants;

    // Calculate total cost
    float coachCost, mealCost, ticketCost;
    if (numParticipants >= 10 && numParticipants <= 16) {
    	numExtraParticipants =16-numParticipants-3;
        coachCost = 150.00;
        mealCost = 14.00;
        ticketCost = 21.00;
    } else if (numParticipants >= 17 && numParticipants <= 26) {
    	numExtraParticipants =26-numParticipants-4;
        coachCost = 190.00;
        mealCost = 13.50;
        ticketCost = 20.00;
    } else {
    	numExtraParticipants =36-numParticipants-4;
        coachCost = 225.00;
        mealCost = 13.00;
        ticketCost = 19.00;
    }

    float totalCost = coachCost
                    + (numParticipants * mealCost)
                    + (numParticipants * ticketCost);

    // Calculate cost per senior citizen (excluding carers)
    float costPerParticipant = totalCost / numParticipants;

    // Output results
    cout << "\nTotal cost of the outing: $" << totalCost << endl;
    cout << "Cost per senior citizen: $" << costPerParticipant << endl;

    // Array to store participant details
    Participant participants[MAX_PARTICIPANTS + numCarers];

    // Prompt for participant details
    for (int i = 0; i < numParticipants; ++i) {
        cout << "\nEnter name of senior citizen " << i + 1 << ": ";
        getline(cin, participants[i].name);

        // Input validation loop for amount paid
        do {
            cout << "Enter amount paid by " << participants[i].name << ": $";
            cin >> participants[i].amountPaid;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline character

            // Check if the amount paid is less than cost per participant
            if (participants[i].amountPaid < costPerParticipant) {
                cout << "Invalid amount. Please enter an amount greater than or equal to $" << costPerParticipant << endl;
            }
        } while (participants[i].amountPaid < costPerParticipant);
    }

    // Prompt for carer details
    for (int i = 0; i < numCarers; ++i) {
        cout << "\nEnter name of carer " << i + 1 << ": ";
        getline(cin, participants[numParticipants + i].name);
        participants[numParticipants + i].amountPaid = 0; // Carers do not pay
    }
     
    if (numExtraParticipants>0) {
        cout << "\nThere are " << numExtraParticipants << " spare places on the coach.\n";

    // Prompt for additional participant details
    for (int i = numParticipants; i < numParticipants + numExtraParticipants; ++i) {
        cout << "\nEnter name of additional participant " << i + 1 << ": ";
        getline(cin, participants[i].name);

        // Input validation loop for amount paid
        do {
                cout << "Enter amount paid by " << participants[i].name << ": $";
                cin >> participants[i].amountPaid;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume newline character

                // Check if the amount paid is less than cost per participant
                if (participants[i].amountPaid < costPerParticipant) {
                    cout << "Invalid amount. Please enter an amount greater than or equal to $" << costPerParticipant << endl;
                }
            } while (participants[i].amountPaid < costPerParticipant);
    }

    // Print participant details
    cout << "\nParticipant details:\n";
      for (int i = 0; i < numParticipants+numExtraParticipants; ++i) {
        cout <<i<< ".  Name: " << participants[i].name << ", Amount Paid: $" << participants[i].amountPaid  << endl;
   	extratotalCost+=participants[i].amountPaid;
    }
    
        
        // Output updated results
        cout << "\nTotal cost of the outing after adding extra participants: $" << extratotalCost << endl;
    }
    float  break_even_point=(extratotalCost-totalCost);
    cout<<"The  Break_even_point Are :"<<break_even_point;

    return 0;
}

