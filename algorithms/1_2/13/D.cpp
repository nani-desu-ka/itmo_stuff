#include <iostream>
#include <vector>

using namespace std;

/*Автомат Кнута-Морриса-Пратта*/
class KMP_machine {
public:
    /*PI строки*/
    void prefix_search() {
        prefix.push_back(0);
        for (int i = 1; i < this->search_area.size(); i++) {
            int temp = prefix[i - 1];
            while (temp > 0 && this->search_area[i] != this->search_area[temp]) {
                temp = prefix[temp - 1];
            }
            if (this->search_area[temp] == this->search_area[i])
                prefix.push_back(temp + 1);
            else
                prefix.push_back(temp);
        }
    }

    /*Построение остова*/
    void span_construct() {
        for (int i = 0; i < this->search_area.size(); i++) {
            int symbol = static_cast<int>(this->search_area[i]) - 97;
            this->transition_matrix[i][symbol] = i + 1;
        }
    }

    /*Создание матрицы переходов*/
    void transition_matrix_construct() {
        this->transition_matrix = new int* [this->search_area.size() + 1];
        for (int i = 0; i <= this->search_area.size(); i++) {
            this->transition_matrix[i] = new int [this->alphabet_size];
        }
        for (int i = 0; i <= this->search_area.size(); i++) {
            for (int j = 0; j < this->alphabet_size; j++) {
                this->transition_matrix[i][j] = 0;
            }
        }
    }

    /*Конструктор класса*/
    KMP_machine(int alphabet_size, string seatch_area) : alphabet_size(alphabet_size), search_area(seatch_area) {}

    /*Заполение матрицы переходов*/
    void transition_matrix_fill() {
        for (int i = 1; i <= this->search_area.size(); i++) {
            for (int j = 0; j < this->alphabet_size; j++) {
                if (this->transition_matrix[i][j] == 0) this->transition_matrix[i][j] = transition(i - 1, j);
            }
        }
    }

    /*Переход*/
    int transition(int prefix_index, int state) {
        return this->transition_matrix[this->prefix[prefix_index]][state];
    }

    /*Вывод матрицы переходов*/
    void transition_matrix_print () {
        for (int i = 0; i <= this->search_area.size(); i++) {
            for (int j = 0; j < this->alphabet_size; j++) cout << this->transition_matrix[i][j] << ' ';
            cout << '\n';
        }
    }


    /*Начало работы*/
    void processing() {
        transition_matrix_construct();
        span_construct();
        prefix_search();
        transition_matrix_fill();
        transition_matrix_print();
    }

private:
    int alphabet_size;
    string search_area;
    vector<int> prefix;
    int **transition_matrix;
};

int main () {
    int alphabet_size;
    string search_area;
    cin >> alphabet_size;
    cin >> search_area;
    KMP_machine test_machine(alphabet_size, search_area);
    test_machine.processing();
    return 0;
}