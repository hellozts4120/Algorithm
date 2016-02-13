package CollinearPoints;

import java.util.*;

public class BruteCollinearPoints {
	
	private List<LineSegment> segment;
	
	// finds all line segments containing 4 points
	public BruteCollinearPoints(Point[] points) {  
		
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
		
		for (int i = 0; i < points.length - 3; i++) {
			for (int j = i + 1; j < points.length - 2; j++) {
				for (int k = j + 1; k < points.length - 1; k++) {
					for (int l = k + 1; l < points.length; l++) {
						if (points[i].slopeOrder().compare(points[j], points[k]) == 0
								&&
								points[i].slopeOrder().compare(points[k], points[l]) == 0) {
							segment.add(new LineSegment(points[i], points[l]));
						}
					}
				}
			}
		}
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