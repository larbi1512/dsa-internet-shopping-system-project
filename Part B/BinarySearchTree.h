// LARBI SAIDCHIKH
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include "item.h"

using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// item findMin( )  --> Return smallest item
// item findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }

    /**
     * Move constructor
     */
    BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree()
    {
        makeEmpty();
    }

    /**
     * Copy assignment
     */
    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        BinarySearchTree copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    /**
     * Move assignment
     */
    BinarySearchTree &operator=(BinarySearchTree &&rhs)
    {
        std::swap(root, rhs.root);
        return *this;
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const item &findMin() const
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMin(root)->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const item &findMax() const
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMax(root)->element;
    }
    item &find(int &itemkey)
    {
        if (isEmpty())
            throw UnderflowException{};
        return find(root, itemkey)->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains(const item &x) const
    {
        return contains(x, root);
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree(ostream &out = cout) const
    {
        if (isEmpty())

            cout << "Empty tree" << endl;
        else
        {
            cout << "\t\t\t\t -----------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t |  ID\t\t\t\t"
                 << "Name \t\t\t\t"
                 << "  Price\t\t\t"
                 << "           Quantity |\t\t\t\t" << endl;
            cout << "\t\t\t\t ------------------------------------------------------------------------------------------------------------" << endl;
            printTree(root, cout);
            cout << "\t\t\t\t ----------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
        }
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
        makeEmpty(root);
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert(const item &x)
    {
        insert(x, root);
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert(item &&x)
    {
        insert(std::move(x), root);
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const item &x)
    {
        remove(x, root);
    }

private:
    struct BinaryNode
    {
        item element;
        int key;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const item &theElement, const int &k, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, key{k}, left{lt}, right{rt} {}

        BinaryNode(item &&theElement, int &&k, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, key{k}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(const item &x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, x.getID(), nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);
        else
            ; // Duplicate; do nothing
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(item &&x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{std::move(x), x.getID(), nullptr, nullptr};
        else if (x < t->element)
            insert(std::move(x), t->left);
        else if (t->element < x)
            insert(std::move(x), t->right);
        else
            ; // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const item &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return; // Item not found; do nothing
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }
    BinaryNode *find(BinaryNode *t, int &itemkey)
    {
        if (t == nullptr)
            return nullptr;
        else if (itemkey < t->key)
            return find(t->left, itemkey);
        else if (t->key < itemkey)
            return find(t->right, itemkey);
        else
            return t;
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains(const item &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (t->element < x)
            return contains(x, t->right);
        else
            return true; // Match
    }
    /****** NONRECURSIVE VERSION*************************
        bool contains( const item & x, BinaryNode *t ) const
        {
            while( t != nullptr )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return true;    // Match

            return false;   // No match
        }
    *****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree(BinaryNode *t, ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            cout << "\t\t\t\t |   " << t->key << "\t\t";
            t->element.PrintBILL();
            printTree(t->right, out);
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{t->element, t->element.getID(), clone(t->left), clone(t->right)};
    }
};
BinarySearchTree MenItems;
BinarySearchTree WomenItems;
BinarySearchTree KidsItems;
#endif
