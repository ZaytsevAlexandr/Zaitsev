    #include <algorithm>
    #include <numeric>
    #include <iostream>
    #include <vector>
    #include <iterator>

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& x){
        for (auto item : x){
            os << item << " ";
        }
        return os;
    }

    template <typename T>
    T sum_abs(T lhs, T lrs){
        return std::abs(lhs) + std::abs(lrs);
    }

    int main(){
        std::vector<int> vals {4, 6, -1, 7, 4, 3, 0, 999, 42};
        std::cout << vals << std::endl;
        std::sort(vals.begin(), vals.end(), [](auto lhs, auto rhs){return std::abs(lhs) < std::abs(rhs);});
        std::cout << vals << std::endl;
        std::cout << *std::max_element(vals.begin(), vals.end()) << std::endl;
        std::cout << std::accumulate(vals.begin(), vals.end(), 0) << std::endl;
        std::cout << std::accumulate(vals.begin(), vals.end(), 0, [](int lhs, int rhs){return std::abs(lhs) + std::abs(rhs);}) << std::endl;

        std::vector<int> squares;
        squares.resize(vals.size());

        auto sqr = [](auto x){return x * x;};

        std::transform(vals.begin(), vals.end(), squares.begin(), sqr);
        std:: cout << "Squares: " << squares << std::endl;

        std::transform(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, ", "), [](auto x){return x % 2;});
    }
