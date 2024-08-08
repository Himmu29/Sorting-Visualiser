#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

// Initialize the size with the total numbers to be sorted and the gap to be maintained in graph
vector<int> numbers;
int size = 200;
int gap = 4;

// Function for swapping the lines graphically for selection sort
void swap_colors_sel(int i, int j, int x, int y) {
    setcolor(GREEN);
    line(j, size, j, size - y);

    delay(100);

    setcolor(BLACK);
    line(j, size, j, size - y);

    setcolor(WHITE);
    line(j, size, j, size - x);

    setcolor(BLACK);
    line(i, size, i, size - x);

    setcolor(GREEN);
    line(i, size, i, size - y);

    delay(100);

    setcolor(WHITE);
    line(i, size, i, size - y);
}

// Selection sort function
void selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < size; j++) {
            if (numbers[j] < numbers[min_idx]) {
                min_idx = j;
            }
        }

        swap(numbers[min_idx], numbers[i]);
        swap_colors_sel(gap * i + 1, gap * (min_idx) + 1, numbers[min_idx], numbers[i]);
    }
}

// Function for swapping the lines graphically for bubble sort
void swap_colors_bubble(int i, int j, int x, int y) {
    setcolor(GREEN);
    line(i, size, i, size - x);

    delay(100);

    setcolor(BLACK);
    line(i, size, i, size - x);

    setcolor(WHITE);
    line(i, size, i, size - y);

    setcolor(GREEN);
    line(j, size, j, size - y);

    delay(100);

    setcolor(BLACK);
    line(j, size, j, size - y);

    setcolor(WHITE);
    line(j, size, j, size - x);
}

// Bubble sort function
void bubbleSort() {
    int temp, i, j;

    for (i = 1; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;

                swap_colors_bubble(gap * j + 1, gap * (j + 1) + 1, numbers[j + 1], numbers[j]);
            }
        }
    }
}

// Function to initialize and shuffle the array
void initializeArray() {
    numbers.clear();
    for (int i = 1; i <= size; i++)
        numbers.push_back(i);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));
}

// Function to plot the initial array
void plotArray() {
    for (int i = 1; i <= gap * size; i += gap) {
        line(i, size, i, (size - numbers[i / gap]));
    }
}

// Driver program
int main() {
    int gd = DETECT, gm;
    int wid1;

    // Graph initialization
    initgraph(&gd, &gm, NULL);

    // Setting up window size (gap*size) * (size)
    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

    // Initialize and shuffle the array
    initializeArray();

    // Initial plot of numbers in graph
    plotArray();

    // Delay the code
    delay(200);

    // Menu for selecting the sort
    cout << "Select sorting algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Bubble Sort\n";
    int choice;
    cin >> choice;

    // Call the selected sort
    switch (choice) {
        case 1:
            selectionSort();
            break;
        case 2:
            bubbleSort();
            break;
        default:
            cout << "Invalid choice!";
            break;
    }

    // Wait for some time
    delay(5000);

    // Close the graph
    closegraph();

    return 0;
}
