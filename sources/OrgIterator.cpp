#include "OrgIterator.hpp"

namespace ariel {

OrgIterator &OrgIterator::operator=(const OrgIterator &other) {
    this->node_ = other.node_;
    return *this;
}

OrgNode *OrgIterator::operator->() const {
    return this->node_;
}

OrgNode &OrgIterator::operator*() const {
    return *this->node_;
}

bool OrgIterator::operator==(const OrgIterator &other) const {
    return this->node_ == other.node_;
}

bool OrgIterator::operator!=(const OrgIterator &other) const {
    return !(*this == other);
}

OrgIterator &OrgIterator::operator++(int) {
    OrgIterator &iter = *this;
    ++(*this);
    return iter;
}

OrgLevelOrderIterator &OrgLevelOrderIterator::operator++() {
    this->node_ = nullptr;
    return *this;
}

OrgReverseLevelOrderIterator &OrgReverseLevelOrderIterator::operator++() {
    this->node_ = nullptr;
    return *this;
}


OrgPreOrderIterator &OrgPreOrderIterator::operator++() {
    this->node_ = nullptr;
    return *this;
}


}  // namespace ariel