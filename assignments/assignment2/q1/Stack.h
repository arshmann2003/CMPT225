


// Desc:  Implementation of an int sequence with push/pop in a LIFO order
class Stack {

    private:

        // Desc:  arr = static array of capacity STACKCAP
        //        size = the number of elements presently in the stack
        //  Inv:  Follows the A2 Spec, namely that the stack elements 
        //        are in order within A[0..size-1], where the top of
        //        the stack is A[0].
        static const unsigned STACKCAP = 8;
        int arr[STACKCAP];
        unsigned size;

    public:

        // Desc:  Object constructor
        // Post:  stack size is set to 0
        Stack();


        // Desc  Insert element x to the top of the stack.
        //  Pre:  If there is space to: push to the stack
        // Post:  element is pushed to the top of the stack
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty
        // Post:  returns the top element, and decrements size
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Is not empty
        // Post:  returns the top most element of the stack
        int peek() const;

        // Desc:  Check if stack is empty
        // Post:  return true if the stack is empty, else return false
        bool isEmpty() const;

};


