include <iostream>
#include <limits>
using namespace std;

#include "patient_list.h"
#include "appointment_queue.h"
#include "billing_stack.h"

void fixInput() {
    cin.clear(); 
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    PatientList pl;
    AppointmentSystem ap;
    BillingSystem bs;

    int choice;

    while (true) {

        cout << "\n\n====== HealthCareHub Menu ======\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient\n";
        cout << "3. Delete Patient\n";
        cout << "4. Show All Patients\n";
        cout << "5. Add Appointment\n";
        cout << "6. Process Appointment\n";
        cout << "7. Show All Appointments\n";
        cout << "8. Add Bill Entry\n";
        cout << "9. Undo Bill\n";
        cout << "10. Redo Bill\n";
        cout << "11. Show Bill Entries\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        // FIX : if wrong input, clear it.
        if(cin.fail()) {
            cout << "\nInvalid input! Please enter a number.\n";
            fixInput();
            continue;
        }

        if (choice == 1) {
    string name, disease, doctor;
    int age;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, disease);

    cout << "Enter Doctor: ";
    getline(cin, doctor);

    pl.addPatient(name, age, disease, doctor);
}

        

        else if (choice == 2) {
            string name;
            cout << "Enter Name to Search: ";
            cin >> name;
            pl.searchPatient(name);
        }

        else if (choice == 3) {
            string name;
            cout << "Enter Name to Delete: ";
            cin >> name;
            pl.deletePatient(name);
        }

        else if (choice == 4) {
            pl.displayPatients();
        }

        else if (choice == 5) {
    string p, d;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, p);

    cout << "Enter Doctor Name: ";
    getline(cin, d);

    ap.addAppointment(p, d);
}


        else if (choice == 6) {
            ap.processAppointment();
        }

        else if (choice == 7) {
            ap.showAppointments();
        }

        else if (choice == 8) {
            int amt;
            cout << "Enter Bill Amount: ";
            cin >> amt;

            if (cin.fail()) {   // amount invalid
                cout << "Invalid amount!\n";
                fixInput();
                continue;
            }

            bs.addBill(amt);
        }

        else if (choice == 9) {
            bs.undo();
        }

        else if (choice == 10) {
            bs.redo();
        }

        else if (choice == 11) {
            bs.showCurrentBill();
        }

        else if (choice == 12) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "\nInvalid choice, enter 1-12 only!\n";
        }
    }

    return 0;
}
