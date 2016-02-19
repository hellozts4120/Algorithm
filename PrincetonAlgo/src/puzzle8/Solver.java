package puzzle8;

public class Solver {
	
	private boolean isSolvable;
	
    public Solver(Board initial) {
    	// find a solution to the initial board (using the A* algorithm)
    }
    
    public boolean isSolvable() {
    	// is the initial board solvable?
    	return this.isSolvable;
    }
    
    public int moves() {
    	// min number of moves to solve initial board; -1 if unsolvable
    }
    
    public Iterable<Board> solution() {
    	// sequence of boards in a shortest solution; null if unsolvable
    }
    
    public static void main(String[] args) {
    	// solve a slider puzzle (given below)
    }
    
}