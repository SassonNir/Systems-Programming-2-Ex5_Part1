#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace ariel {
class OrgNode {
   private:
    std::string data_;
    std::vector<OrgNode*> subordinates_;
    OrgNode* supervisor_;

   public:
    OrgNode(const std::string& data) : data_(data), supervisor_(nullptr) {}  // constructor
    ~OrgNode() {                                                             // destructor
        for (OrgNode* subordinate : this->subordinates_) {
            delete subordinate;
        }
    }

    int level() const;                            // returns the level of the node in the tree
    size_t size() const;                             // returns the length of the data
    size_t degree() const;                           // returns the number of subordinates
    std::string get_data() const;                    // returns the data
    OrgNode& set_data(const std::string& data);      // sets the data
    std::vector<OrgNode*> get_subordinates() const;  // returns the subordinates
    OrgNode& add_subordinate(OrgNode* node);         // adds a subordinate
    OrgNode& remove_subordinate(OrgNode* node);      // removes a subordinate
    OrgNode& set_supervisor(OrgNode* node);          // sets the supervisor
    OrgNode* get_supervisor() const;                 // returns the supervisor
    std::vector<OrgNode*> get_team() const;          // returns the siblings of the node

    friend std::ostream& operator<<(std::ostream& os, const OrgNode& node);  // prints the node
};
}  // namespace ariel