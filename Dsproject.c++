#include <iostream>
#include <queue>
using namespace std;

class Elevator {
    int curr_floor;
    int max_floor;
    queue<int> external_requests;
    queue<int> internal_requests;

public:
    Elevator(int floors) {
        curr_floor = 0;
        max_floor = floors;
    }

    void move_to_floor(int floor) {
        if (floor > curr_floor) {
            cout << "Moving up from " << curr_floor << " to " << floor << endl;
            for (int i = curr_floor + 1; i <= floor; i++) {
                cout << "Floor " << i << endl;
            }
        }
        else if (floor < curr_floor) {
            cout << "Moving down from " << curr_floor << " to " << floor << endl;
            for (int i = curr_floor - 1; i >= floor; i--) {
                cout << "Floor " << i << endl;
            }
        }
        else {
            cout << "Already at floor " << floor << endl;
        }
        curr_floor = floor;
    }

    void External_request() {
        int floor;
        cout << "Enter external request floors (separate floors with space): ";
        while (cin >> floor) {
            if (floor == -1) break;  // Stop if user enters -1
            if (floor >= 0 && floor <= max_floor) {
                external_requests.push(floor);
            }
            else {
                cout << "Invalid floor!" << endl;
            }

            char ch = cin.get();
            if (ch == '\n') break;  // Stop if Enter is pressed
        }
    }

    void Internal_requests() {
        cout << "Enter internal floors one by one (-1 to stop taking requests ): ";
        int floor;
        while (true) {
            cin >> floor;
            if (floor == -1) break;
            if (floor >= 0 && floor <= max_floor) {
                internal_requests.push(floor);
            }
            else {
                cout << "Invalid floor!" << endl;
            }
        }
    }

    void processRequests() {
        while (!external_requests.empty() || !internal_requests.empty()) {
            if (!external_requests.empty()) {
                int floor = external_requests.front();
                external_requests.pop();
                move_to_floor(floor);
                Internal_requests();
            }

            while (!internal_requests.empty()) {
                int floor = internal_requests.front();
                internal_requests.pop();
                move_to_floor(floor);
            }
        }
        cout << "No pending requests. Elevator stopped at floor " << curr_floor << endl;
    }
};