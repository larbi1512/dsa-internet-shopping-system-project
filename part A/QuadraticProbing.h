#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include "item.h"
using namespace std;

int nextPrime(int n);

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 101) : array(nextPrime(size))
    {
        makeEmpty();
    }

    bool contains(const HashedObj &x) const
    {
        return isActive(findPos(x));
    }
    bool checkIndex(int n)
    {
        if (n >= 0 && n < array.size())
            return true;
        return false;
    }

    HashedObj &FindWithIndex(int n)
    {
        return array[n].element;
    }

    void makeEmpty()
    {
        currentSize = 0;
        for (auto &entry : array)
            entry.info = EMPTY;
    }

    bool insert(const HashedObj &x)
    {
        // Insert x as active
        int currentPos = findPos(x);
        if (isActive(currentPos))
            return false;

        if (array[currentPos].info != DELETED)
            ++currentSize;

        array[currentPos].element = x;
        array[currentPos].info = ACTIVE;

        // Rehash
        if (currentSize > array.size() / 2)
            rehash();

        return true;
    }

    bool insert(HashedObj &&x)
    {
        // Insert x as active
        int currentPos = findPos(x);
        if (isActive(currentPos))
            return false;

        if (array[currentPos].info != DELETED)
            ++currentSize;

        array[currentPos] = std::move(x);
        array[currentPos].info = ACTIVE;

        // Rehash; see Section 5.5
        if (currentSize > array.size() / 2)
            rehash();

        return true;
    }

    bool remove(const HashedObj &x)
    {
        int currentPos = findPos(x);
        if (!isActive(currentPos))
            return false;

        array[currentPos].info = DELETED;
        return true;
    }

    enum EntryType
    {
        ACTIVE,
        EMPTY,
        DELETED
    };

    void printTable()
    {
        cout << "\t\t\t\t -----------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t |  ID\t\t\t\t"
             << "Name \t\t\t\t"
             << "  Price\t\t\t"
             << "           Quantity |\t\t\t\t" << endl;
        cout << "\t\t\t\t ------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < array.size(); i++)
        {

            if (array[i].info == ACTIVE)
            {
                if (i >= 100)
                    cout << "\t\t\t\t |   " << i << "\t\t";
                else
                    cout << "\t\t\t\t |   " << i << "\t\t\t";
                array[i].element.Print();
            }
        }
        cout << "\t\t\t\t ----------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
    int getArraySize() const
    {
        return array.size();
    }

private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj &e = HashedObj{}, EntryType i = EMPTY)
            : element{e}, info{i} {}

        HashEntry(HashedObj &&e, EntryType i = EMPTY)
            : element{std::move(e)}, info{i} {}
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive(int currentPos) const
    {
        return array[currentPos].info == ACTIVE;
    }

    int findPos(const HashedObj &x) const
    {
        int offset = 1;
        int currentPos = myhash(x);

        while (array[currentPos].info != EMPTY &&
               array[currentPos].element != x)
        {
            currentPos += offset; // Compute ith probe
            offset += 2;
            if (currentPos >= array.size())
                currentPos -= array.size();
        }

        return currentPos;
    }

    void rehash()
    {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize(nextPrime(2 * oldArray.size()));
        for (auto &entry : array)
            entry.info = EMPTY;

        // Copy table over
        currentSize = 0;
        for (auto &entry : oldArray)
            if (entry.info == ACTIVE)
                insert(std::move(entry.element));
    }

    int myhash(const HashedObj &x) const
    {

        int result = 0;
        int tohash = x.getID();
        while (tohash != 0)
        {
            result += tohash % 10;
            result *= result;
            tohash /= 10;
        }
        return result % array.size();
    }
};

#endif