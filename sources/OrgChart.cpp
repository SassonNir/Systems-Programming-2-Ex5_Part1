#include "OrgChart.hpp"

namespace ariel {

OrgNode *OrgChart::search(const OrgNode *node, const std::string &data) {
    if (data == "") {
        return nullptr;
    }
    if (node == nullptr) {
        return nullptr;
    }
    if (node->get_data() == data) {
        return const_cast<OrgNode *>(node);
    }
    if (node->degree() == 0) {
        return nullptr;
    }
    for (OrgNode *child : node->get_subordinates()) {
        OrgNode *result = search(child, data);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

OrgNode *OrgChart::get_root() const {
    return this->root_;
}

OrgChart &OrgChart::add_root(const std::string &data) {
    if (data == "") {
        throw std::invalid_argument("data cannot be empty");
    }
    if (this->root_ != nullptr) {
        delete this->root_;
    }
    this->root_ = new OrgNode(data);
    return *this;
}

OrgChart &OrgChart::add_sub(const std::string &supervisor_data, const std::string &subordinate_data) {
    if (supervisor_data == "") {
        throw std::invalid_argument("supervisor_data cannot be empty");
    }
    if (subordinate_data == "") {
        throw std::invalid_argument("subordinate_data cannot be empty");
    }
    OrgNode *supervisor = this->search(this->root_, supervisor_data);
    if (supervisor == nullptr) {
        throw std::invalid_argument("No such supervisor");
    }
    OrgNode *subordinate = new OrgNode(subordinate_data);
    supervisor->add_subordinate(subordinate);
    return *this;
}

// returns an iterator to the first node in the level order traversal
OrgLevelOrderIterator OrgChart::begin_level_order() const {
    return OrgLevelOrderIterator();
}
// returns an iterator to the end of the level order traversal
OrgLevelOrderIterator OrgChart::end_level_order() const {
    return OrgLevelOrderIterator();
}
// returns an iterator to the first node in the reverse level order traversal
OrgReverseLevelOrderIterator OrgChart::begin_reverse_order() const {
    return OrgReverseLevelOrderIterator();
}
// returns an iterator to the end of the reverse level order traversal
OrgReverseLevelOrderIterator OrgChart::reverse_order() const {
    return OrgReverseLevelOrderIterator();
}
// returns an iterator to the first node in the pre order traversal
OrgPreOrderIterator OrgChart::begin_preorder() const {
    return OrgPreOrderIterator();
}
// returns an iterator to the end of the pre order traversal
OrgPreOrderIterator OrgChart::end_preorder() const {
    return OrgPreOrderIterator();
}
// returns an iterator to the first node in the level order traversal
OrgLevelOrderIterator OrgChart::begin() {
    return OrgLevelOrderIterator();
}
// returns an iterator to the end of the level order traversal
OrgLevelOrderIterator OrgChart::end() {
    return OrgLevelOrderIterator();
}

/*
print the chart in the following format using ascii art:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
*/


std::ostream& print_node(std::ostream& os, const OrgNode& node, bool last, std::string prefix) {
    std::string current = prefix + (last ? "└── " : "├── ") + node.get_data();
    std::string next_prefix = prefix + (last ? "    " : "│   ");
    os << current << std::endl;
    for (size_t i = 0; i < node.degree(); i++) {
        print_node(os, *node.get_subordinates()[i], i == node.degree() - 1, next_prefix);
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const OrgChart &chart) {
    return print_node(os, *chart.get_root(), true, "");
}

}  // namespace ariel