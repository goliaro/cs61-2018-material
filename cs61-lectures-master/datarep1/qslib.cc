#include "qslib.hh"
#include "allowexec.hh"

static void initialize_up(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
}

static void initialize_down(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = n - i;
    }
}

static void initialize_random(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::swap(array[i], array[random() % n]);
    }
}

static void initialize_magic(int* array, int n) {
    for (int i = 1; i <= n; ++i) {
        int middle = i / 2;
        array[i - 1] = array[middle];
        array[middle] = i;
    }
}

void ints_print(const int* array, int n) {
    printf("[");
    for (int i = 0; i < n && i < 20; ++i) {
        printf(i ? " %d" : "%d", array[i]);
    }
    if (n > 20) {
        printf(" ...");
    }
    printf("]\n");
}

void ints_print(const std::list<int>& list) {
    printf("[");
    auto it = list.begin();
    for (int i = 0; it != list.end() && i < 20; ++i, ++it) {
        printf(i ? " %d" : "%d", *it);
    }
    if (it != list.end()) {
        printf(" ...");
    }
    printf("]\n");
}

void ints_print(const std::vector<int>& list) {
    printf("[");
    auto it = list.begin();
    for (int i = 0; it != list.end() && i < 20; ++i, ++it) {
        printf(i ? " %d" : "%d", *it);
    }
    if (it != list.end()) {
        printf(" ...");
    }
    printf("]\n");
}

qs_info parse_arguments(int argc, char** argv) {
    limit_stack_size(1048576);   // 1MB of stack is enough for anyone!

    qs_info qsi;
    qsi.size = 6;
    qsi.execute = true;

    // parse command line arguments
    int initialize_type = 'r';
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-r") == 0
            || strcmp(argv[i], "-u") == 0
            || strcmp(argv[i], "-d") == 0
            || strcmp(argv[i], "-m") == 0) {
            initialize_type = argv[i][1];
        } else if (strcmp(argv[i], "-n") == 0) {
            qsi.execute = false;
        } else if (strisnumber(argv[i])) {
            qsi.size = strtol(argv[i], NULL, 0);
        } else {
            fprintf(stderr, "Usage: %s [-r|-u|-d|-m] [-n] [SIZE]\n", argv[0]);
            exit(1);
        }
    }

    // initialize based on command line argument
    qsi.array = (int*) malloc(sizeof(int) * qsi.size);
    if (initialize_type == 'r') {
        initialize_random(qsi.array, qsi.size);
    } else if (initialize_type == 'u') {
        initialize_up(qsi.array, qsi.size);
    } else if (initialize_type == 'd') {
        initialize_down(qsi.array, qsi.size);
    } else if (initialize_type == 'm') {
        initialize_magic(qsi.array, qsi.size);
    }

    qsi.checksum = ints_checksum(qsi.array, qsi.size);
    return qsi;
}
