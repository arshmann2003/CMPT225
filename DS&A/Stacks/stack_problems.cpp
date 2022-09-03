#include <iostream>
#include "Stack_LL.hpp"
#include <string.h>

std::string reverse_in_place(std::string word)
{
    if(word.length()<=1)
        return word;

    int  n = word.length()-1;
    for (int i = 0; i < word.length()/2; i++) 
    {
        char temp = word[i];
        word[i] = word[n];
        word[n] = temp;
        n--;
    }       
    return word;
}

bool single_parenthesisMatching(std::string word)
{   
    Stack_LL<char> check;

    for(int i=0; i<word.length(); i++)
    {
        if(word[i]=='(')
            check.push(word[i]);
        else if(word[i]==')')
        {
            if(check.isEmpty())
                return false;
            check.pop();
        }
    }
    if(check.isEmpty())
        return true;
    return false;
}

bool multiple_parenthesisMatching(std::string word)
{
    Stack_LL<char> stack;
    char brack;

    for(int i=0; i<word.length(); i++)
    {
        if(word[i]=='(' || word[i] == '[' || word[i]=='{')
            stack.push(word[i]);
        else if(word[i]==')' || word[i] == ']' || word[i]=='}')
        {
            if(stack.isEmpty())
                return false;
            
            brack = stack.pop();
            
            if(word[i]==')')
                if(brack!='(')
                    return false;
            
            if(word[i]==']')
                if(brack!='[')
                    return false;
            
            if(word[i]=='}')
                if(brack!='{')
                    return false;
        }
    }
    if(stack.isEmpty())
        return true;
    return false;
}

std::string reverse_using_stack(std::string word)
{
    Stack_LL<char> stack;
    for(int i=0; i<word.length(); i++)
    {
        stack.push(word[i]);
    }
    for(int i=0; i<word.length(); i++)
    {
        word[i]=stack.pop();
    }  
    return word;
}


int evaluate(std::string word)
{
    Stack_LL<char> stack;
    int num;    

    for(int i=0; i<word.length(); i++)
    { 
        
    }

}


int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='/' || x=='*')
        return 0;
    return 1;
}

int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}


char *convert(std::string infix)
{
    Stack_LL<char> stack;
    char *postfix = new char[infix.length()+1];
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i])>pre(stack.peek()))
                stack.push(infix[i++]);
            else
            {
                postfix[j++] = stack.pop();
            }
        }
    }
}

int evalPost(string postfix)
{
    int n = postfix.size();

    Stack_LL<char> stack;
    for(int i=0; i<n; i++)
    {
        if(postfix[i].isdigit())
        {
            stack.push(postfix[i]);
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/' || postfix[i]=='*')
        {
            int num2 = stack.pop();
            int num1 = stack.pop();
            
        }
    }

}

int main()
{
    std::string word = "{[()]}";
    if(multiple_parenthesisMatching(word))
        std::cout << "YES";
    else
        std::cout<<"NO";
    std::cout<<"\n";

    std::string word_2 = "ARSH";
    std::cout<<reverse_using_stack(word_2);
    std::cout<<"\n";


    char h = '4';
    int g = h;
    std:: cout << h;
    return 0;
}
