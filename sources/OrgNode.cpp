#include "OrgNode.hpp"

namespace ariel {

int OrgNode::level() const {
    if (this->get_supervisor() == nullptr) {
        return this->data_ == "" ? 0 : -1;
    }
    return this->get_supervisor()->level() + 1;
}

size_t OrgNode::size() const {
    return this->data_.length();
}

size_t OrgNode::degree() const {
    return this->subordinates_.size();
}

std::string OrgNode::get_data() const {
    return this->data_;
}

OrgNode& OrgNode::set_data(const std::string& data) {
    this->data_ = data;
    return *this;
}

std::vector<OrgNode*> OrgNode::get_subordinates() const {
    return this->subordinates_;
}

OrgNode& OrgNode::add_subordinate(OrgNode* node) {
    this->subordinates_.push_back(node);
    node->set_supervisor(this);
    return *this;
}

OrgNode& OrgNode::remove_subordinate(OrgNode* node) {
    this->subordinates_.erase(std::remove(this->subordinates_.begin(), this->subordinates_.end(), node), this->subordinates_.end());
    node->set_supervisor(nullptr);
    return *this;
}

OrgNode& OrgNode::set_supervisor(OrgNode* node) {
    this->supervisor_ = node;
    return *this;
}

OrgNode* OrgNode::get_supervisor() const {
    return this->supervisor_;
}

std::vector<OrgNode*> OrgNode::get_team() const {
    std::vector<OrgNode*> team;
    if (this->get_supervisor() == nullptr) {
        return team;
    }
    for (OrgNode* subordinate : this->get_supervisor()->get_subordinates()) {
        if (subordinate != this) {
            team.push_back(subordinate);
        }
    }
    return team;
}


std::ostream& operator<<(std::ostream& os, const OrgNode& org_node) {
    os << org_node.data_;
    return os;
}

}  // namespace ariel