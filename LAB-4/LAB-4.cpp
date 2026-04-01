#include <iostream>
#include <string>

struct MoneyBundle {
    std::string serialNumber = "";
    std::string currencyType = "";
    int billCounts[3];
    MoneyBundle* next = nullptr;
};

struct Customer {
    std::string customerName = "";
    std::string transactionType = "";
};

MoneyBundle* top = nullptr;
Customer queueArray[5];
int front = -1;
int rear = -1;
const int MAX_SIZE = 5;

void Push(std::string sn, std::string type, int counts[]) {
    MoneyBundle* NewBundle = new MoneyBundle();
    NewBundle->serialNumber = sn;
    NewBundle->currencyType = type;
    for (int i = 0; i < 3; i++) {
        NewBundle->billCounts[i] = counts[i];
    }
    NewBundle->next = top;
    top = NewBundle;
}

void Pop() {
    if (top == nullptr) return;
    MoneyBundle* ToDelete = top;
    top = top->next;
    delete ToDelete;
}

void Enqueue(std::string name, std::string trans) {
    if ((rear + 1) % MAX_SIZE == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queueArray[rear].customerName = name;
    queueArray[rear].transactionType = trans;
}

void Dequeue() {
    if (front == -1) return;
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
    }
}

void ProcessTransaction() {
    if (top == nullptr || front == -1) return;
    std::cout << "Islem Tamamlandi: " << queueArray[front].customerName
        << " adli kisiye " << top->serialNumber << " nolu paket verildi." << std::endl;
    Pop();
    Dequeue();
}

void Display() {
    std::cout << "--- KASA (PARA DESTELERI) ---" << std::endl;
    if (top == nullptr) {
        std::cout << "Kasa bos!" << std::endl;
    }
    else {
        MoneyBundle* Temp = top;
        while (Temp != nullptr) {
            std::cout << "Seri No: " << Temp->serialNumber << " | Tur: " << Temp->currencyType
                << " | (100:" << Temp->billCounts
        }
    }
}