// 文件 src/increase_model.hpp

#ifndef __INCREASE_MODLE_HPP__
#define __INCREASE_MODLE_HPP__

#include <limits>
#include <vector>

// 这么模型要求 model 至少有两个数据
// 这个函数的功能是把 model 把 model的数据量扩张到 count 个
// 扩张方式: 当前值等于前两个的和.
template<class T, class Alloc>
bool UpdateIncreaseModel(std::vector<T, Alloc>& model, unsigned int count) {
    bool result = false;

    do {
        // model 中的原始数据至少有两个
        if (model.size() < 2) break;
        

        // 处理不需要扩张
        result = true;
        if (count <= model.size()) break;

        model.reserve(count);
        for (unsigned int i = model.size(); i < count; ++i) {
            // 判断溢出
            if (model[i - 1] < 0) {
                if (model[i -2] < std::numeric_limits<T>::min() - model[i - 1]) {
                    // 这会导致溢出
                    result = false;
                    break;
                }
            } else {
                if (model[i -2] > std::numeric_limits<T>::max() - model[i - 1]) {
                    // 这会导致溢出
                    result = false;
                    break;
                }
            }
            
            // 没有溢出, 添加数据
            model.push_back(model[i - 1] + model[i - 2]);
        }
    } while(false);

    return result;
}

#endif // __INCREASE_MODLE_HPP__