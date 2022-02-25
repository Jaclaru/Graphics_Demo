#include "AllClass.h"

void smart_ptr_test::addSum()
{
    int return_value = 0;
    for(auto it = this->arr.begin(); it != this->arr.end(); ++it)
    {
        return_value += *(*it).get();
        return_value += *(it->get());
    }
    cout << std::to_string(return_value)<<endl;
}

void smart_ptr_test::getData(const std::vector<int> & rhs)
{
    for(const auto & item : rhs)
    {
        std::unique_ptr<int> temp_ptr = std::make_unique<int>(item);
        this->arr.push_back(std::move(temp_ptr));
    }
}
