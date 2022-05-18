#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

#include "OrgNode.hpp"

namespace ariel {
class OrgIterator {
   protected:
    OrgNode *node_;

   public:
    OrgIterator() : node_(nullptr) {}                              // default constructor
    OrgIterator(OrgNode *node) : node_(node) {}                    // constructor
    OrgIterator(const OrgIterator &other) : node_(other.node_) {}  // copy constructor

    OrgIterator &operator=(const OrgIterator &other);  // assignment operator

    virtual OrgIterator &operator++() = 0;  // prefix increment operator
    OrgIterator &operator++(int);           // postfix increment operator

    OrgNode *operator->() const;  // returns the node
    OrgNode &operator*() const;   // returns the node

    bool operator!=(const OrgIterator &other) const;  // returns true if both iterators point to different nodes
    bool operator==(const OrgIterator &other) const;  // returns true if both iterators point to the same node

};

class OrgLevelOrderIterator : public OrgIterator {
   public:
    OrgLevelOrderIterator() : OrgIterator() {}                                                               // constructor
    OrgLevelOrderIterator(OrgNode *node) : OrgIterator(node), queue_(std::queue<OrgNode *>()) {}             // constructor
    OrgLevelOrderIterator(const OrgLevelOrderIterator &other) : OrgIterator(other), queue_(other.queue_) {}  // copy constructor

    OrgLevelOrderIterator &operator++();  // prefix increment operator
   private:
    std::queue<OrgNode *> queue_;
};

class OrgReverseLevelOrderIterator : public OrgIterator {
   public:
    OrgReverseLevelOrderIterator() : OrgIterator() {}                                                // constructor
    OrgReverseLevelOrderIterator(OrgNode *node) : OrgIterator(node) {}                               // constructor
    OrgReverseLevelOrderIterator(const OrgReverseLevelOrderIterator &other) : OrgIterator(other) {}  // copy constructor

    OrgReverseLevelOrderIterator &operator++();  // prefix increment operator
};

class OrgPreOrderIterator : public OrgIterator {
   public:
    OrgPreOrderIterator() : OrgIterator(), stack_(std::stack<OrgNode *>()) {}                            // constructor
    OrgPreOrderIterator(OrgNode *node) : OrgIterator(node), stack_(std::stack<OrgNode *>()) {}           // constructor
    OrgPreOrderIterator(const OrgPreOrderIterator &other) : OrgIterator(other), stack_(other.stack_) {}  // copy constructor

    OrgPreOrderIterator &operator++();  // prefix increment operator
   private:
    std::stack<OrgNode *> stack_;
};


}  // namespace ariel