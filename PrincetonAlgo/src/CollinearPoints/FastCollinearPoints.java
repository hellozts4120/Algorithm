package CollinearPoints;

import java.util.*;

public class FastCollinearPoints {
	
	private List<LineSegment> segment;
	private List<Point> ablePoints;
	
	// finds all line segments containing 4 or more points
	public FastCollinearPoints(Point[] points) {
	
		if (points == null) {
			throw new java.lang.NullPointerException("input is null!");
		}
		
		Arrays.sort(points);
		for (int i = 0; i < points.length; i++) {
			if (points[i] == null) {
				throw new java.lang.NullPointerException("input is null!");
			}
			if (i > 0 && (points[i].compareTo(points[i-1])) == 0) {
				throw new java.lang.IllegalArgumentException("repeated points found!");
			}
		}
		
		segment = new ArrayList<LineSegment>();
		ablePoints = new ArrayList<Point>();
		
		for (int cur = 0; cur < points.length - 3; cur++) {
			qsort(points, points[cur], cur + 1, points.length - 1);
			int i = cur + 1;
			while (i < points.length - 2) {
				if(points[cur].slopeOrder().compare(points[i], points[i + 1]) == 0) {
					int j = i + 2;
					for (; j < points.length; j++) {
						if(points[cur].slopeOrder().compare(points[i], points[j]) != 0) {
							break;
						}
					}
					
					if (j - i >= 3) {
						Point temp = points[i];
						for (int k = i + 1; k < j; k++) {
							if (temp.compareTo(points[k]) < 0) {
								temp = points[k];
							}
							if (!ablePoints.contains(temp)) {
								ablePoints.add(temp);
								segment.add(new LineSegment(points[cur], temp));
							}
						}
					}
					
					i = j;
				}
				
				else i++;
			}
			
			Arrays.sort(points);
		}
	}
	
	//Partition function of quicksort.
	private static int partition(Point[] a, Point origin, int lo, int hi) {
		
		int i = lo, j = hi+1;
		while (true) {
			while (origin.slopeTo(a[++i]) < origin.slopeTo(a[lo])) {
				if (i == hi) break;
			}
			while (origin.slopeTo(a[lo]) < origin.slopeTo(a[--j])) {
				if (j == lo) break;
			}
			if (i >= j) break;
			exch(a, i, j);
		}
		exch(a, lo, j);
		return j;
	}
	
	private static void exch(Point[] a, int i, int j) {
		
		Point temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	//quicksort implemention
	private static void qsort(Point[] a, Point origin, int lo, int hi) {
	
		if (hi <= lo) {
			return;
		}
		int place = partition(a, origin, lo, hi);
		qsort(a, origin, lo, place - 1);
		qsort(a, origin, place + 1, hi);
	}
	
	// the number of line segments
	public int numberOfSegments() {
		
		return segment.size();
	}
	
	// the line segments
	public LineSegment[] segments() {
		
		LineSegment[] segments = new LineSegment[segment.size()];
		for (int i = 0; i < segment.size(); i++) {
			segments[i] = segment.get(i);
		}
		return segments;
	}
}