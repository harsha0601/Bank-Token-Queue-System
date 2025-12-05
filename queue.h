#ifndef QUEUE_H
#define QUEUE_H

/**
 * Node structure for linked list queue
 * tokenNo: unique token number for each customer
 * next: pointer to the next node in the queue
 */
struct Node {
    int tokenNo;
    struct Node *next;
};

/**
 * Function Declarations
 */

/**
 * createNode - Create a new node with given token number
 * @token: token number to be assigned
 * Returns: pointer to newly created node
 */
struct Node* createNode(int token);

/**
 * enqueue - Add new customer to the end of queue
 * Increments nextToken counter automatically
 */
void enqueue();

/**
 * dequeue - Remove and serve customer from front of queue
 * Frees the dequeued node from memory
 */
void dequeue();

/**
 * queueSize - Get current number of customers waiting
 * Returns: number of nodes in queue
 */
int queueSize();

/**
 * currentCustomer - Get token number of customer at counter
 * Returns: token number of front customer, or 0 if queue empty
 */
int currentCustomer();

/**
 * displayQueue - Display queue in ncurses window
 * @win: pointer to ncurses WINDOW for display
 */
void displayQueue(WINDOW *win);

/**
 * cleanup - Free all nodes in queue and reset pointers
 */
void cleanup();

#endif
