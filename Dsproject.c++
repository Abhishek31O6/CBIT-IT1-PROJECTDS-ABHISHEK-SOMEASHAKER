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