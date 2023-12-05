    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Vector {
        double* data;
        int _size;
        int capacity;
    } Vector;

    int enter_number_of_members() {
        printf("How many numbers do you want to input?\n");
        int n;
        scanf("%d", &n);
        while (!n || n < 0) {
            printf("Please, try again!\n");
            scanf("%d", &n);
        }
        return n;
    }

    void init_vector(Vector* vec, int start_size) {
        vec->data = (double*)malloc(start_size * sizeof(double));
        vec->capacity = start_size;
        vec->_size = 0;
    }

    void push(Vector* vec, double element) {
        if (vec->_size == vec->capacity) {
            vec->capacity = (vec->capacity ? vec->capacity * 2 : 1);
            double* new_data = (double*)malloc(vec->capacity * sizeof(double));
            for (int i = 0; i < vec->_size; i++)
                new_data[i] = vec->data[i];
            free(vec->data);
            vec->data = new_data;
        }
        vec->data[vec->_size++] = element;
    }

    void throw_vector(Vector* vec) {
        for (int i = 0; i < vec->_size; i++)
            printf("%lf ", vec->data[i]);
        printf("\n");
    }

    void pop(Vector* vec, int index) {
        for (int i = index; i < vec->_size - 1; i++)
            vec->data[i] = vec->data[i + 1];
        vec->_size--;
    }

    void task(Vector* vec) {
        double maximum = vec->data[0];
        int index_maximum = 0;
        double minimum = vec->data[0];
        int index_minimum = 0;
        for (int i = 1; i < vec->_size; i++) {
            if (vec->data[i] > maximum) {
                maximum = vec->data[i];
                index_maximum = i;
            }
        }
        for (int i = 1; i < vec->_size; i++) {
            if (vec->data[i] <= minimum) {
                minimum = vec->data[i];
                index_minimum = i;
            }
        }

        if ((index_maximum == index_minimum + 1) || (index_maximum + 1 == index_minimum)) {
            printf("nothing to delete\n");
            return;
        }
        if (index_maximum < index_minimum) {
            for (;;) {
                int target = 0;
                for (int i = index_maximum + 1; i <= index_minimum; i++) {
                    if (vec->data[i] > 0) {
                        pop(vec, i);
                        break;
                    } else {
                        if (i == index_minimum)
                            target = 1;
                    }
                }
                if (!target)
                    index_minimum--;
                else
                    break;
            }
        }
        if (index_maximum > index_minimum) {
            for (;;) {
                int target = 0;
                for (int i = index_minimum + 1; i <= index_maximum; i++) {
                    if (i == index_maximum) {
                        target = 1;
                        break;
                    }
                    if (vec->data[i] > 0) {
                        pop(vec, i);
                        break;
                    }
                }
                if (!target)
                    index_maximum--;
                else
                    break;
            }
        }
    }

    int main() {
        int n = enter_number_of_members();
        Vector arr;
        init_vector(&arr, 10);
        printf("Enter your numbers accurately:\n");
        for (int i = 0; i < n; i++) {
            double elem;
            scanf("%lf", &elem);
            push(&arr, elem);
        }
        printf("That's how does your array look like:\n");
        throw_vector(&arr);
        printf("Task is completed! Result:\n");
        task(&arr);
        throw_vector(&arr);
        free(arr.data);
        return 0;
    }



