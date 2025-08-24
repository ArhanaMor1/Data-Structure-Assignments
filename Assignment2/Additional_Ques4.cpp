#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            int t = arr[low];
            arr[low] = arr[mid];
            arr[mid] = t;
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else {
            int t = arr[mid];
            arr[mid] = arr[high];
            arr[high] = t;
            high--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
