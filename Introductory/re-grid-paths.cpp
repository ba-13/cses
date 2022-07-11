#include "../_header.hpp"

std::invalid_argument OtherVal("Enter ?, U, R, D, L only");
int result = 0;
const int SZ = 7;
std::unordered_map<int, char> mapping = {{1, 'U'}, {2, 'R'}, {3, 'D'}, {4, 'L'}};

bool isNotValidBoundary(int r, int c, std::vector<vi> &grid, vi &path, int idx)
{
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        return true;
    if (grid[r][c] == 1)
        return true;
    // now if grid[r][c] == 0, check the previous location and the forward location
    if (idx > 0)
    {
        int lastMove = path[idx - 1];
        switch (lastMove)
        {
        case 1:
            // we moved up to the current
            if (r == 0 || grid[r - 1][c] == 1)
            {
                // now check if allowed in right and left
                if (c > 0 and grid[r][c - 1] == 0 and c < SZ - 1 and grid[r][c + 1] == 0)
                    return true;
            }
            break;
        case 2:
            if (c == SZ - 1 || grid[r][c + 1] == 1)
            {
                if (r > 0 and grid[r - 1][c] == 0 and r < SZ - 1 and grid[r + 1][c] == 0)
                    return true;
            }
            break;
        case 3:
            if (r == SZ - 1 || grid[r + 1][c] == 1)
            {
                if (c > 0 and grid[r][c - 1] == 0 and c < SZ - 1 and grid[r][c + 1] == 0)
                    return true;
            }
        case 4:
            if (c == 0 || grid[r][c - 1])
            {
                if (r > 0 and grid[r - 1][c] == 0 and r < SZ - 1 and grid[r + 1][c] == 0)
                    return true;
            }

        default:
            break;
        }
    }
    return false;
}

int traverse(vi &path, std::vector<vi> &grid, int idx, int i, int j)
{
    if (isNotValidBoundary(i, j, grid, path, idx))
    {
        return -1;
    }
    if (idx == path.size())
    {
        if (i == SZ - 1 and j == 0)
        {
            result++;
            std::cout << result << " ";
            ff(i, 0, path.size()) std::cout << mapping[path[i]];
            std::cout << "\n";
            std::cerr << "Found " << result << "\n";
            return 1;
        }
        return -1;
    }
    else
    {
        if (i == SZ - 1 and j == 0)
            return -1;
    }
    grid[i][j] = 1; // visit current

    if (path[idx] != 0) // already decided path
    {
        if (path[idx] == 1)
            // go up
            traverse(path, grid, idx + 1, i - 1, j);
        else if (path[idx] == 2)
            // go right
            traverse(path, grid, idx + 1, i, j + 1);
        else if (path[idx] == 3)
            // go down
            traverse(path, grid, idx + 1, i + 1, j);
        else if (path[idx] == 4)
            // go left
            traverse(path, grid, idx + 1, i, j - 1);
    }
    else
    {
        // go in all directions
        path[idx] = 1;
        traverse(path, grid, idx + 1, i - 1, j);
        path[idx] = 2;
        traverse(path, grid, idx + 1, i, j + 1);
        path[idx] = 3;
        traverse(path, grid, idx + 1, i + 1, j);
        path[idx] = 4;
        traverse(path, grid, idx + 1, i, j - 1);
        path[idx] = 0;
    }
    grid[i][j] = -1; // unvisit this node
    return -1;
}

int main()
{
    vi path(SZ * SZ - 1, -1);
    std::vector<vi> grid(SZ, vi(SZ, -1));
    std::string s = "??????R??????U??????????????????????????LD????D?";
    ff(i, 0, path.size())
    {
        char tmp = s[i];
        // char tmp = getchar();
        switch (tmp)
        {
        /*
            1
          4 0 2
            3
        */
        case '?':
            path[i] = 0;
            break;
        case 'U':
            path[i] = 1;
            break;
        case 'R':
            path[i] = 2;
            break;
        case 'D':
            path[i] = 3;
            break;
        case 'L':
            path[i] = 4;
            break;
        default:
            throw OtherVal;
        }
    }
    int i = 0, j = 0;
    traverse(path, grid, 0, i, j);
    std::cout << result;
    return 0;
}