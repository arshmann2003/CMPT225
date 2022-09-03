#include <cmath>
#include "hash.h"
#include "Scanner.h"
#include "Parse.h"
#include "assert.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define tabstop 4



class var {
    public:
        string key;
        int val;
    var(string key):key(key), val(0){};
        // * * * add some more attributes and methods here * * * //

};



// * * * declare more things here * * * //


Set<var> memmap;
int run(StmtsNode *stmts);


int run(StmtsNode *stmts) {
    return 0;
}



///////////////////////////////////////////////
//----- carried over from testParse.cpp -----//
///////////////////////////////////////////////

// Desc:  These 3 functions return a string which is a pretty-printed
//        version of the subtree rooted there.
string printE(ExpnNode *root);
string printStmts(StmtsNode *root, int ilevel);
string print(StmtsNode *root);


// Desc:  Generate pretty printed pish of the parse tree rooted at root.
string print(StmtsNode *root) {
    return printStmts(root, 0);  // call helper
}


// Desc:  Generate pretty printed pish, by traversing like a linked list.
//        Parameter ilevel is the indentation level.
string printStmts(StmtsNode *root, int ilevel) {
    // generate leading tab
    string spc = "", tab = "";
    for (int i = 0; i < tabstop; i++) spc += " ";
    for (int i = 0; i < ilevel; i++) tab += spc;


    // traverse StmtsNode * like it is a linked list
    StmtsNode *cur = root;
    string accum = "";  // pretty-printed version


    while (cur != NULL) {
        assert(cur->stmt != NULL);

        // print statement
        if (cur->stmt->tok == printtok) {
            accum += tab + toktotext(printtok) + " " + printE(cur->stmt->expn) + toktotext(sctok) + "\n";
        }
        // assignment statement
        else if (cur->stmt->tok == asgntok) {
            accum += tab + cur->stmt->ident + " " + toktotext(asgntok) + " " + printE(cur->stmt->expn) + toktotext(sctok) + "\n";
        }
        // while statement: tab level increases for subStmts
        else if (cur->stmt->tok == whiletok) {
            accum += tab + toktotext(whiletok) + " " + printE(cur->stmt->expn) + " " + toktotext(lctok) + "\n" + printStmts(cur->stmt->stmts, ilevel+1) + tab + toktotext(rctok) + "\n";
        }
        // if/elif/else statement: tab level increases for subStmts
        else if (cur->stmt->tok == iftok) {
            StmtNode *elif = cur->stmt;
            while (elif != NULL) {
                accum += tab + toktotext(elif->tok) + ((elif->tok == elsetok) ? "" : (" " + printE(elif->expn))) + " " + toktotext(lctok) + "\n" + printStmts(elif->stmts, ilevel+1) + tab + toktotext(rctok) + "\n";
                elif = elif->elif;
            }
        }
        // break statement
        else if (cur->stmt->tok == breaktok) {
            accum += tab + toktotext(breaktok) + toktotext(sctok) + "\n";
        }
        else { assert(0); }


        // next node in the chain
        cur = cur->stmts;
    }
    return accum;
}


// Desc:  Generate bracketed infix via postorder traversal
string printE(ExpnNode *root) {
    if (root == NULL) return "";
    if (root->text != "") return root->text;
    if (root->left_operand == NULL) return "(" + toktotext(root->tok) + ((root->tok == nottok) ? " " : "") + printE(root->right_operand) + ")";
    else return "(" + printE(root->left_operand) + " " + toktotext(root->tok) + " " + printE(root->right_operand) + ")";
}




int evaluate(ExpnNode *expn)
{
    if(expn==NULL)
        return 0;

    if(memmap.search(expn->text))
        if(memmap.search(expn->text)->key==expn->text)
            return memmap.search(expn->text)->val;    

    if(expn->tok==nottok)
        return !evaluate(expn->right_operand);
    
    if(expn->left_operand==NULL && expn->right_operand==NULL)
        return stoi(expn->text);
    
    int num1 = evaluate(expn->left_operand);

    if(num1==0 && toktotext(expn->tok)=="*")
        return 0;
    if(num1==0 && toktotext(expn->tok)=="/")
        return 0;
    if(num1==0 && toktotext(expn->tok)=="and")
        return 0;
    if(num1!=0 && toktotext(expn->tok)=="or")
        return 1;

    int num2 = evaluate(expn->right_operand);
        
    if(toktotext(expn->tok) == "+")
        return num1+num2;
    else if(toktotext(expn->tok) == "-")
        return num1-num2;
    else if(toktotext(expn->tok)=="*")
        return num1*num2;
    else if(toktotext(expn->tok) =="/")
    {
        if((num2>0 && num1>0) || (num2<0 && num1<0))
            return num1/num2;
        else if((num2<0 && num1>0) || (num1<0 && num2>0)) 
        {
            float x = num1;
            float y = num2;
            float num = x/y;
            return floor(num);
        }
        else
            throw std::runtime_error("Divison by 0");
    }
    else if(toktotext(expn->tok)==">")
        return num1>num2;
    else if(toktotext(expn->tok)=="<")
        return num1<num2;
    else if(toktotext(expn->tok)==">=")
        return num1>=num2;
    else if(toktotext(expn->tok)== "<=")
        return num1<=num2;
    else if(toktotext(expn->tok)== "==")
        return num1==num2;
    else if(toktotext(expn->tok)=="!=")
        return num1!=num2;
    else if(toktotext(expn->tok)=="and")
        return num1&&num2;
    else if(toktotext(expn->tok)=="or")
        return num1||num2;

    return 0;
}

void print_helper(StmtNode *stmt);
void assign_helper(StmtNode *stmt);
void if_helper(StmtsNode *x);
void while_helper(StmtsNode *x);

vector<var *> pointers_to_delete;


void print_helper(StmtNode *stmt){
    cout << evaluate(stmt->expn) << "\n";
}
void assign_helper(StmtNode *stmt){
    var *newNode = new var(stmt->ident);
    pointers_to_delete.push_back(newNode);
    newNode->val = evaluate(stmt->expn);
    memmap.insert(newNode);
}
void if_helper(StmtsNode *x){
    if(x==NULL)
        return;

    StmtsNode *sub_curr = x;
    while(sub_curr)
    {
        if(sub_curr->stmt->tok==printtok)
            print_helper(sub_curr->stmt);
        else if(sub_curr->stmt->tok==asgntok)
            assign_helper(sub_curr->stmt);
        else if(sub_curr->stmt->tok == iftok)
        {
            if(evaluate(sub_curr->stmt->expn)){
                if_helper(sub_curr->stmt->stmts);
            }
            else if(sub_curr->stmt->elif)
            {
                StmtNode *sub = sub_curr->stmt->elif;
                while(sub)
                {
                    if(sub->tok==elsetok)
                    {
                        if_helper(sub->stmts);
                        break;
                    }
                    else if(evaluate(sub->expn)){
                        if_helper(sub->stmts);
                        break;
                    }
                    sub = sub->elif;
                }   
            }
        }
        else if(sub_curr->stmt->tok==whiletok)
        {
            while(evaluate(sub_curr->stmt->expn))  
                while_helper(sub_curr->stmt->stmts);
        }
        else if(sub_curr->stmt->tok==breaktok)
            break;
        sub_curr = sub_curr->stmts;
    }
}
void while_helper(StmtsNode *x){
    if(x==NULL)
        return;

    StmtsNode *sub_curr = x;    
    while(sub_curr)
    {
        if(sub_curr->stmt->tok==printtok)
            print_helper(sub_curr->stmt);
        else if(sub_curr->stmt->tok==asgntok)
            assign_helper(sub_curr->stmt);
        else if(sub_curr->stmt->tok==iftok)
        {
            if(evaluate(sub_curr->stmt->expn)){
                if_helper(sub_curr->stmt->stmts);
            }
            else if(sub_curr->stmt->elif)
            {
                StmtNode *sub = sub_curr->stmt->elif;
                while(sub)
                {
                    if(sub->tok==elsetok)
                    {
                        if_helper(sub->stmts);
                        break;
                    }
                    else if(evaluate(sub->expn)){
                        if_helper(sub->stmts);
                        break;
                    }
                    sub = sub->elif;
                }   
            }
        }
        else if(sub_curr->stmt->tok==whiletok)
        {
            while(evaluate(sub_curr->stmt->expn))
                while_helper(sub_curr->stmt->stmts);
        }
        else if(sub_curr->stmt->tok==breaktok)
            break;
        sub_curr = sub_curr->stmts;
    }
}


int main () {
    StmtsNode *pTree;
    try {
        pTree = Parse(cin);
    }
    catch(string s) {
        cout << "Parse error: " << s << endl;
        return 0;
    }
    
    StmtsNode *curr = pTree;
    while(curr)
    {
        if(curr->stmt->tok == printtok)
            print_helper(curr->stmt);       
        
        else if(curr->stmt->tok == asgntok)
            assign_helper(curr->stmt);

        else if(curr->stmt->tok == iftok)
        {
            
            if(evaluate(curr->stmt->expn))
                if_helper(curr->stmt->stmts);
            else if(curr->stmt->elif)
            {
                StmtNode *sub = curr->stmt->elif;
                while(sub)
                {
                    if(sub->tok==elsetok){
                        if_helper(sub->stmts);
                        break;
                    }    
                    else if(evaluate(sub->expn)){
                        if_helper(sub->stmts);  
                        break;  
                    }
                    sub = sub->elif;
                }
            }
        }
        else if(curr->stmt->tok == whiletok)
        {
            while(evaluate(curr->stmt->expn))
                while_helper(curr->stmt->stmts);
        }
        curr = curr->stmts;
    }
    for(int i=0; i<pointers_to_delete.size(); i++)
        delete pointers_to_delete[i];
    
    run(pTree);
    delete pTree;
}

