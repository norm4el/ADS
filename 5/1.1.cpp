#include <iostream>
#include <vector>

using namespace std;

/*
    Класс MinHeap - самостоятельная реализация очереди с приоритетом.
    В основе лежит обычный динамический массив (vector), но элементы в нем
    располагаются по правилам полного бинарного дерева.
*/
class MinHeap {
private:
    // Вектор для хранения элементов кучи
    vector<long long> heap;

    // Вспомогательные функции для вычисления индексов (по формулам из лекции)
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    /*
        Heapify-Up: Поднятие элемента вверх.
        Вызывается при добавлении нового элемента в конец.
        Если добавленный элемент меньше своего родителя, они меняются местами,
        и так продолжается вплоть до корня, пока не восстановится свойство Min-Heap.
    */
    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            // Меняем текущий элемент с родителем
            swap(heap[i], heap[parent(i)]);
            // Переходим на индекс родителя для следующей проверки
            i = parent(i);
        }
    }

    /*
        Heapify-Down: Спуск элемента вниз.
        Вызывается при удалении корня (минимального элемента).
        Новый корень сравнивается со своими детьми и меняется местами
        с НАИМЕНЬШИМ из них, опускаясь вниз по дереву.
    */
    void heapifyDown(int i) {
        int smallest = i;       // Предполагаем, что текущий узел самый маленький
        int l = left(i);        // Индекс левого ребенка
        int r = right(i);       // Индекс правого ребенка
        int n = heap.size();

        // Если левый ребенок существует и он меньше текущего наименьшего
        if (l < n && heap[l] < heap[smallest]) {
            smallest = l;
        }
        // Если правый ребенок существует и он меньше текущего наименьшего
        if (r < n && heap[r] < heap[smallest]) {
            smallest = r;
        }

        // Если наименьшим оказался не сам родитель, а один из детей
        if (smallest != i) {
            swap(heap[i], heap[smallest]); // Меняем их местами
            heapifyDown(smallest);         // Рекурсивно продолжаем спуск
        }
    }

public:
    /*
        Вставка нового значения.
        Сложность: O(log N)
    */
    void push(long long val) {
        heap.push_back(val);        // Ставим элемент в самый конец массива
        heapifyUp(heap.size() - 1); // Поднимаем его на правильное место
    }

    /*
        Удаление минимального значения (корня).
        Сложность: O(log N)
    */
    void pop() {
        if (heap.empty()) return;
        
        heap[0] = heap.back();      // Заменяем корень последним элементом дерева
        heap.pop_back();            // Удаляем последний элемент
        
        if (!heap.empty()) {
            heapifyDown(0);         // Опускаем новый корень на правильное место
        }
    }

    /*
        Получение минимального значения.
        Сложность: O(1)
    */
    long long top() {
        return heap[0]; // Минимальный элемент всегда лежит под индексом 0
    }

    int size() {
        return heap.size();
    }
};

int main() {
    // Оптимизация потоков ввода/вывода для быстродействия
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    MinHeap pq; // Создаем нашу кучу

    // 1. Считываем длины всех массивов и добавляем их в кучу
    for (int i = 0; i < n; ++i) {
        long long length;
        cin >> length;
        pq.push(length);
    }

    long long total_cost = 0;

    // 2. Жадный алгоритм: пока массивов больше одного, сливаем два самых коротких
    while (pq.size() > 1) {
        // Достаем первый минимальный элемент
        long long first = pq.top();
        pq.pop();
        
        // Достаем второй минимальный элемент
        long long second = pq.top();
        pq.pop();

        // Считаем стоимость текущего слияния
        long long current_merge_cost = first + second;
        
        // Добавляем к общей стоимости всех операций
        total_cost += current_merge_cost;

        // Возвращаем получившийся слитый массив обратно в кучу
        pq.push(current_merge_cost);
    }

    // 3. Выводим итоговую минимальную стоимость
    cout << total_cost << "\n";

    return 0;
}