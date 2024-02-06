

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 05 февраля 2024 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

    #include <iostream>

    using namespace std;

    class Point2D
    {
    protected:
        double _x;
        double _y;

    public:
        // Конструктор точки с заданными координатами
        Point2D(double x, double y): _x(x), _y(y) {
        }

        // Получить координату X точки
        double x() const {
            return _x;
        }

        // Получить координату Y точки
        double y() const {
            return _y;
        }
    };

    #include <vector>

    template <typename T>
    T abs(T x) {
        return x > T(0) ? x : -x;
    }

    class Polygone
    {
    public:
        // Конструктор, создаёт полигон из набора точек.
        // Точки передаются в порядке обхода полигона по контуру.
        Polygone(const std::vector<Point2D>& points){
            vertices = points;
        }

        // Деструктор, если нужен

        // Возвращает площадь полигона
        double area() const{
            auto s = 0.;
            for (auto i = 1u; i + 1 < this->size(); i++){
                auto p_i = vertex(i);
                auto p_j = vertex(i + 1);
                auto p_0 = vertex(0);
                s += abs(
                         (p_i.x() - p_0.x()) * (p_j.y() - p_0.y()) -
                         (p_j.x() - p_0.x()) * (p_i.y() - p_0.y())
                         );
            }
            return s / 2.;
        }

        // Возвращает количество вершин полигона
        unsigned int size() const{
            return vertices.size();
        }

        // Возвращает N-ую вершину полигона
        // (вершины нумеруются в том же порядке, в котором были переданы)
        Point2D vertex(unsigned int N) const{
            return vertices[N];
        }

    private:
        vector<Point2D> vertices;
    };


    int main()
{
    vector<Point2D> points = {{-1.0, -1.0}, {-1.0, 1.0}, {1.0, 1.0}, {1.0, -1.0}};
    Polygone p(points);
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() << endl;
    }
    cout << "Area: " << p.area() << endl;
    return 0;
}
