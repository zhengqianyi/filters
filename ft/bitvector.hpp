#ifndef FT_BITVECTOR_HPP
#define FT_BITVECTOR_HPP

#include <vector>

namespace ft
{

    class bitvector
    {
    private:
        /* data */
        std::vector<bool> bits_;
        size_t cells_;

    public:
        // init a vector have m cells with 0
        bitvector(size_t m);
        ~bitvector();

        // set bits[i] to 1
        void set(size_t i);

        //check bit[i] if 1 or 0
        bool check(size_t i) const;
    };

    bitvector :: bitvector(size_t m):cells_(m)
    {
        bits_ = std::vector<bool>(m,false);
    }

    void bitvector :: set(size_t i)
    {
        bits_[i%cells_] = true;
    }

    bool bitvector :: check(size_t i) const {
        return bits_[i%cells_];
    }



} // namespace ft

#endif