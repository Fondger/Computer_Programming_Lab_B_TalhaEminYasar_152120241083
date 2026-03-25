
#include <iostream>
#include <string>
struct Page {
    string url;
    string title;
    int Time[3];
    Page* next;
    Page* prev;

}

Page(string u, string t, int h, int m, int s) {
    url = u;
    title = t;
    accessTime[0] = h;
    accessTime[1] = m;
    accessTime[2] = s;
    next = nullptr;
    prev = nullptr;
}


Page* first = nullptr;
Page* now = nullptr;

void visited(string url, string title, int h, int m, int s) {
    Page* newPage = new Page(url, title, h, m, s);
    if (first == nullptr) {
        first = newPage;
        now = first;
    }
    else {
        Page* temp = first;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newPage;
        newPage->prev = temp;
        now = newPage;
    }
    

      void getBack(){
        if (now != nullptr && now->prev != nullptr) {
            now = now->prev;
        }

      void getForward(){
            if (now != nullptr && now->next != nullptr) {
                now = now->next;
            }

            void deleted() {
                if (now == nullptr)
                    << cout "No pages are deleted." << endl;
                return;
                Page* Del = now;
                if (Del->prev != nullptr) Del->prev->next = Del->next;
                else first = Del->next;
                if (Del->next != nullptr) {
                    Del->next->prev = Del->prev;
                    now = Del->next;
                }
                else {
                    now = Del->prev;
                }
                delete Del;
            }
            void Display(){
                if (first == nullptr) return;
                Page* temp = first;
                while(temp != nullptr) {
                    if (temp == current) cout << " > [Anlık] ";
                    else cout << "   ";
                    cout << temp->title << " (" << temp->url << ") Zaman: ";
                    for (int i = 0; i < 3; i++) {
                        cout << (temp->Time[i] < 10 ? "0" : "") << temp->Time[i] << (i < 2 ? ":" : "");
                    }
                    cout << endl;
                    temp = temp->next;
                }


      
        void clear() {
            Page* temp = first;
            while (temp != nullptr) {
                Page* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            first = nullptr;
            now = nullptr;
        }
int main(){
    string choice = "";
    while (choice != "EXIT") {
        cout << "\n1.Visit 2.Back 3.Forward 4.Delete 5.Display EXIT: ";
        cin >> choice;
        if (choice == "1") {
            string u, t; int h, m, s;
            cin >> u >> t >> h >> m >> s;
            visit(u, t, h, m, s);
        }
        else if (choice == "2") moveBack();
        else if (choice == "3") moveForward();
        else if (choice == "4") deleteEntry();
        else if (choice == "5") displayHistory();
        else if (choice == "EXIT") clearMemory();
    }
    return 0;
}


    












