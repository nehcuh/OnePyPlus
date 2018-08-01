#include "EventEngine.h"
#include <iostream>

void EventEngine::put(EVENT event) {
    this->_core.push(event);
};

EVENT EventEngine::get(void) {
    this->_check_core_empty();
    EVENT result = this->_core.front();

    _core.pop();
    return result;
};

int EventEngine::size(void) const {
    return this->_core.size();
};

void EventEngine::_check_core_empty(void) const {
    if (this->_core.empty()) {
        throw std::logic_error("Can't get from empty");
    };
};

bool EventEngine::is_core_empty(void) const {
    return this->_core.empty() ? true : false;
};
