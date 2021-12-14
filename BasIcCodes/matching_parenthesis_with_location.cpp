#include <algorithm>

#include <vector>
#include <cmath>
#include <numeric>

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
    type(type),
    position(position)
    {}
    
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    
    char type;
    int position;
};

int main() {
    //freopen("input.txt", "r", stdin);
    string text;
    getline(cin, text);
    //debug(text);
    
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        //algo, push=opening, if closing match, pop ; else retrun closing bracket location.works (+1 for indexing issue, no rocket science here)
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next,position));
        }
        //matching logic=difference of ascii value of any (left-right parenthesis is at most 2 ,for matching pair)
        
        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            //debug((int)temp.type);debug((int)next);
            if(opening_brackets_stack.empty()){cout<<position+1;return 0;}
            else{
                Bracket temp = opening_brackets_stack.top();
                //debug((int)temp.type);debug((int)next);
                int same_match=abs((int)temp.type-(int)next);
                if(same_match<=2){
                    opening_brackets_stack.pop();
                }
                else {cout<<position+1; return 0;}
                
            }
            
            
        }
    }
    if(opening_brackets_stack.empty()){cout<<"Success";}
    else cout<<opening_brackets_stack.top().position+1;
    
    // Printing answer, write your code here
    
    return 0;
}
