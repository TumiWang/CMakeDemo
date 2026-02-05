// 文件 src/fibonacci.cpp

#include "fibonacci.h"

#include "increase_model.hpp"

#include <mutex>

class FibonacciImpl: public FibonacciInterface {
public:
    FibonacciImpl(FibonacciType type);
    virtual ~FibonacciImpl() = default;

public:
    unsigned int GetValue(unsigned int index) override;

    void Cleanup() override {
        delete this;
    }

private:
    std::mutex mutex_cache_;
    std::vector<unsigned int> cache_;
};

FibonacciImpl::FibonacciImpl(FibonacciInterface::FibonacciType type){
    switch (type)
    {
    case FibonacciInterface::FibonacciType::Standard:
        cache_.insert(cache_.end(), {0, 1});
        break;
    case FibonacciInterface::FibonacciType::Extend:
        cache_.insert(cache_.end(), {1, 1});
        break;
    default:
        break;
    }
}

unsigned int FibonacciImpl::GetValue(unsigned int index) {
    unsigned int result = 0;

    std::unique_lock<decltype(mutex_cache_)> lock(mutex_cache_);

    if (UpdateIncreaseModel(cache_, index + 1)) {
        result = cache_[index];
    }

    return result;
}

FibonacciInterface* CreateFibonacciInstance(FibonacciInterface::FibonacciType type) {
    return new FibonacciImpl(type);
}