#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"


#define SOURCE_SIZE 2
#define LOAD_SIZE 5
#define BUS_SIZE 2


int source[SOURCE_SIZE];
int is_active_source[SOURCE_SIZE];
int source_bus[SOURCE_SIZE];

int load[LOAD_SIZE];
int is_active_load[LOAD_SIZE];
int load_priority[LOAD_SIZE];
int load_bus[LOAD_SIZE];

int bus_connection[BUS_SIZE][BUS_SIZE];
int loop_count = 0;
int loop_source_total[BUS_SIZE];
int loop_load_total[BUS_SIZE];
int bus_system_total[BUS_SIZE]; // total source - total load

void init();

int main() {
    init();

    int total_load = 0;
    for (int i = 0; i < LOAD_SIZE; i++) {
        total_load += load[i];
    }

    int total_source = 0;
    for (int i = 0; i < SOURCE_SIZE; i++) {
        total_source += source[i];
    }

    printf("LOAD: ");
    print_array(load, LOAD_SIZE);
    printf("SOURCE: ");
    print_array(source, SOURCE_SIZE);
    printf("BUS CONNECTION: \n");
    print_bus_connection(BUS_SIZE, bus_connection);

    // source 2 shutdown
    printf("\n-- SOURCE 2 SHUTDOWN --\n");
    is_active_source[1] = 0;

    // check overload
    if (is_overload(load, is_active_load, source, is_active_source, LOAD_SIZE, SOURCE_SIZE)) {
        printf("SOURCE: ");
        print_active(source, is_active_source, SOURCE_SIZE);
        printf("OVERLOAD: Reducing loads\n");

        // shutdown necessary loads
        int total_load = sum_of_active(load, is_active_load, LOAD_SIZE);
        int total_source = sum_of_active(source, is_active_source, SOURCE_SIZE);

        while (is_overload(load, is_active_load, source, is_active_source, LOAD_SIZE, SOURCE_SIZE)) {
            int idx = idx_of_max_active(load, is_active_load, LOAD_SIZE);
            is_active_load[idx] = 0;
            printf("KILLING LOAD %d: ", idx);
            print_active(load, is_active_load, LOAD_SIZE);
        }
    }

    printf("\n");
    printf("SOURCE: ");
    print_active(source, is_active_source, SOURCE_SIZE);
    printf("LOAD: ");
    print_active(load, is_active_load, LOAD_SIZE);
    printf("SOURCE TOTAL: %d\n", sum_of_active(source, is_active_source, SOURCE_SIZE));
    printf("LOAD TOTAL: %d\n", sum_of_active(load, is_active_load, LOAD_SIZE));
}

void init() {
    source[0] = 10;
    source[1] = 8;
    is_active_source[0] = 1;
    is_active_source[1] = 1;

    load[0] = 5;
    load[1] = 3;
    load[2] = 2;
    load[3] = 3;
    load[4] = 3;

    for (int i = 0; i < LOAD_SIZE; i++) {
        is_active_load[i] = 1;
        load_bus[i] = 0;
    }

    for (int i = 0; i < SOURCE_SIZE; i++) {
        source_bus[i] = 0;
    }

    for (int i = 0; i < LOAD_SIZE; i++) {
        load_priority[i] = 1;
    }

    add_connection(BUS_SIZE, bus_connection, 0, 1);
}
