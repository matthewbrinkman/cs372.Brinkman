template<typename V>
class Tree {
private:
    struct Node {
        Node(V v, shared_ptr<Node>& l, shared_ptr<Node>Node& r) :
            value(v), left(l), right(r) {}
        V value;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
    };
    explicit Tree(shared_ptr<Node>& node) : root(node) {}
    shared_ptr<Node> root;
public:
    Tree() {}
    Tree(Tree const& lft, V value, Tree const& rgt) :
        root(Node(val, lft->root, rgt->root)) {}

    bool isEmpty() const { return !root; }
    V root() const { return root->val; }
    Tree& left() const { return root->left; }
    Tree& right() const { return root->right; }

    bool member(V x) const;
};

template<typename V>
bool Tree<V>::member(V x) const
{
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

