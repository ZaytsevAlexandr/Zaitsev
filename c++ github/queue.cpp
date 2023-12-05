    #include <iostream>
    #include <windows.h>

    using namespace std;

    void error(){
        cout << "ERROR" << endl;
    }
    template <typename T>
    struct Vector
    {
        T* data;
        int _size; // current size
        int capacity; // maximum number of available elements

        void sort(){
            float const fact_increase = 1.247;
            int compare_step = _size / fact_increase;
            while (compare_step >= 1){
                for (int i = 0; i + compare_step < _size; i++){
                    if (data[i] > data[i + compare_step])
                        swap(data[i], data[i + compare_step]);
                }
                compare_step /= fact_increase;
            }
        }

        void push(int element){ // Add an element to the end
            if (_size == capacity){
                capacity = (capacity ? capacity * 2 : 1); // if (capacity != 0) then? (capacity * 2) else: 1
                auto new_data = new T[capacity];
                for (auto i = 0; i < _size; i++)
                    new_data[i] = data[i];
                delete[] data;
                data = new_data;
            }
            data[_size++] = element;
            sort();
        }

        Vector(int start_size = 10){ // Create a vector (construct)
            data = new T[start_size];
            cout << "Welcome, come in!" << endl;
            capacity = start_size;
            _size = 0;
        }

        ~Vector(){ // Destroy a vector (free memory) (destruct)
            cout << "All enough, we are closed" << endl;
            delete[] data;
        }

        void pop(){ // Remove an element from the beginning
            cout << "Next, please." << endl;
            for (int i = 0; i < _size; i++)
                data[i] = data[i+1];
            _size--;
        }

        int front(){
            if (_size){
                cout << "Who is the next?" << endl;
                return data[0];
            }
            else{
                cout << "No queue anymore!" << endl;
                return -1;
            }
        }

        int back(){
            if (_size){
                cout << "Who is the last?" << endl;
                return data[_size - 1];
            }
            else{
                cout << "No queue anymore!" << endl;
                return -1;
            }
        }

        int size(){ // Size of vector
            cout << "How many people in this line are waiting?" << endl;
            return _size;
        }

        int operator[](int index){
            return data[index];
        }
    };

    int main(){

        cout << "How much people have come?" << endl;
        int n;
        cin >> n;
        if (n == 0){
            error();
            return -1;
        }
        auto arr = Vector<int>(n);
        Sleep(500);
        cout << "People, show your IDs." << endl;
        for (int i = 0; i < n; i++){
            int ID;
            cin >> ID;
            arr.push(ID);
        }
        Sleep(300);
        cout << "Thank you." << endl;
        Sleep(500);
        cout << "Get in line in ascending your IDs." << endl;
        arr.sort();
        for (int i = 0; i < arr._size; i++){
            cout << arr[i];
            if (i != arr._size - 1)
                cout << ", ";
            else
                cout << ".";
        }
        cout << endl;
        Sleep(500);
        cout << "Nice! Wait, please." << endl;
        Sleep(500);
        arr.pop();
        cout << arr.size() << endl;
        Sleep(500);
        for (int i = 0; i < arr._size; i++){
            cout << arr[i];
            if (i != arr._size - 1)
                cout << ", ";
            else
                cout << ".";
        }
        cout << endl;
        Sleep(500);
        cout << arr.front() << endl;
        Sleep(500);
        cout << arr.back() << endl;
        Sleep(500);
    }
