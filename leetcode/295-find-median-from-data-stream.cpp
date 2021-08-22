// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    struct node {
        int data;
        node * left;
        node * right;
    };

    node * root = NULL;
    int size = 0;
    double median = 0;
    int prev = 0;

    node * insert(node * t, const int x) {
        if(t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x <= t->data)
            t->left = insert(t->left, x);
        else if(x > t->data)
            t->right = insert(t->right, x);
        return t;
    }

    void getMedian(node * t, int & current, const int target) {
        if (t == NULL || current > target)
            return;

        getMedian(t->left, current, target);

        // Check itself
        if (current == target) {
            if (++current > 0 && size % 2 == 0)
                median = (double) (prev + t->data) / 2;
            else
                median = t->data;
            return;
        }
        prev = t->data;
        ++current;

        getMedian(t->right, current, target);
    }

    // Debugging purposes
    void inorder(node * t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        root = insert(root, num);
        ++size;
    }

    double findMedian() {
        int current = 0;
        getMedian(root, current, size/2);
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */