// 文件 src/info.cpp

#include "info.h"

#include <iomanip>
#include <list>
#include <map>
#include <sstream>

namespace {
    const unsigned int max_value_ = 1000000000;
    const unsigned int witdh_value_ = 9;
}

class FibonacciItem {
public:
    // 原则上 该构造只运行 v 的值为 0 或 1
    FibonacciItem(unsigned int v);
    // 这个构造内部使用
    FibonacciItem() = default;
    ~FibonacciItem() = default;

    FibonacciItem(FibonacciItem&& other);
    FibonacciItem& operator=(FibonacciItem&& other);

    // 这个是计算的关键
    FibonacciItem operator+(const FibonacciItem& other) const;

    const char* GetText() const;

protected:
    void InitText();

private:
    // 因为整数的有效区间问题
    // 这里使用 一个数组(实际是双向链表) 来保存一个整数
    // 这个链表的表头代表的是低位
    // 这里使用9位数字为一组
    std::list<unsigned int> numbers_;

    unsigned int v_;

    std::string text_;
};

FibonacciItem::FibonacciItem(unsigned int v)
 : v_(v) {
    numbers_.push_back(v);
    InitText();
}

FibonacciItem::FibonacciItem(FibonacciItem&& other)
 : v_(other.v_), numbers_(std::move(other.numbers_)), text_(other.text_) {

}

FibonacciItem& FibonacciItem::operator=(FibonacciItem&& other) {
    v_ = other.v_ ;
    numbers_ = std::move(other.numbers_);
    text_ = other.text_;
    return *this;
}

FibonacciItem FibonacciItem::operator+(const FibonacciItem& other) const {
    FibonacciItem result;

    auto iter1 = numbers_.begin();
    auto iter2 = other.numbers_.begin();
    unsigned int carry = 0;
    unsigned int temp = 0;

    while (true)
    {
        if (iter1 == numbers_.end() && iter2 == other.numbers_.end()) {
            if (carry > 0) {
                result.numbers_.push_back(carry);
            }
            break;
        } else {
            unsigned int temp1 = 0;
            unsigned int temp2 = 0;
            if (iter1 != numbers_.end()) {
                temp1 = *iter1;
                ++iter1;
            }
            if (iter2 != other.numbers_.end()) {
                temp2 = *iter2;
                ++iter2;
            }
            temp = carry + temp1 + temp2;
            carry = temp / max_value_;
            result.numbers_.push_back(temp % max_value_);
        }
    }

    // 这个 if 条件是校验
    // 因为内部使用，这里实际上不会不满足
    if (v_ - 1 == other.v_) {
        result.v_ = v_ + 1;
        result.InitText();
    }
    
    return result;
}

const char* FibonacciItem::GetText() const {
    return text_.c_str();
}

// std::list的crbegin和crend两个方法要求C++14或以上
void FibonacciItem::InitText() {
    std::ostringstream os;
    auto iter = numbers_.crbegin();
    os << *iter;
    ++iter;
    unsigned int p1 = os.str().size();
    std::string t = os.str();
    
    if (iter != numbers_.crend()) {
        os << std::setfill('0');
        for (; iter != numbers_.crend(); ++iter)  {
            os << std::setw(witdh_value_) << *iter;
        }
    }
    
    text_ = os.str();
}

class FibonacciImpl: public FibonacciInterface {
public:
    FibonacciImpl();
    virtual ~FibonacciImpl() = default;

public:
    const char* GetValue(unsigned int index) override;

    void Cleanup() override {
        delete this;
    }

private:
    std::map<unsigned int, FibonacciItem> cache_;
    unsigned int mac_cache_index_;
};

FibonacciImpl::FibonacciImpl() : mac_cache_index_(1) {
    cache_.insert(cache_.end(), {0, FibonacciItem(0)});
    cache_.insert(cache_.end(), {1, FibonacciItem(1)});
}

const char* FibonacciImpl::GetValue(unsigned int index) {
    if (index > mac_cache_index_) {
        for (auto i = mac_cache_index_ + 1; i <= index; ++i) {
            cache_.insert(cache_.end(), {i, std::move(cache_[i - 1] + cache_[i - 2])});
        }
        mac_cache_index_ = index;
    }
    auto iter = cache_.find(index);
    if (iter == cache_.end()) {
        return nullptr;
    }
    if (iter->first != index) {
        // 这是预期外的错误, 实际上不需要的
        return nullptr;
    }
    return iter->second.GetText();
}

FibonacciInterface* CreateFibonacciInstance() {
    return new FibonacciImpl;
}