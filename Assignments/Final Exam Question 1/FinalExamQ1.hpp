// This code is made with the help of claude.ai and the tree class from GitHub. The prompt is the question along with the tree class.
#pragma once
#include <memory>
#include <functional>
#include <cassert>
using namespace std;

template<class T>
class Tree
{
    struct Node
    {
        Node(std::shared_ptr<const Node> const& lft
            , T val
            , std::shared_ptr<const Node> const& rgt)
            : _lft(lft), _val(val), _rgt(rgt)
        {}

        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
    };

    explicit Tree(std::shared_ptr<const Node> const& node)
        : _root(node) {}

    unsigned int numberOfNodes = 0;
public:
    
    Tree() {}

    Tree(Tree const& lft, T val, Tree const& rgt)
        : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || val < rgt.root());
    }

    Tree(std::initializer_list<T> init) {
        Tree t;
        for (T v : init) {
            t = t.insert(v);
        }
        _root = t._root;
    }

    bool isEmpty() const { return !_root; }

    size_t size() { return numberOfNodes; }

    T root() const {
        assert(!isEmpty());
        return _root->_val;
    }


    Tree left() const {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }

    Tree right() const {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }

    Tree insert(T x) {
        numberOfNodes++;
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this; 
    }

    bool member(T x) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    bool find(T x, T& foundValue) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().find(x);
        else if (y < x)
            return right().find(x);
        else {
            foundValue = y;
            return true;
        }
    }

    void preorder(std::function<void(T)> visit) const {
        if (isEmpty())
            return;
        T contents = root();
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().inorder(visit);
        T contents = root();
        visit(contents);
        right().inorder(visit);
    }

    void postorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().postorder(visit);
        right().postorder(visit);
        T contents = root();
        visit(contents);
    }

private:
    std::shared_ptr<const Node> _root;
};

template<typename T>
int countNodes(const Tree<T>& tree) {
    if (tree.isEmpty()) {
        return 0;
    }

    return 1 + countNodes(tree.left()) + countNodes(tree.right());
}

template<typename T>
int countInternalNodes(const Tree<T>& tree) {
    if (tree.isEmpty()) {
        return 0;
    }

    if (tree.left().isEmpty() && tree.right().isEmpty()) {
        return 0;
    }

    return 1 + countInternalNodes(tree.left()) + countInternalNodes(tree.right());
}

template<typename T>
void externalPathLength(const Tree<T>& tree, int& sum, int currentDepth = 0) {
    if (tree.isEmpty()) {
        return;
    }

    if (tree.left().isEmpty() && tree.right().isEmpty()) {
        sum += currentDepth;
        return;
    }

    externalPathLength(tree.left(), sum, currentDepth + 1);
    externalPathLength(tree.right(), sum, currentDepth + 1);
}