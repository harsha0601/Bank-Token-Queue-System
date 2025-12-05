#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int tokenNo;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;
int nextToken = 1;
int totalTokens = 0;

// Queue operations
struct Node* createNode(int token) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->tokenNo = token;
    newNode->next = NULL;
    return newNode;
}

void enqueue() {
    struct Node *newNode = createNode(nextToken);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    totalTokens++;
    nextToken++;
}

void dequeue() {
    if (front == NULL) return;
    struct Node *temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    totalTokens--;
}

int queueSize() {
    int size = 0;
    struct Node *temp = front;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}

int currentCustomer() {
    return front ? front->tokenNo : 0;
}

void displayQueue(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    
    mvwprintw(win, 1, 2, "Bank Token Queue System");
    mvwprintw(win, 3, 2, "Queue Size: %d | Total Served: %d", queueSize(), totalTokens - queueSize());
    
    if (currentCustomer()) {
        mvwprintw(win, 5, 2, "Current Serving: #%d", currentCustomer());
    } else {
        mvwprintw(win, 5, 2, "No customer at counter");
    }
    
    mvwprintw(win, 7, 2, "Waiting Queue:");
    struct Node *temp = front ? front->next : NULL;
    int row = 9;
    while (temp && row < 18) {
        mvwprintw(win, row, 4, "Token #%d", temp->tokenNo);
        temp = temp->next;
        row++;
    }
    wrefresh(win);
}

void cleanup() {
    while (front) {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    
    // Windows setup
    WINDOW *menuWin = newwin(12, 45, 2, 2);
    WINDOW *queueWin = newwin(20, 55, 2, 50);
    box(menuWin, 0, 0);
    box(queueWin, 0, 0);
    
    int ch;
    refresh();
    
    while (1) {
        displayQueue(queueWin);
        
        // Menu display
        werase(menuWin);
        box(menuWin, 0, 0);
        mvwprintw(menuWin, 1, 2, "Bank Counter Control");
        mvwprintw(menuWin, 3, 2, "1. Issue New Token");
        mvwprintw(menuWin, 4, 2, "2. Serve Next Customer");
        mvwprintw(menuWin, 5, 2, "3. Show Statistics");
        mvwprintw(menuWin, 6, 2, "4. Clear All Queue");
        mvwprintw(menuWin, 7, 2, "5. Next Token: #%d", nextToken);
        mvwprintw(menuWin, 9, 8, "Press 1-5 keys:");
        
        wrefresh(menuWin);
        ch = getch();
        
        switch (ch) {
            case '1':
                enqueue();
                mvwprintw(menuWin, 11, 2, "Token #%d issued! [Press any key]", nextToken-1);
                wrefresh(menuWin);
                getch();
                break;
                
            case '2':
                if (front) {
                    int served = currentCustomer();
                    dequeue();
                    mvwprintw(menuWin, 11, 2, "Served Token #%d! [Press any key]", served);
                } else {
                    mvwprintw(menuWin, 11, 2, "No customers waiting! [Press any key]");
                }
                wrefresh(menuWin);
                getch();
                break;
                
            case '3':
                mvwprintw(menuWin, 11, 2, "Size:%d Served:%d Next:%d [Press any key]", 
                         queueSize(), totalTokens - queueSize(), nextToken);
                wrefresh(menuWin);
                getch();
                break;
                
            case '4':
                cleanup();
                mvwprintw(menuWin, 11, 2, "Queue cleared! [Press any key]");
                nextToken = 1;
                totalTokens = 0;
                wrefresh(menuWin);
                getch();
                break;
                
            case '5':
                cleanup();
                endwin();
                return 0;
                
            default:
                mvwprintw(menuWin, 11, 2, "Invalid choice! Use 1-5 [Press any key]");
                wrefresh(menuWin);
                getch();
                break;
        }
        werase(menuWin);
    }
    
    endwin();
    return 0;
}
