#ifndef UTIL_H
#define UTIL_H

void print_array(int arr[], int size);
int is_overload(int load[], int is_active_load[], int source[], int is_active_source[], int load_size, int source_size);
int idx_of_max_active(int arr[], int is_active[], int size);
int sum_of_active(int arr[], int is_active[], int size);
void print_active(int arr[], int is_active[], int size);
void print_bus_connection(int bus_size, int bus_connection[bus_size][bus_size]);
void add_connection(int bus_size, int bus_connection[bus_size][bus_size], int from, int to);
int is_bus_connected(int bus_size, int bus_connection[bus_size][bus_size], int from, int to);

#endif