#ifndef FIBONACCI_H
#define FIBONACCI_H


class Fibonacci
{
public:
    Fibonacci();
    int func(int n);
    int num() const
    {
        return m_num;
    }
    void setNum(int num)
    {
        m_num = num;
    }
    int result() const
    {
        return m_result;
    }
    void setResult(int result)
    {
        m_result = result;
    }
private:
    int m_num;
    int m_result;
};

#endif // FIBONACCI_H
