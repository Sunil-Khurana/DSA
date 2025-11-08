#include <iostream.h>
struct Activity {
    int start;
    int finish;
    int index;  // to track original position
};

// Function to sort activities by finish time (Selection Sort)
void sortActivities(Activity act[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int min_idx = i;
        for (int j = i+1; j < n; ++j) {
            if (act[j].finish < act[min_idx].finish) {
                min_idx = j;
            }
        }
        Activity temp = act[i];
        act[i] = act[min_idx];
        act[min_idx] = temp;
    }
}

void activitySelection(Activity act[], int n) {
    sortActivities(act, n);

    cout << "Selected Activities (by index): ";
    int last_finish = act[0].finish;
    cout << act[0].index << " ";

    for (int i = 1; i < n; ++i) {
        if (act[i].start >= last_finish) {
            cout << act[i].index << " ";
            last_finish = act[i].finish;
        }
    }
    cout << endl;
}

int main() {
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    Activity act[6];

    for (int i = 0; i < n; ++i) {
        act[i].start = start[i];
        act[i].finish = finish[i];
        act[i].index = i;
    }

    activitySelection(act, n);

    return 0;
}
