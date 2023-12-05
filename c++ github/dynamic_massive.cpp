// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//   The size of the dynamic array is entered by the user at the execution stage.
//   The array type is double.
//   The array elements are entered using the keyboard.
//   Remove all positive elements located between the first maximum and last minimum elements.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    #include <iostream>

    using namespace std;

    int enter_number_of_members(){
        cout << "How many numbers do you want to input?" << endl;
        int n;
        cin >> n;
        while (!n || n < 0){
            cout << "Please, try again!" << endl;
            cin >> n;
        }
        return n;
    }

    struct Vector
        {
            double* data;
            int _size; // current size
            int capacity; // maximum number of available elements

            Vector(int start_size = 10){ // Create a vector (construct)
                data = new double[start_size];
                capacity = start_size;
                _size = 0;
                // cout << "New vector has been created!" << '\n'; // test
            }

            void push(double element){ // Add an element to the end
                if (_size == capacity){
                    capacity = (capacity ? capacity * 2 : 1); // if (capacity != 0) then? (capacity * 2) else: 1
                    double* new_data = new double[capacity];
                    for (int i = 0; i < _size; i++)
                        new_data[i] = data[i];
                    delete[] data;
                    data = new_data;
                }
                data[_size++] = element;
            }

            void throw_vector(){ // Print out an array
                for (int i = 0; i < _size; i++)
                    cout << data[i] << ' ';
                cout << '\n';
            }

            void pop(int index){ // Remove an element
                for (int i = index; i <= _size; i++)
                    data[i] = data[i+1];
                _size--;
            }

            void task(){
                double maximum = data[0];
                int index_maximum = 0;
                double minimum = data[0];
                int index_minimum = 0;

                for (int i = 1; i < _size; i++){
                    if (data[i] > maximum){
                        maximum = data[i];
                        index_maximum = i; // first maximum
                    }
                }
                for (int i = 1; i < _size; i++){
                    if (data[i] <= minimum){ // '<=' is to find out the index of the last minimum
                        minimum = data[i];
                        index_minimum = i; // last minimum
                    }
                }
//              cout << "Maximum and minimum: " << maximum << " " << minimum << endl; // debug
//              cout << "Indexes of maximum and minimum: " << index_maximum << " " << index_minimum << endl; // debug

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Removal part ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

                if ((index_maximum == index_minimum + 1) || (index_maximum + 1 == index_minimum)){
                    cout << "nothing to delete" << endl;
                    return;
                }

                if (index_maximum < index_minimum){ // maximum before minimum
                    for (;;){
                        bool target = false;
                        for (int i = index_maximum + 1; i <= index_minimum; i++){
                            if (data[i] > 0){
                                pop(i);
                                break;
                            }
                            else{
                                if (i == index_minimum)
                                    target = true;
                            }
                        }
                        if (!target)
                            index_minimum--;
                        else break;
                        }

                    }
                if (index_maximum > index_minimum){ // maximum after minimum
                    for (;;){
                        bool target = false;
                        for (int i = index_minimum + 1; i <= index_maximum; i++){
                            if (i == index_maximum){
                                target = true;
                                break;
                            }
                            if (data[i] > 0){
                                pop(i);
                                break;
                            }
                        }
                        if (!target)
                            index_maximum--;
                        else break;
                        }
                }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
            }
        };

    int main(){
        int n = enter_number_of_members();
        Vector arr;
        cout << "Enter your numbers accurately: " << endl;
        for (int i = 0; i < n; i++){
            int elem;
            cin >> elem;
            arr.push(elem);
        }
        cout << "That's how does your array look like:" << endl;
        arr.throw_vector();
        cout << "Task is completed! Result: " << endl;
        arr.task();
        arr.throw_vector();
    }

