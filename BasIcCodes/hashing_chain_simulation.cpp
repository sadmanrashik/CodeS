#include "stdc+.h"




vss hash_table(100001);
struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    /*
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }*/
    lli hash_func(string s) {
        lli hash = 0;
        for (int i = s.size() - 1; i >= 0; --i)
            hash = (hash * 263 + (int)s[i]) % 1000000007;
        return (hash % bucket_count);
    }
    
public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}
    
    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }
    
    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }
    
    void processQuery(const Query& query) {
                if (query.type == "check") {
            // use reverse order, because we append strings to the end
            if(!hash_table[query.ind].empty()){
                for (auto i = (hash_table[query.ind].end()-1); i >= hash_table[query.ind].begin(); --i)  //definite row reverse print
                {
                    cout << *i << " ";
                    
            
                }
                cout << "\n";
            }
            else cout << "\n";
        }
        else {
            size_t hash=hash_func(query.s);
            auto it = find(hash_table[hash].begin(),hash_table[hash].end(), query.s);

            if (query.type == "find")
                writeSearchResult(it != hash_table[hash].end());
            else if (query.type == "add") {
                if (it == hash_table[hash].end())
                    hash_table[hash].push_back(query.s);
            } else if (query.type == "del") {
                if (it != hash_table[hash].end())
                    hash_table[hash].erase(it);
            }
        }
    }
    
    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    fre;
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}

