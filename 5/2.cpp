#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
class MinHeap {
    private:
    vector<ll> heap;
    int parent(int i) { return (i-1)/2;}
    int left(int i) {return i*2+1;}
    int right(int i) {return i*2+2;}
    void heapifyUp(int i) {
        while (i>0&& heap[i]>heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i=parent(i);
        }
    }
    void heapifyDown(int i) {
        int smallest=i;
        int l=left(i);
        int r=right(i);
        int n=heap.size();
        if(l<n&&heap[l]>heap[smallest]) {
            smallest=l;
        } 
        if (r<n&& heap[r]>heap[smallest]) {
            smallest=r;
        }
        if(smallest!=i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    public:
    void push(ll val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    void pop() {
        if (heap.empty()) return;
        heap[0]=heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
    ll top () {
        return heap[0];
    }
    ll size() {
        return heap.size();
    }
    bool empty() {
        return heap.empty();
    }
};
int main () {

    int n;
    cin >> n;
    MinHeap pq;
    for (int i=0;i<n;i++) {
        int len;
        cin >> len;
        pq.push(len);
    }
    while(pq.size()>1) {
        ll first=pq.top();
        pq.pop();
        ll second=pq.top();
        pq.pop();
       
        if(first!=second) {
            pq.push(first-second);
        }
    }
    if (pq.empty()) {
        cout <<0;
    } else {
        cout << pq.top();
    }

    return 0;
}