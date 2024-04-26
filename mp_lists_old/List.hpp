/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List(): head_(nullptr), tail_(nullptr) { 
  // @TODO: graded in MP3.1
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(nullptr);
}


/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(nullptr);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
    ListNode * current = head_;
    while (current != nullptr) {
        ListNode * next = current->next;
        delete current;
        current = next;
    }
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = nullptr;
  
  if (head_ != nullptr) {
    head_ -> prev = newNode;
  }
  if (tail_ == nullptr) {
    tail_ = newNode;
  }
  

  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
    ListNode * newNode = new ListNode(ndata);
    newNode->prev = tail_;
    newNode->next = nullptr;
    
    if (tail_ != nullptr) {
        tail_->next = newNode;
    }
    
    tail_ = newNode;
    
    if (head_ == nullptr) {
        head_ = newNode;
    }

    length_++;
}


/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
    if (start == nullptr || splitPoint <= 0) {
        return nullptr;
    }

    ListNode * current = start;
    for (int i = 0; i < splitPoint && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        current->prev->next = nullptr;
        current->prev = nullptr;
    }

    return current;
}


/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
    if (head_ == nullptr || head_->next == nullptr || head_->next->next == nullptr) {
        return; // Not enough nodes to perform rotation
    }

    ListNode *current = head_;
    while (current != nullptr && current->next != nullptr && current->next->next != nullptr) {
        ListNode *temp1 = current;
        ListNode *temp2 = current->next;
        ListNode *temp3 = current->next->next;

        // Perform rotation
        temp2->prev = nullptr;
        temp1->next = temp3->next;
        temp2->next = temp3->next;
        temp3->next = temp1;

        // Update head pointer if needed
        if (temp1 == head_) {
            head_ = temp2;
        }

        current = temp1->next;
    }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  if (startPoint == nullptr || endPoint == nullptr || startPoint == endPoint) {
    // Nothing to reverse or only one node in the sequence
    return;
  }

  ListNode *prev = nullptr;
  ListNode *current = startPoint;
  ListNode *next = nullptr;

  while (current != nullptr && current != endPoint->next) {
    next = current->next;
    current->next = prev;
    current->prev = next; // Update previous pointer for bidirectional linked list
    prev = current;
    current = next;
  }

  // Update startPoint and endPoint
  endPoint->prev = startPoint->prev;
  startPoint->prev = current;
  startPoint = endPoint;
  endPoint = prev;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
    ListNode * start = head_;
    ListNode * end = nullptr;

    while (start != nullptr) {
        int count = 1;
        end = start;
        while (count < n && end->next != nullptr) {
            end = end->next;
            count++;
        }
        reverse(start, end);
        start = end->next;
    }
}



/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode* List<T>::merge(ListNode * first, ListNode* second) {
    if (first == nullptr) // Handle empty first list
        return second;
    else if (second == nullptr) // Handle empty second list
        return first;

    ListNode* result = nullptr;
    ListNode* current = nullptr;

    // Determine the head of the merged list
    if (first->data <= second->data) {
        result = first;
        first = first->next;
    } else {
        result = second;
        second = second->next;
    }
    current = result;

    // Merge the rest of the lists
    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            current->next = first;
            first->prev = current;
            first = first->next;
        } else {
            current->next = second;
            second->prev = current;
            second = second->next;
        }
        current = current->next;
    }

    // Attach remaining nodes
    if (first != nullptr) {
        current->next = first;
        first->prev = current;
    } else if (second != nullptr) {
        current->next = second;
        second->prev = current;
    }

    return result; // Return the head of the merged list
}



/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
    if (chainLength <= 1 || start == nullptr || start->next == nullptr) {
        return start;
    }

    int mid = chainLength / 2;
    ListNode *middle = split(start, mid);
    ListNode *left = mergesort(start, mid);
    ListNode *right = mergesort(middle, chainLength - mid);

    return merge(left, right);
}

