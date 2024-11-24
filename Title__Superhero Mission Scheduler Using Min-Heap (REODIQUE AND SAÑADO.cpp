//Title:
//Superhero Mission Scheduler Using Min-Heap
//Submitted by: Reodique Curt Justin N. and Sañado Faith Ann S.

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

// Function to heapify up (after insertion)
void heapifyUp(vector<pair<string, int>>& heap, int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index].second < heap[parentIndex].second) {
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

// Function to heapify down (after deletion)
void heapifyDown(vector<pair<string, int>>& heap, int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;

    if (leftChildIndex < heap.size() && heap[leftChildIndex].second < heap[smallestIndex].second) {
        smallestIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex].second < heap[smallestIndex].second) {
        smallestIndex = rightChildIndex;
    }

    if (smallestIndex != index) {
        swap(heap[index], heap[smallestIndex]);
        heapifyDown(heap, smallestIndex);
    }
}

// Function to insert a new superhero mission
void insertMission(vector<pair<string, int>>& heap, const string& missionName, int priority) {
    heap.push_back({missionName, priority});
    cout << "Adding mission '" << missionName << "' with priority " << priority << " to the Min-Heap!"<<endl << endl;
    heapifyUp(heap, heap.size() - 1);
}

// Function to delete the highest priority mission (root)
void deleteMission(vector<pair<string, int>>& heap) {
    if (heap.empty()) {
        cout << "No missions to delete!" << endl;
        return;
    }
    cout << "Deleting mission '" << heap[0].first << "' (highest priority) from the Min-Heap!" << endl;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(heap, 0);
}

// Function to build a Min-Heap from an array
void heapifyArray(vector<pair<string, int>>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        heapifyDown(arr, i);
    }
}


// Function to print the heap (for visualization)
void printHeap(const vector<pair<string, int>>& heap) {
    cout << "Current Mission Priorities (Min-Heap):" << endl;
    for (const auto& mission : heap) {
        cout << mission.first << ": " << mission.second << endl;
    }
    cout << endl;
}

int main() {
    vector<pair<string, int>> missionHeap;

    // Task 1: Insert missions
    insertMission(missionHeap, "Stop the bank robbery", 1);
    insertMission(missionHeap, "Defuse the bomb", 2);
    insertMission(missionHeap, "Rescue the cat", 5);
    insertMission(missionHeap, "Apprehend the villain", 3);
    printHeap(missionHeap);


    // Task 2: Delete the highest priority mission
    deleteMission(missionHeap);
    printHeap(missionHeap);


    // Task 3: Heapify an array of missions
    vector<pair<string, int>> initialMissions = {
        {"Save the world", 1},
        {"Find the missing dog", 10},
        {"Stop the asteroid", 2},
        {"Deliver pizza", 9}
    };
    cout << "Initial Missions (Unordered):" << endl;
    for(auto mission : initialMissions) {
        cout << mission.first << ": " << mission.second << endl;
    }
    cout << endl;
    heapifyArray(initialMissions);
    cout << "Missions after Heapify (Min-Heap):" << endl;
    for(auto mission : initialMissions) {
        cout << mission.first << ": " << mission.second << endl;
    }


    return 0;
}