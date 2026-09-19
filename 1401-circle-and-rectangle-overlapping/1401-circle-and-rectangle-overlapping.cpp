class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        
        int closestX= max(x1,min(xc, x2));
        int closestY= max(y1,min(yc, y2));

        int dx=xc-closestX;
        int dy=yc-closestY;

        return dx*dx+dy*dy<=r*r;
    }
};