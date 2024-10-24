#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // Adjust based on expected input size

typedef struct {
    int key;
    int value;
} MapEntry;

typedef struct {
    MapEntry entries[MAX_SIZE];
    int size;
} Map;

void initMap(Map *map) {
    map->size = 0;
    map->entries[0].key = 0;
    map->entries[0].value = 1; // Initialize for sum = 0
    map->size++;
}

int find(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return i;
        }
    }
    return -1;
}

void insert(Map *map, int key) {
    int index = find(map, key);
    if (index != -1) {
        map->entries[index].value++;
    } else {
        map->entries[map->size].key = key;
        map->entries[map->size].value = 1;
        map->size++;
    }
}

void clearMap(Map *map) {
    map->size = 0;
    map->entries[0].key = 0;
    map->entries[0].value = 1; // Reset for the next subarray
    map->size++;
}

int main() {
    long long test_cases;
    scanf("%lld", &test_cases);

    while (test_cases--) {
        int n;
        scanf("%d", &n);

        Map prefixSums;
        initMap(&prefixSums);

        int currentSum = 0;
        int subarrayCount = 0;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            currentSum += x;

            // Check if this sum has been seen before
            int index = find(&prefixSums, currentSum);
            if (index != -1) {
                subarrayCount++;
                clearMap(&prefixSums);
                currentSum = 0; // Reset current sum
            } else {
                insert(&prefixSums, currentSum);
            }
        }

        printf("%d\n", subarrayCount);
    }

    return 0;
}
