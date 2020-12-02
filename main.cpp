//14.    Класс «Множество».

#include<iostream>

template <typename T>
class Set{
public:
    T *elements;
    int size;
    Set():size{0}{}
    Set(int size):size{size}{
        elements = new T[size];
    }
    ~Set(){
        if(size==0){
            return;
        }
    }
    void add_element(T element){
        if(size==0){
            elements = new T[1];
            elements[0]=element;
            size++;
        }else if(index_of(element) == -1){
            T *temp = new T[size + 1];
            for(int i = 0; i < size; i++){
                temp[i] = std::move(elements[i]);
            }
            temp[size] = element;
            delete [] elements;
            elements = temp;
            size++;
        }
    }
    int index_of(T element){
        for(int i = 0; i < size; i++){
            if(elements[i] == element){
                return i;
            }
        }
        return -1;
    }
    void delete_element(T element){
        if(index_of(element) == -1){
            return;
        }else if(size == 1){
            delete [] elements;
            size--;
        }else{
            T *temp = new T[size - 1];
            int j = 0;
            for(int i = 0; i < size; i++){
                if(elements[i] != element){
                    temp[j] == std::move(elements[i]);
                    j++;
                }
            }
            delete[] elements;
            elements = temp;
            size--;
        }
        
    }
    T& get_element(int index){
        return elements[index];
    }
    T& operator[](int index){
        return get_element(index);
    }
    
    void sort_elements(){
        if(size > 1){
            for(int i = 0; i < size; i++){
                for(int j = i; j < size; j++){
                    if(elements[i] < elements[j]){
                        T temp = std::move(elements[j]);
                        elements[j] = std::move(elements[i]);
                        elements[i] = std::move(temp);
                    }
                }
            }
        }
    }
    bool operator==(Set<T> set){
        if(size != set.size){
            return false;
        }
        for(int i = 0; i < size; i++){
            if(set.index_of(elements[i]) == -1){
                return false;
            }
        }
        return true;
    }
    bool operator != (Set<T> set){
        return !(operator==(set));
    }
};

bool is_number(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (!isnumber(str[i])) {
            return false;
        }
    }
    return true;
}

int read_int() {
    std::string buffer;
    while (true) {
        std::getline(std::cin, buffer);
        if (is_number(buffer)) {
            return std::stoi(buffer);
        } else {
            std::cout << "it is not a number" << std::endl;
        }
    }
}

int read_count() {
    while (true) {
        int count = read_int();
        if (count <= 0) {
            std::cout << "enter count > 0" << std::endl;
        } else {
            return count;
        }
    }
}


int main() {
    std::cout << "how many elements add to first set: " << std::endl;
    int count = read_count();
    
    Set<int> first;

    std::cout << "enter elements of first set: " << std::endl;
    for (int i = 0; i < count; i++) {
        int number = read_int();
        first.add_element(number);
    }
    
    std::cout << "how many elements add to second set: " << std::endl;
    count = read_count();
    
    Set<int> second;
    std::cout << "enter elements of second set: " << std::endl;
    for (int i = 0; i < count; i++) {
        int number = read_int();
        second.add_element(number);
    }
    
    std::cout << "first set : " << std::endl;
    for (int i = 0; i < first.size; i++) {
        std::cout << first[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "second set : " << std::endl;
    for (int i = 0; i < second.size; i++) {
        std::cout << second[i] << " ";
    }
    std::cout << std::endl;
    
    if (first == second) {
        std::cout << "sets are equals" << std::endl;
    } else {
        std::cout << "sets are not equals" << std::endl;
    }
    
    first.sort_elements();
    std::cout << "sorted first set: " << std::endl;
    for (int i = 0; i < first.size; i++) {
        std::cout << first[i] << " ";
    }
    std::cout << std::endl;
}
