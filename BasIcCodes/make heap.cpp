#include "stdc++.h"
//freopen("input.txt", "r", stdin);


class HeapBuilder {
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;
    
    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }
    
    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }
    void SiftDown(int r,vector<int> &data){
        int left=2*r+1;  //left child index
        int right=2*r+2; //right child index
        int min_index=r;
        if( left>=data.size() && right>=data.size() ){
            return;
        }
        if(left<data.size() && data[left]<data[min_index])
        {
            min_index=left;
        }
        if(right<data.size() && data[right]<data[min_index])
        {
            min_index=right;
        }
        if (r!=min_index){
            swap(data[r], data[min_index]);
            swaps_.push_back(make_pair(r, min_index));
            SiftDown(min_index, data);
        }
        
        
    }
    
    void GenerateSwaps() {
        //building heap
        swaps_.clear();
        // The following naive implementation just sorts
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap,
        // but in the worst case gives a quadratic number of swaps.
        //
        // TODO: replace by a more efficient implementation
//        for (int i = 0; i < data_.size(); ++i)
//        {
//            SiftDown(i, data_);
//        }
        int half_size=floor(data_.size()/2);  //to get prevous level of last level//divide by 2 //binary tree rule
        for (int i = half_size; i >=0 ; --i)
        {
            SiftDown(i, data_);
        }
    }
    
    
public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
