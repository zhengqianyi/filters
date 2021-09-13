#ifndef FT_BLOOM_FILTER_HPP
#define FT_BLOOM_FILTER_HPP

#include <ft/filter.hpp>
#include <ft/bitvector.hpp>
#include <ft/hasher.hpp>

#include <string>
#include <random>

namespace ft
{

    class bloom_filter : public filter
    {
    private:
        /// the length of bits_
        size_t cells_;

        /// the bits for hash result
        bitvector bits_;

        /// the seeds for hashf
        std::vector<size_t> seeds_;

        /// whitch hash to use
        HashType hash_name_;
        ///

    public:
        /// Computes the number of cells based on a false-positive rate and capacity.
        static size_t m(double fp, size_t capcity);

        /// Computes the number of hash function
        static size_t k(size_t cells, size_t capacity);

        /// have tow way to init a bloom_filter

        /// by cells and k
        bloom_filter(size_t cells, size_t k_hash, HashType hashname);

        /// by fp and capcity
        bloom_filter(double fp, size_t capacity, HashType hashname);

        ~bloom_filter();

        using filter::add;
        using filter::lookup;

        /// Adds an element to the Bloom filter.
        virtual void add(object const &o) override;

        /// Retrieves the count of an element.
        virtual bool lookup(object const &o) const override;
    };

    size_t bloom_filter::m(double fp, size_t capacity)
    {
        auto ln2 = std::log(2);
        return std::ceil(-(capacity * std::log(fp) / ln2 / ln2));
    }

    size_t bloom_filter::k(size_t cells, size_t capacity)
    {
        auto frac = static_cast<double>(cells) / static_cast<double>(capacity);
        return std::ceil(frac * std::log(2));
    }

    bloom_filter ::bloom_filter(size_t cells, size_t k_hash, HashType hashname) : cells_(cells), bits_(cells), hash_name_(hashname)
    {
        //initial the seeds
        auto t = k_hash;
        while (t--)
        {
            seeds_.push_back(random());
        }
    }

    bloom_filter ::bloom_filter(double fp, size_t capacity, HashType hashname) : cells_(m(fp, capacity)), bits_(m(fp, capacity)), hash_name_(hashname)
    {
        auto t = k(cells_, capacity);
        while (t--)
        {
            seeds_.push_back(random());
        }
    }

    void bloom_filter ::add(object const &o)
    {
        for (const auto s : seeds_)
            bits_.set(hashf(hash_name_, o, s));
    }


    bool bloom_filter ::lookup(object const &o) const
    {
        for (const auto s : seeds_)
            if (bits_.check(hashf(hash_name_, o, s)) == true)
                return true;
        return false;
    }

} // namespace ft

#endif