#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

#include "OrgIterator.hpp"
#include "OrgNode.hpp"

namespace ariel {
class OrgChart {
   private:
    OrgNode *root_;

   public:
    OrgChart() : root_(nullptr) {}
    ~OrgChart() {
        delete root_;
    }

    OrgNode *search(const OrgNode *node, const std::string &data);  // returns the node with the given data or nullptr if not found
                                                                    // (if multiple nodes with the same data exist, returns the first one)

    OrgNode *get_root() const;  // returns the root node

    OrgChart &add_root(const std::string &root_data);  // adds a root node with the given data
                                                       // (if there is already a root, it will be replaced)

    OrgChart &add_sub(const std::string &supervisor_data, const std::string &subordinate_data);  // adds a subordinate to the given supervisor
                                                                                                 // (if the supervisor does not exist, throws exception)
                                                                                                 // (if the supervisor exists twice or more choose the first one)

    OrgLevelOrderIterator begin_level_order() const;           // returns an iterator to the first node in the level order traversal
    OrgLevelOrderIterator end_level_order() const;             // returns an iterator to the end of the level order traversal
    OrgReverseLevelOrderIterator begin_reverse_order() const;  // returns an iterator to the first node in the reverse level order traversal
    OrgReverseLevelOrderIterator reverse_order() const;        // returns an iterator to the end of the reverse level order traversal
    OrgPreOrderIterator begin_preorder() const;                // returns an iterator to the first node in the pre order traversal
    OrgPreOrderIterator end_preorder() const;                  // returns an iterator to the end of the pre order traversal
    OrgLevelOrderIterator begin();                            // returns an iterator to the first node in the level order traversal
    OrgLevelOrderIterator end();                              // returns an iterator to the end of the level order traversal

    friend std::ostream &operator<<(std::ostream &os, const OrgChart &chart);  // prints the chart
};
}  // namespace ariel