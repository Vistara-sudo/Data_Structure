//  I think i need to add realloc or malloc concept so that i will not need buffer storage memory.


#include <stdio.h>
#include <stdbool.h>

int ins(int arr[], int *n) {
    int idx, elem;
    if (*n > 10) {
        printf("Array is full. Cannot insert.\n");
        return 0;
    }
    printf("Enter position of element where you want to insert your element: ");
    scanf("%d", &idx);

    printf("Enter what to insert: ");
    scanf("%d", &elem);


    // shift element to right
    for(int i = *n; i >= idx; i--) {
        arr[i] = arr[i - 1];
    }

    arr[idx - 1] = elem;
    (*n)++;

    printf("Element inserted successfully!\n");

    for(int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



int del(int arr[], int *n) {
    int idx;
    printf("Enter position of element which you want to delete: ");
    scanf("%d", &idx);

    // Shift element to left
    for(int i = idx-1; i < *n-1; i++) {         // Not i< *n becuase after deletion we are not able to access *n-1
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully!\n");

    for(int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void search(int arr[], int *n) {
    int x;
    printf("Enter elements to search: ");
    scanf("%d", &x);

    bool flag = false;

    for(int i = 0; i < *n; i++) {
        if(arr[i] == x) {
            flag = true;
        }
    }

    if(flag) {
        printf("Element found");
    }
    else
        printf("Element not found");
}

void tra(int arr[], int *n) {
    for(int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
}

    int main() {
        char choice;
        int n;
        printf("Enter the size of array: ");
        scanf("%d",&n);
        int arr[n];

        printf("Enter elements of array: ");
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Enter your choices: 'I' for insert, 'D' for deletion 'T' for traversal 'S' for searching: ");
        scanf(" %c", &choice);

        if(choice == 'I' || choice == 'i') {
            ins(arr, &n);
        }
        else if(choice == 'D' || choice == 'd') {
            del(arr, &n);
        }
        else if(choice == 'T' || choice == 't') {
            tra(arr, &n);
        }
        else if(choice == 'S' || choice == 's') {
            search(arr, &n);
        }

        return 0;
    }