/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> data;
    int x=0;
    int y=0;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int dir=0;
    void cleanRoom(Robot& robot) {
        if(data[x][y]==1){
            return;
        }
        data[x][y]=1;
        robot.clean();
        for(int i=0; i<4; i++){
            if(robot.move()){
                x+=dx[dir];
                y+=dy[dir];
                cleanRoom(robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x-=dx[dir];
                y-=dy[dir];
            }
            robot.turnRight();
            dir=(dir+1)%4;
        }
    }
};