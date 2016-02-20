package puzzle8;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.MinPQ;

public class Solver {
	
	private boolean isSolvable;
	private Node ansNode;
	private int move = -1;
	
    public Solver(Board initial) {
    	// find a solution to the initial board (using the A* algorithm)
    	if (initial == null) {
    		throw new java.lang.NullPointerException("initial board found to be null!");
    	}
    	MinPQ<Node> minPQ = new MinPQ<Node>();
    	minPQ.insert(new Node(initial, null, 0, false));
    	minPQ.insert(new Node(initial.twin(), null, 0, true));
    	BFS(minPQ);
    }
    
    private void BFS(MinPQ<Node> minPQ) {
    	while (true) {
    		Node minNode = minPQ.delMin();
    		if (minNode.board.isGoal()) {
    			if (minNode.isTwin) {
    				this.isSolvable = false;
    				this.move = -1;
    			}
    			else {
    				this.isSolvable = true;
    				this.move = minNode.moveNum;
    				this.ansNode = minNode;
    			}
    			break;
    		}
    		for (Board neighbor : minNode.board.neighbors()) {
    			Node neighborNode = new Node(neighbor, minNode, 
    					minNode.moveNum + 1, minNode.isTwin);
    			if (minNode.preNode == null) {
    				minPQ.insert(neighborNode);
    			}
    			else if (!minNode.preNode.board.equals(neighborNode.board)) {
    				minPQ.insert(neighborNode);
    			}
    		}
    	}
    }
    
    public boolean isSolvable() {
    	// is the initial board solvable?
    	return this.isSolvable;
    }
    
    public int moves() {
    	// min number of moves to solve initial board; -1 if unsolvable
    	return this.move;
    }
    
    public Iterable<Board> solution() {
    	// sequence of boards in a shortest solution; null if unsolvable
    	if (!this.isSolvable) return null;
    	Node curNode = this.ansNode;
    	Stack<Board> solutionStack = new Stack<Board>();
    	solutionStack.push(curNode.board);
    	while (curNode.preNode != null) {
    		curNode = curNode.preNode;
    		solutionStack.push(curNode.board);
    	}
    	return solutionStack;
    }
    
    private static class Node implements Comparable {
    	private Board board;
    	private int moveNum = 0;
    	private Node preNode;
    	private final boolean isTwin;
    	
    	private Node(Board b, Node n, int move, boolean isTwin) {
    		this.isTwin = isTwin;
    		this.board = b;
    		this.preNode = n;
    		this.moveNum = move;
    	}
    	
    	@Override
    	public int compareTo(Object o) {
    		Node that = (Node)o;
    		if (this.board.equals(that.board)) return 0;
    		int manhattanDiff = (this.board.manhattan() + this.moveNum) - 
    				(that.board.manhattan() + that.moveNum);
    		return (manhattanDiff > 0) ? 1 : -1;
    	}
    }
    
    public static void main(String[] args) {
    	// solve a slider puzzle (given below)
    	// create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
    
}