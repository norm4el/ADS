#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

// 1. Вставка (Лазейка с фиктивным узлом)
Node* insert(Node* head, int value, int position) {
    Node* dummy = new Node{0, head}; // Временный узел встает ПЕРЕД головой
    Node* curr = dummy;
    
    // Идем до нужного места. Так как есть dummy, мы никогда не выйдем за пределы
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    
    curr->next = new Node{value, curr->next};
    
    head = dummy->next; // Новая голова
    delete dummy;       // Убираем фиктивный узел
    return head;
}

// 2. Удаление (Лазейка с фиктивным узлом)
Node* remove(Node* head, int position) {
    Node* dummy = new Node{0, head};
    Node* curr = dummy;
    
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    
    Node* to_delete = curr->next;
    curr->next = to_delete->next;
    delete to_delete;
    
    head = dummy->next;
    delete dummy;
    return head;
}

// 3. Вывод
void print(Node* head) {
    if (head == nullptr) {
        cout << "-1\n";
        return;
    }
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->value << (curr->next ? " " : "");
    }
    cout << "\n";
}

// 4. Замена (Используем уже готовые insert и remove)
Node* replace(Node* head, int p1, int p2) {
    Node* curr = head;
    for (int i = 0; i < p1; i++) {
        curr = curr->next;
    }
    int val = curr->value;       // Запомнили значение
    head = remove(head, p1);     // Удалили со старого места
    return insert(head, val, p2); // Вставили на новое
}

// 5. Разворот
Node* reverse(Node* head) {
    Node* prev = nullptr;
    while (head != nullptr) {
        Node* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }
    return prev;
}

// 6. Сдвиг влево (Лазейка с кольцом)
Node* shift_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr) return head;
    
    int length = 1;
    Node* tail = head;
    // Находим хвост и длину
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }
    
    x = x % length;
    if (x == 0) return head;
    
    tail->next = head; // Замыкаем список в кольцо
    
    // Крутим кольцо
    for (int i = 0; i < x; i++) {
        tail = tail->next;
    }
    
    head = tail->next; // Назначаем новую голову
    tail->next = nullptr; // Разрезаем кольцо
    
    return head;
}

// 7. Сдвиг вправо (Это сдвиг влево на "длина - x")
Node* shift_right(Node* head, int x) {
    int length = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        length++;
    }
    if (length == 0) return head;
    
    return shift_left(head, length - (x % length));
}

int main() {
    Node* head = nullptr;
    int command, value, p1, p2;

    while (cin >> command && command != 0) {
        if (command == 1) {
            cin >> value >> p1;
            head = insert(head, value, p1);
        } else if (command == 2) {
            cin >> p1;
            head = remove(head, p1);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            cin >> value;
            head = shift_left(head, value);
        } else if (command == 7) {
            cin >> value;
            head = shift_right(head, value);
        }
    }
    
    return 0;
}