
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>

using namespace std;


int main () {
    Scanner S(cin);
    Token t;
    
    Stack<Token> numstack;
    Stack<Token> opstack;  // 2x Stacks of type Token
    
    t = S.getnext();
   
    while (t.tt != eof || !opstack.isEmpty()) {
        if(t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        
        else if(t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        
        else if(t.tt == rptok)
        {
            if(opstack.peek().tt==lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                Token one = numstack.pop();
                Token two = numstack.pop();
                Token sub_operator = opstack.pop();
                Token operation;
                
                if(sub_operator.tt==pltok)
                    operation.val = one.val + two.val;
                else if(sub_operator.tt==mitok)
                    operation.val =two.val - one.val  ;
                else if(sub_operator.tt==slashtok)
                    operation.val = two.val/one.val;
                else if(sub_operator.tt==asttok)
                    operation.val = one.val*two.val;
                
                operation.text = to_string(operation.val);
                operation.tt = integer;
                numstack.push(operation);
            }
        }
        else if(t.tt==pltok || t.tt==mitok || t.tt==eof)
        {
            if(!opstack.isEmpty() && (opstack.peek().tt==pltok || opstack.peek().tt==mitok || opstack.peek().tt==slashtok || opstack.peek().tt==asttok))
            {
                Token num_1 = numstack.pop();
                Token num_2 = numstack.pop();
                Token operation_ = opstack.pop();

                if(operation_.tt==pltok)
                    operation_.val = num_1.val + num_2.val;
                else if(operation_.tt==mitok)
                    operation_.val = num_2.val - num_1.val ;
                else if(operation_.tt==slashtok)
                    operation_.val = num_2.val/num_1.val;
                else if(operation_.tt==asttok)
                    operation_.val = num_1.val*num_2.val;
                
                operation_.text = to_string(operation_.val);
                operation_.tt = integer;
                numstack.push(operation_);
            }
            else
            {
                opstack.push(t);        
                t = S.getnext();
            }
        }
        else if(t.tt==asttok || t.tt==slashtok)
        {
            if(!opstack.isEmpty() && (opstack.peek().tt==asttok || opstack.peek().tt==slashtok))
            {
                Token first = numstack.pop();
                Token second = numstack.pop();
                Token result = opstack.pop();

                if(result.tt==pltok)
                    result.val = first.val + second.val;
                else if(result.tt==mitok)
                    result.val = second.val-first.val;
                else if(result.tt==slashtok)
                    result.val = second.val/first.val;
                else if(result.tt==asttok)
                    result.val = first.val*second.val;
                
                result.text = to_string(result.val);
                result.tt = integer;
                numstack.push(result);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }
    Token answer = numstack.peek();
    std::cout<<answer;
    return numstack.peek().val;
}

