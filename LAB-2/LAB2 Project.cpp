// LAB2 Project.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>


struct Node {
    std::string songTitle;
    Node* next;
};
void addSong(Node*& head, std::string title); 
void searchSong(Node* head, std::string title);
void displayPlaylist(Node* head);

int main() {
    Node* head = nullptr;
    int secim;
    std::string title;

    
    do {
        std::cout << " MENU" << std::endl;
        std::cout << "1. SARKI EKLE" << std::endl;
        std::cout << "2. SARKI ARA" << std::endl;
        std::cout << "3.SARKI LISTELE" << std::endl;
        std::cout << "4.CİKİS " << std::endl;
        std::cout << "SEC: ";
        std::cin >> secim;
        std::cin.ignore(); 

        switch (secim) {
        case 1:
            std::cout << "Sarki gir: "; ;
            std::getline(std::cin, title);
            addSong(head, title);
            break;
        case 2:
            std::cout << "Sarki arat: "; 
            std::getline(std::cin, title);
            searchSong(head, title);
            break;
        case 3:
            std::cout << "Sarki calinmaya basliyor." << std::endl;
            displayPlaylist(head);
            break;
        case 4:
            std::cout << "Cikis yapiyorsun" << std::endl;
            break;
        default:
            std::cout << "Yanlis sectin!!/ Bir daha dene!!" << std::endl;
        }
    } while (secim != 4);

    return 0;
}
 
void addSong(Node*& head, std::string title) {
    Node* newNode = new Node();
    newNode->songTitle = title;
    newNode->next = head; 
    head = newNode;       
    std::cout << "Sarkini ekledin!" << std::endl;
}

void searchSong(Node* head, std::string title) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->songTitle == title) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        std::cout << "Bu sarki '" << title << "' bulundu." << std::endl;
    }
    else {
        std::cout << "Bu sarki '" << title << "' bulunamadi." << std::endl;
    }
}


void displayPlaylist(Node* head) {
    if (head == nullptr) {
        std::cout << "Playlistin bos." << std::endl;
        return;
    }

    Node* temp = head;
    int order = 1;
    std::cout << "\n--- Anlık Listen ---" << std::endl;
    while (temp != nullptr) {
        std::cout << order << ". " << temp->songTitle << std::endl;
        temp = temp->next;
        order++;
    }
}
