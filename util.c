#include <stdio.h>

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

void print_active(int arr[], int is_active[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (is_active[i]) {
            printf("%d", arr[i]);
        } else {
            printf("X");
        }
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

void add_connection(int bus_size, int bus_connection[bus_size][bus_size], int from, int to) {
    bus_connection[from][to] = 1;
    bus_connection[to][from] = 1;
}

int is_bus_connected(int bus_size, int bus_connection[bus_size][bus_size], int from, int to) {
    return bus_connection[from][to];
}

int sum_of_active(int arr[], int is_active[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (is_active[i]) {
            sum += arr[i];
        }
    }
    return sum;
}

int is_overload(int load[], int is_active_load[], int source[], int is_active_source[], int load_size, int source_size) {
    int total_load = sum_of_active(load, is_active_load, load_size);
    int total_source = sum_of_active(source, is_active_source, source_size);

    return total_load > total_source;
}

int idx_of_max_active(int arr[], int is_active[], int size) {
    int max = 0;
    int idx = -1;
    for (int i = 0; i < size; i++) {
        if (is_active[i] && arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }
    return idx;
}

int loop_source_total(int source_size, int source[source_size], int is_active_source[source_size], int source_bus[source_size], int bus_size, int bus_connection[bus_size][bus_size], int *loop_source) {
    int total = 0;
}

void print_bus_connection(int bus_size, int bus_connection[bus_size][bus_size]) {
    printf("[");
    for (int i = 0; i < bus_size; i++) {
        printf("[");
        for (int j = 0; j < bus_size; j++) {
            printf("%d", bus_connection[i][j]);
            if (j < bus_size - 1) {
                printf(" ");
            }
        }
        if (i < bus_size - 1) {
            printf("]\n");
        } else {
            printf("]");
        }
    }
    printf("]\n");
}
