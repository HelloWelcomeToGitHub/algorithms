

/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
bool solve_maze(int** maze, int n){
    if(maze[0][0] != 1){
        return false;
    }
    else if(maze[0][0] == maze[n][n]){
        return true;
    }
    else{
        return;
    }
}

/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the
 * given position by only moving downward and to the right, but not both at
 * once (i.e. not diagonally). A position in the maze is valid to move to
 * only if it contains a 1.
 */
bool solve_maze(int** maze, int n, int position[2]){
    int down[] = {position[0], position[1]+1};
    int right[] = {position[0]+1, position[1]};
    if(position[0] && position[1]){
        return true;
    }

    return 0;
}
