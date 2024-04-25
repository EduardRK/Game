class Point
{
private:
    const int x;
    const int y;

public:
    Point(int x, int y);
    ~Point();

    auto x() -> int const;
    auto y() -> int const;
}