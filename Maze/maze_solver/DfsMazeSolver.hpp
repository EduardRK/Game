#include "MazeSolver.hpp"

class DfsMazeSolver : public MazeSolver
{
public:
    DfsMazeSolver();
    ~DfsMazeSolver();

    auto solveMaze(Maze const &maze) -> std::vector<Point>;
}