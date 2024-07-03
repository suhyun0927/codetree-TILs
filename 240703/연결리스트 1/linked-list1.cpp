#include <iostream>
#include <string>

using namespace std;

struct Node{
    string str;
    Node* pre;
    Node* next;
};

void printCur(Node* cur) {
    if (cur->pre == NULL) cout << "(Null) ";
    else cout << cur->pre->str << " ";

    cout << cur->str << " ";

    if (cur->next == NULL) cout << "(Null)\n";
    else cout << cur->next->str << "\n";
}

int main() {
    
    // S_init
    string init;
    cin >> init;

    Node* cur= new Node();
    cur->str = init;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 1) {
            string tmp;
            cin >> tmp;

            Node* n2 = new Node();
            n2->str = tmp;

            if (cur->pre == NULL) {
                n2->next = cur;
                cur->pre = n2;
            }
            else {
                n2->pre = cur->pre;
                cur->pre->next = n2;
                cur->pre = n2;
                n2->next = cur;
            }
            
            printCur(cur);
        }
        else if (num == 2) {
            string tmp;
            cin >> tmp;

            Node* n2 = new Node();
            n2->str = tmp;

            if (cur->next == NULL) {
                n2->pre = cur;
                cur->next = n2;
            }
            else {
                n2->next = cur->next;
                cur->next->pre = n2;
                cur->next = n2;
                n2->pre = cur;
            }
            
            printCur(cur);
        }
        else if (num == 3) {
            if (cur->pre != NULL) {
                Node* n2 = new Node();
                n2->pre = cur->pre;
                n2->next = cur->next;
                n2->str = cur->str;

                cur->pre = n2->pre->pre;
                cur = n2->pre;
                cur->next = n2;
            }

            printCur(cur);
        }
        else { // num == 4
            if (cur->next != NULL) {
                Node* n2 = new Node();
                n2->pre = cur->pre;
                n2->next = cur->next;
                n2->str = cur->str;

                cur->pre = n2;
                cur = n2->next;
                cur->next = n2->next->next;
            }

            printCur(cur);
        }
    }

    return 0;
}