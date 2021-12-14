#include "stdc+.h"

void add_queries_pro_del_print() {
    umis::iterator it;
    int n;
    cin >> n;
    umis tmp;
    string type, name;
    int number;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if (type == "add"){
            cin >> number >> name;
            
            it=tmp.find(number);
            if (it != tmp.end()){
                it->se=name;
            }
            else {
                
                tmp.insert(mp(number,name));
            }
            
        }
        else if(type=="find"){
            cin >> number;
            it=tmp.find(number);
            if (it != tmp.end()){
                cout<<it->se<<"\n";
                
            }
            else cout<<"not found"<<"\n";
            
            
        }
        else if(type=="del"){
            cin >> number;
            it=tmp.find(number);
            if (it != tmp.end()){
                tmp.erase(it);
            }
            
        }
    }
    return ;
}





int main() {
    fre;
    add_queries_pro_del_print();
    
    return 0;
}
