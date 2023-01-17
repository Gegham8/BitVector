#ifndef BIT
#define BIT
#include <iostream>
class VecBit
{
public:
    VecBit();
    ~VecBit();
    VecBit(const size_t, bool);
    VecBit(const VecBit&);
    VecBit(VecBit&&);
    void set(const size_t, const bool);
    int get(const size_t);
    size_t size() const;
    friend  std::ostream& operator << (std::ostream &out, const VecBit&);
    std::size_t operator[] (const size_t);
private:
    bool resize(const size_t);
    int* m_arr;
    size_t m_size;
};
#endif // BIT